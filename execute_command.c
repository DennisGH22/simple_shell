#include "shell.h"

/**
 * execute_command - Execute a command using fork and execve
 * @command: The command to execute
 *
 * Return: 0 on success, 1 on failure
*/

int execute_command(char *command)
{
	pid_t pid;
	int status;

	pid = fork();

	if (pid < 0)
	{
		perror("Fork failed");
		return (1);
	}
	else if (pid == 0)
	{
		/* Child process */
		char *args[] = {command, NULL};
		char *env[] = {NULL}; /* Empty environment variables */
		if (execve(command, args, env) == -1)
		{
			perror("Command execution failed");
			_exit(EXIT_FAILURE);
		}
		_exit(EXIT_SUCCESS);
	}
	else
	{
		/* Parent process */
		do {
			if (waitpid(pid, &status, WUNTRACED) == -1)
			{
				perror("Waitpid failed");
				return (1);
			}
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}

	return (0);
}
