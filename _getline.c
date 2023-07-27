/**
 * empty_line - checks if a line is empty (contains only spaces).
 * @buff: line
 *
 * Return: 0 if the line is not empty, 1 if it is empty.
*/

int _getline(char *buff)
{
	if (buff == NULL)
		return (1);

	while (*buff)
	{
		if (*buff != ' ')
			return (0);
		buff++;
	}

	return (1);
}
