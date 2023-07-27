#include "main.h"

/**
 * _strdup - Returns a pointer to a newly allocated space in memory.
 * @str: The string.
 *
 * Return: A pointer to the duplicated string, or NULL if str = NULL.
*/

char *_strdup(char *str)
{
	size_t i, len;
	char *dup;

	if (str == NULL)
		return (NULL);

	for (len = 0; str[len] != '\0'; len++)
		; /* Do nothing.. */

	dup = (char *)malloc((len + 1) * sizeof(char));

	if (dup == NULL)
		return (NULL);

	for (i = 0; i <= len; i++)
		dup[i] = str[i];

	return (dup);
}
