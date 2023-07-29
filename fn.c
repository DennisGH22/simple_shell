#include "main.h"

/**
 * _atoi - Converts a string to an integer.
 * @s: The string to convert.
 *
 * Return: 0 if no numbers.
*/

int _atoi(char *s)
{
	int i, d = 0, n = 0, len = 0, f = 0, digit = 0;

	while (s[len] != '\0')
	{
		len++;
	}

	for (i = 0; i < len && f == 0; i++)
	{
		if (s[i] == '-')
		{
			++d;
		}

		if (s[i] >= '0' && s[i] <= '9')
		{
			digit = s[i] - '0';
			if (d % 2)
			{
				digit = -digit;
			}
			n = n * 10 + digit;
			f = 1;
			if (s[i + 1] < '0' || s[i + 1] > '9')
			{
				break;
			}
			f = 0;
		}
	}

	if (f == 0)
	{
		return (0);
	}

	return (n);
}

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

/**
 * is_all_digits - Checks if a string contains only digits.
 * @str: The input string to check.
 *
 * Return: 1 if all characters are digits, 0 otherwise.
*/

int is_all_digits(const char *str) {
    while (*str) {
        if (!isdigit(*str)) {
            return (0);
        }
        str++;
    }
    return (1);
}

/**
 * _itoa - Convert an unsigned integer to a string.
 * @n: The unsigned integer to convert.
 *
 * Return: Pointer to the newly allocated string representation of @n,
 *         or NULL if memory allocation fails.
*/

char *_itoa(unsigned int n)
{
	int len = 1;
	unsigned int temp = n;
	char *s = malloc(len + 1);

	while (temp /= 10)
		len++;

	if (!s)
		return (NULL);

	s[len] = '\0';

	while (len--)
	{
		s[len] = (n % 10) + '0';
		n /= 10;
	}

	return (s);
}
