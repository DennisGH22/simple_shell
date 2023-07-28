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
	char *token, **split_str;
	int i;

	token = strtok(str, delimiter);
	split_str = (char **)_calloc(100, sizeof(char *));

	if (!split_str)
	{
		free(split_str);
		return (NULL);
	}

	for (; token; i++)
	{
		split_str[i] = token;
		token = strtok(NULL, delimiter);
	}

	return (split_str);
}

/**
 * _strcpy - function that copies the string pointed to by src
 * @dest: pointer
 * @src: ponter
 * Return: @dest
 */
char *_strcpy(char *dest, char *src)
{
	char *c = dest;

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (c);
}

/**
 * _strcat - function that concatenates two strings
 * @dest: string
 * @src: string
 * Return: @dest
 */

char *_strcat(char *dest, char *src)
{
	int a, b;

	for (a = 0; dest[a] != '\0'; a += 1)
	{}

	for (b = 0; src[b] != '\0'; b += 1)
	{
		dest[a] = src[b];
		a++;
	}
	dest[a] = '\0';
	return (dest);
}

/**
 * _strlen - string length
 * @s: string
 * Return: result
 *
 */

int _strlen(char *s)
{
	int i = 0;

	while (s[i] != '\0')
		i++;

	return (i);
}


