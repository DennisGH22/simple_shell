#include "shell.h"

/**
 * _getline - Read a line of input from stdin.
 *
 * Return: The input line as a string.
*/

char *_getline()
{
    char *line = NULL;
    size_t buflen = 0;
    errno = 0;

    // Use getline() to read a line of input from stdin.
    ssize_t strlen = getline(&line, &buflen, stdin);

    if (strlen < 0)
    {
        if (errno)
        {
            perror("err"); // Print an error message if getline() encounters an error.
        }
        exit(1); // Terminate the program with an error status.
    }

    return (line); // Return the input line as a string.
}
