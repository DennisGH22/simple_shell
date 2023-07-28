#include "main.h"

/**
 * exit_shell - Handle the exit command in the shell.
 * @cmd: The command and its arguments passed to the shell.
 * @input: The input provided to the shell.
 * @argv: The program arguments.
 * @c: The line number in the shell program where the command was executed.
*/

void exit_shell(char **cmd, char *input, char **argv, int c)
{
	int i = 0;

	if (cmd[1] == NULL)
	{
		free(input);
		free(cmd);
		exit(EXIT_SUCCESS);
	}

	if (cmd[1][i] == '-')
	{
		i++;
	}

	while (cmd[1][i])
	{
		if (!_isdigit(cmd[1][i]))
		{
			print_error(argv, c, cmd);
			return;
		}
		i++;
	}

	int status = _atoi(cmd[1]);
	free(input);
	free(cmd);
	exit(status);
}
