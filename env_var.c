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
 * _unsetenv - Remove an environment variable from the environment.
 * @var_name: The name of the variable to be removed.
 *
 * Return: 0 on success, -1 if the variable was not found.
*/

int _unsetenv(const char *var_name)
{
    char **current = environ;
    char **previous = environ;

    while (*current != NULL)
    {
        char *equal_sign = strchr(*current, '=');

        size_t name_length = equal_sign - *current;

        if (strncmp(*current, var_name, name_length) == 0 && var_name[name_length] == '\0')
        {

            free(*current);

            while (*current != NULL)
            {
                *current = *(current + 1);
                current++;
            }

            environ = previous;

            return (0);
        }

        
        current++;
    }

    return (-1);
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
