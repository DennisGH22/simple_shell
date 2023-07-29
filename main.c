#include "main.h"

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
	int arg_len, exit_status = 0;
	char arg[buff_size];

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

		if (_strcmp("exit ", buff, 5) == 0)
		{
			arg_len = buff_size - 5;
			_strncpy(arg, buff + 5, arg_len);
			arg[arg_len] = '\0';

			exit_status = _atoi(arg);

			free(buff);
			break;
		}

		if (_strcmp("env", buff) == 0)
		{
			_env();
			continue;
		}

		if (_getline(buff))
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
