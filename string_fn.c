#include "main.h"

/**
 * _strcmp - Compare two strings.
 * @s1: string A.
 * @s2: string B.
 *
 * Return: negative int if s1 < s2, 0 if matching, and positive int if s1 > s2.
*/

int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] != '\0' || s2[i] != '\0'; i++)
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
	}

	return (0);
}

/**
 * split_string - Split a string into an array of tokens based on a delimiter.
 * @str: The string to split.
 * @delimiter: The delimiter used for splitting.
 *
 * Return: An array of tokens if successful, or NULL on failure.
*/

char **split_string(char *str, char *delimiter)
{
	char *token;
	char **split_str = (char **)_calloc(100, sizeof(char *));
	int i;

	if (!split_str)
	{
		free(split_str);
		return (NULL);
	}

	for (i = 0; i < 100; i++)
	{
		token = strtok(i == 0 ? str : NULL, delimiter);
		if (token == NULL)
			break;

		split_str[i] = token;
	}

	return (split_str);
}

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
