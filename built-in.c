#include "shell.h"

/**
 * builtins - Returns the number of built-in commands
 * available in the `builtins` array.
 *
 * Return: The number of built-in commands as an integer.
*/

int _builtins()
{
    return sizeof(builtins) / sizeof(struct builtin);
}