#include "shell.h"

/**
 * main - Simple shell main function.
 *
 * Return: Exit status.
*/

int main(void)
{
	char *buff = NULL, **args;
	size_t read_size = 0;
	ssize_t buff_size = 0;
	int exit_status = 0;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2);

		buff_size = getline(&buff, &read_size, stdin);
		if (buff_size == -1 || _strcmp("exit\n", buff) == 0)
		{
			free(buff);
			break;
		}
		buff[buff_size - 1] = '\0';

		if (_strcmp("env", buff) == 0)
		{
			_env();
			continue;
		}

		if (empty_line(buff))
		{
			exit_status = 0;
			continue;
		}

		args = split_string(buff, " ");
		args[0] = env_path(args[0]);

		if (args[0] != NULL)
			exit_status = execute_command(args);
		else
			perror("Error");

		free(args);
	}

	return (exit_status);
}
