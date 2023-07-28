#include "shell.h"

/**
 * empty_line - checks if a line is empty (contains only spaces).
 * @line: line
 *
 * Return: 0 if the line is not empty, 1 if it is empty.
*/

int _getline(char *line)
{
	if (line == NULL)
		return (1);

	while (*line)
	{
		if (*line != ' ')
			return (0);
		line++;
	}

	return (1);
}
