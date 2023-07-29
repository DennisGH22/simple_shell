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

/**
 * _strncpy - Copy a string starting from index 0.
 * @dest: Destination
 * @src: Source
 * @n: Number of chars to copy.
 *
 * Return: dest
*/

char *_strncpy(char *dest, char *src, int n)
{
	int i;

	for (i = 0; i < n && src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}

	for (; n > i; i++)
	{
		dest[i] = '\0';
	}

	return (dest);
}

/**
 * strncmp - Compare the first 'n' characters of two strings.
 * @s1: Pointer to the first string to be compared.
 * @s2: Pointer to the second string to be compared.
 * @n: The maximum number of characters to compare.
 *
 * Return: Negative value if s1 < s2, positive value if s1 > s2, 0 if equal.
*/

int _strncmp(char *s1, char *s2, int n)
{
	for (; n > 0 && (*s1 || *s2); s1++, s2++, n--)
    {
        if (*s1 != *s2)
        {
            return (*s1 - *s2);
        }
    }

    return (0);
}
