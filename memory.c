#include "shell.h"

/**
 * malloc_checked - Allocates memory using malloc.
 * @b: Number of bytes in memory.
 *
 * Return: A pointer to the allocated memory.
*/

void *_malloc(unsigned int b)
{
	void *ptr;

	ptr = malloc(b);

	if (ptr == NULL)
		exit(98);

	return (ptr);
}
