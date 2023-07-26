#include "shell.h"

void execute_command(char **args, char **envp)
{
	pid_t pid = fork();

	if (pid < 0)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		if (execve(args[0], args, envp) == -1)
		{
			perror("execve");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(NULL);
	}
}

void run_shell()
{
	char command[MAX_COMMAND_LENGTH];
	char *args[MAX_ARGS];
	char *token;
	char *envp[] = {NULL};

	struct termios term_attr;
	tcgetattr(STDIN_FILENO, &term_attr);

	while (1)
	{
		printf("Shell > ");
		fflush(stdout);

		// Reset terminal attributes
		tcsetattr(STDIN_FILENO, TCSANOW, &term_attr);

		if (fgets(command, MAX_COMMAND_LENGTH, stdin) == NULL)
		{
			// End-of-file condition (Ctrl+D)
			printf("\n");
			break;
		}

		command[strcspn(command, "\n")] = '\0';

		if (strcmp(command, "exit") == 0)
		{
			break;
		}
		else if (strcmp(command, "") == 0)
		{
			continue;
		}
		else
		{
			int arg_count = 0;
			token = strtok(command, " ");
			while (token != NULL && arg_count < MAX_ARGS - 1)
			{
				args[arg_count] = token;
				arg_count++;
				token = strtok(NULL, " ");
			}
			args[arg_count] = NULL;

			// Handle special characters
			int i = 0;
			while (args[i] != NULL)
			{
				// Replace double quotes
				if (args[i][0] == '"' && args[i][strlen(args[i]) - 1] == '"')
				{
					memmove(args[i], args[i] + 1, strlen(args[i]) - 1);
					args[i][strlen(args[i]) - 1] = '\0';
				}
				// Replace single quotes
				else if (args[i][0] == '\'' && args[i][strlen(args[i]) - 1] == '\'')
				{
					memmove(args[i], args[i] + 1, strlen(args[i]) - 1);
					args[i][strlen(args[i]) - 1] = '\0';
				}
				// Handle backticks (command substitution)
				else if (args[i][0] == '`' && args[i][strlen(args[i]) - 1] == '`')
				{
					memmove(args[i], args[i] + 1, strlen(args[i]) - 1);
					args[i][strlen(args[i]) - 1] = '\0';

					FILE *pipe = popen(args[i], "r");
					if (pipe != NULL) {
						char output[MAX_COMMAND_LENGTH];
						if (fgets(output, sizeof(output), pipe) != NULL)
						{
							output[strcspn(output, "\n")] = '\0';
							strcpy(args[i], output);
						}
						pclose(pipe);
					}
				}
				else
				{
					// Handle escaping special characters
					char *escaped = malloc(strlen(args[i]) * 2 + 1);
					int j = 0;
					for (int k = 0; k < strlen(args[i]); k++)
					{
						if (args[i][k] == '\\' || args[i][k] == '*' || args[i][k] == '&' || args[i][k] == '#')
						{
							escaped[j++] = '\\';
						}
						escaped[j++] = args[i][k];
					}
					escaped[j] = '\0';
					strcpy(args[i], escaped);
					free(escaped);
				}

				i++;
			}

			if (strcmp(args[0], "cd") == 0)
			{
				// Change directory (built-in command)
				if (arg_count == 1)
				{
					char *home = getenv("HOME");
					if (home != NULL)
					{
						chdir(home);
					} else
					{
						printf("Home directory not found.\n");
					}
				}
				else if (arg_count == 2)
				{
					if (chdir(args[1]) == -1)
					{
						perror("chdir");
					}
				}
				else
				{
					printf("Invalid number of arguments for 'cd' command.\n");
				}
				}
			else if (strcmp(args[0], "cursor") == 0)
			{
			// Cursor movement (built-in command)
			if (arg_count == 2)
			{
				int move = atoi(args[1]);
				if (move < 0)
				{
					printf("Invalid cursor movement value.\n");
				}
				else
				{
					printf("\033[%dC", move);
				}
			}
			else
			{
				printf("Invalid number of arguments for 'cursor' command.\n");
			}
			}
			else
			{
				execute_command(args, envp);
			}
		}
	}
}

int main() {
    run_shell();
    return (0);
}
