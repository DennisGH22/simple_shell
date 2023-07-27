#include "shell.h"

/**
 * _getenv - Get the value of an environment variable.
 * @env_var: Name of the environment variable to retrieve.
 *
 * Return: A pointer to the value of the environment variable,
 * or NULL if not found.
*/

char *_getenv(char *env_var)
{
	if (env_var == NULL || *env_var == '\0')
		return NULL;

	char **env_ptr = environ;

	while (*env_ptr)
	{
		char *env_name = *env_ptr;

		/* Compare the environment variable name */
		while (*env_var && *env_var == *env_name)
		{
			env_var++;
			env_name++;
		}

		/* Check if the environment variable matches */
		if (*env_var == '\0' && *env_name == '=')
			return env_name + 1;

		env_ptr++;
	}

	return NULL;
}

/**
 * _env - Print all environment variables.
*/

void _env(void)
{
	for (char **env = environ; *env != NULL; env++)
	{
		printf("%s\n", *env);
	}
}