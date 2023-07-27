#include "shell.h"

/**
 * _strcpy - Copies the string pointed to by src.
 * @dest: destination.
 * @src: source.
 *
 * Return: dest.
*/

char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; i >= 0; i++)
	{
		*(dest + i) = *(src + i);

		if (*(src + i) == '\0')
		{
			break;
		}
	}
	return (dest);
}

/**
 * _strlen - Returns the length of a string.
 * @s: String checked.
 *
 * Return: String length.
*/

int _strlen(char *s)
{
	return (strlen(s));
}

/**
 * _strcat - Concatenate two strings.
 * @dest: Destinaion.
 * @src: Source.
 *
 * Return: dest.
*/

char *_strcat(char *dest, char *src)
{
	int i, c;

	for (i = 0; dest[i] != '\0'; i++)
	{
		/**
		 * Do nothing...
		*/
	}

	for (c = 0; src[c] != '\0'; c++)
	{
		dest[i] = src[c];
		i++;
	}

	dest[i] = '\0';

	return (dest);
}
