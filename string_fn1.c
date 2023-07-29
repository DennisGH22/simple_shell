#include "main.h"

/**
 * _strchr - Locates a character in a string.
 * @s: The string.
 * @c: The character
 *
 * Return: A pointer to the first occurrence of the character,
 * or NULL if the character is not found.
*/

char *_strchr(char *s, char c)
{
	for (; *s; s++)
	{
		if (*s == c)
		{
			return (s);
		}
	}

	if (c == '\0')
	{
		return (s);
	}

	return (NULL);
}

/**
 * reverse_array - Reverse the contents of an array of integers.
 * @a: Array of integers.
 * @n: Number of elements in the array.
*/

void reverse_array(int *a, int n)
{
	int i;
	int temp;

	for (i = 0; i < (n / 2); i++)
	{
		temp = a[i];
		a[i] = a[n - i - 1];
		a[n - i - 1] = temp;
	}
}
