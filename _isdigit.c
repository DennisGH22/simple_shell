#include "main.h"

/**
 * _isdigit - Checks for a digit.
 * @c: The parameter checked.
 *
 * Return: 1 if c is a digit and 0 otherwise.
*/

int _isdigit(int c)
{

	if (isdigit(c))
	{
		return (1);
	}

	return (0);

}
