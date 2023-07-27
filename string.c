#include "shell.h"

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
 * split_string - Split a string into multiple substrings using a delimiter.
 * @str: The input string to be split.
 * @delimiter: The delimiter string used to split the input string.
 *
 * Return: A dynamically allocated array of pointers to the substrings,
 * NULL if memory allocation fails or no substrings are found.
*/
char **split_string(char *str, char *delimiter)
{
	char **split_str = NULL;
	int num_tokens = 0;
	int max_tokens = 100; /* Initial maximum number of tokens */

	/* Allocate memory for the array of pointers to substrings */
	split_str = (char **)_malloc(max_tokens * sizeof(char *));
	if (!split_str)
	{
		return NULL;
	}

	/* Tokenize the input string using the specified delimiterarator */
	char *token = strtok(str, delimiter);
	while (token)
	{
		/* Store the current token in the array of pointers */
		split_str[num_tokens] = token;
		num_tokens++;

		/* Check if the maximum number of tokens is reached, and reallocate if needed */
		if (num_tokens >= max_tokens)
		{
			max_tokens *= 2; /* Double the maximum tokens */
			char **temp = (char **)_realloc(split_str, max_tokens * sizeof(char *));
			if (!temp)
			{
				/* Free previously allocated memory before returning NULL */
				for (int i = 0; i < num_tokens; i++)
					free(split_str[i]);
				free(split_str);
				return NULL;
			}
			split_str = temp;
		}

		/* Get the next token */
		token = strtok(NULL, delimiter);
	}

	/* Set the last element of the result array to NULL to indicate the end */
	split_str[num_tokens] = NULL;

	return split_str;
}
