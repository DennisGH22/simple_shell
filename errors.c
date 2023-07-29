#include "main.h"

/**
 * print_rerror - Print an error message.
 * @argv: The argument vector.
 * @c: The error code.
 * @cmd: The command array.
*/

void print_error(char **cmd)
{
	printf("Error: Invalid argument provided.\n");

    printf("Command: %s\n", cmd[0]);
    printf("Arguments:");

    for (int i = 1; cmd[i] != NULL; i++)
        printf(" %s", cmd[i]);

    printf("\n");
}
