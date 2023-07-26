#include "shell.h"

/**
 * _cd - Changes the current working directory to the specified path.
 * If no argument is provided, it prints an error message.
 *
 * @args: An array of strings containing the command and its arguments.
*/

void _cd(char **args)
{
    // Check if an argument is provided for the directory path.
    if (args[1] == NULL)
    {
        fprintf(stderr, "err: cd: not found\n");
    }
    else
    {
        // Attempt to change the current working directory.
        if (chdir(args[1]) != 0)
        {
            perror("err: No such file or directory"); // Print an error message if chdir() fails.
        }
    }
}
