#include "main.h"

void executeCommand(char** args)
{
    pid_t pid = fork();

    if (pid < 0)
	{
        // Error occurred
        perror("fork");
        exit(EXIT_FAILURE);
    }
	else if (pid == 0)
	{
        // Child process
        if (execvp(args[0], args) == -1)
		{
            perror("execvp");
            exit(EXIT_FAILURE);
        }
    }
	else
	{
        // Parent process
        wait(NULL);
    }
}

int main()
{
    char command[MAX_COMMAND_LENGTH];
    char* args[MAX_ARGS];
    char* token;

    while (1)
	{
        printf("Shell > ");
        fgets(command, MAX_COMMAND_LENGTH, stdin);
        command[strcspn(command, "\n")] = '\0';

        int argCount = 0;
        token = strtok(command, " ");
        while (token != NULL && argCount < MAX_ARGS - 1)
		{
            args[argCount] = token;
            argCount++;
            token = strtok(NULL, " ");
        }
        args[argCount] = NULL;

        if (strcmp(args[0], "exit") == 0)
		{
            break;
        }
		else
		{
            executeCommand(args);
        }
    }

    return (0);
}
