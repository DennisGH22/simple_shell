#include "main.h"

/**
 * execute_command - Execute a command using fork and execve.
 * @args: An argument to be passed to the command.
 *
 * Return: The exit status.
*/

int execute_command(char **args)
{
	pid_t pid;
	int status;

	pid = fork();

	if (pid < 0)
	{
		perror("Fork failed");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		/* Child process */
		if (execve(args[0], args, environ) == -1)
		{
			perror("Error");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		/* Parent process */
		if (waitpid(pid, &status, 0) == -1)
		{
			perror("Waitpid failed");
			exit(EXIT_FAILURE);
		}

		if (WIFEXITED(status))
			status = WEXITSTATUS(status);
	}

	return (status);
}
