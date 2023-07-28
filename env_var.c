#include "main.h"

/**
 * _getenv - Get the value of an environment variable.
 * @env_var: Name of the environment variable to retrieve.
 *
 * Return: A pointer to the value of the environment variable,
 * or NULL if not found.
*/

char *_getenv(char *env_var)
{
	int i = 0, j;
	int match_status;

	for (; environ[i]; i++)
	{
		match_status = 1;

		for (j = 0; environ[i][j] != '='; j++)
		{
			if (environ[i][j] != env_var[j])
				match_status = 0;
		}

		if (match_status == 1)
			break;
	}

	return (&environ[i][j + 1]);
}


/**
 * _env - Print all environment variables.
*/

void _env(void)
{
	int i = 0;

	for (; environ[i]; i++)
	{
		printf("%s\n", environ[i]);
	}
}
