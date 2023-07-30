#include "main.h"

/**
 * printError - Print an error message to stderr.
 * @command: The name of the command that caused the error.
 * @count: The count of the command.
 * @argument: The argument that caused the error.
*/

void printError(char **command, int count, char **argument)
{
    char *errorMessage = "not found\n";
    size_t commandLen = _strlen(*command);
    size_t argumentLen = _strlen(*argument);

    write(2, *command, commandLen);
    write(2, ": ", 2);
    dprintf(2, "%d", count);
    write(2, ": ", 2);
    write(2, *argument, argumentLen);
    write(2, ": ", 2);
    write(2, errorMessage, _strlen(errorMessage));
}

/**
 * intError - Write an integer to the standard error (stderr) stream.
 * @num: The integer to write.
 *
 * Return: The number of characters printed.
*/

int intError(int num)
{
    int i, printChars = 0;
    unsigned int c1;
    char buffer[20];

    if (num < 0)
    {
        num = -num;
        write(2, "-", 1);
        printChars++;
    }

    c1 = num;
    i = sizeof(buffer) - 1;
    buffer[i] = '\0';

    do
    {
        buffer[--i] = '0' + (c1 % 10);
        c1 /= 10;
    } while (c1);

    printChars += write(2, buffer + i, _strlen(buffer + i));
    return (printChars);
}
