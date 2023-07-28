#include "main.h"

/**
 * _prerror - Print an error message for an illegal number.
 * @argv: The program arguments.
 * @c: The line number in the shell program where the error occurred.
 * @cmd: The command and its arguments causing the error.
*/

void print_error(char **argv, int c, char **cmd)
{
	char *er = _itoa(c);

	PRINTER(argv[0]);
	PRINTER(": ");
	PRINTER(er);
	PRINTER(": ");
	PRINTER(cmd[0]);
	PRINTER(": Illegal number: ");
	PRINTER(cmd[1]);
	PRINTER("\n");
	free(er);
}
