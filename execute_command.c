#include "main.h"

/**
 * execute_command - Execute a command using fork and execve.
 * @args: An argument to be passed to the command.
 *
 * Return: The exit status.
*/

int execute_command(char **args)
{
	int pid, status;

	pid = fork();

	if (pid == 0)
	{
		// Child process
		if (execve(args[0], args, environ) == -1)
		{
			perror("Error");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		// Parent process
		wait(&status);

		if (WIFEXITED(status))
			status = WEXITSTATUS(status);
	}

	return (status);
}
