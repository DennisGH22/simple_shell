#include "shell.h"

/**
 * main - Simple shell main function
 *
 * Return: Always 0
*/

int main(void)
{
	char command[MAX_COMMAND_LENGTH];

	while (1)
	{
		write(STDOUT_FILENO, "$ ", strlen("$ "));

		if (fgets(command, sizeof(command), stdin) == NULL)
		{
			/* Handle end of file (Ctrl+D) */
			write(STDOUT_FILENO, "\n", 1);
			break;
		}

		/* Remove trailing newline character */
		command[strcspn(command, "\n")] = '\0';

		if (strlen(command) == 0)
		{
			/* Empty command, continue to the next iteration */
			continue;
		}

		if (execute_command(command) != 0)
		{
			write(STDERR_FILENO, "Error executing command: ", strlen("Error executing command: "));
			write(STDERR_FILENO, command, strlen(command));
			write(STDERR_FILENO, "\n", 1);
		}
	}

	return (0);
}
