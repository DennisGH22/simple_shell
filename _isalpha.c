#include "main.h"

/**
 * _isalpha - Checks for alphabetic character.
 * @c: Character checked.
 *
 * Return: 1 if c is lowercase or uppercase and 0 otherwise.
*/

int _isalpha(int c)
{
if (isalpha(c))
{
return (1);
}

return (0);
}
