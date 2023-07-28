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
 * _setenv - Set an environment variable or update its value.
 * @name: The name of the environment variable.
 * @value: The value to set for the environment variable.
 * @overwrite: Flag to indicate whether to overwrite the variable if it already exists.
 *
 * Return: 0 on success, -1 on allocation failure, or if name or value is NULL.
*/

int _setenv(const char *name, const char *value, int overwrite)
{
    if (name == NULL || value == NULL || name[0] == '\0')
        return (-1);

    size_t name_length = strlen(name);
    size_t value_length = strlen(value);

    for (char **env_var_ptr = environ; *env_var_ptr; env_var_ptr++)
    {
        char *current_env_var = *env_var_ptr;

        if (strncmp(current_env_var, name, name_length) == 0 && current_env_var[name_length] == '=')
        {
            if (!overwrite)
                return (0);

            char *updated_env_var = malloc(name_length + value_length + 2);
            if (updated_env_var == NULL)
                return (-1);

            snprintf(updated_env_var, name_length + value_length + 2, "%s=%s", name, value);
            *env_var_ptr = updated_env_var;
            return (0);
        }
    }

    size_t num_env_vars = 0;
    for (char **env_var_ptr = environ; *env_var_ptr; env_var_ptr++)
        num_env_vars++;

    char **new_env = _realloc(environ, sizeof(char *) * (num_env_vars + 2));
    if (new_env == NULL)
        return (-1);

    environ = new_env;
    char *new_env_var = malloc(name_length + value_length + 2);
    if (new_env_var == NULL)
        return (-1);

    snprintf(new_env_var, name_length + value_length + 2, "%s=%s", name, value);
    environ[num_env_vars] = new_env_var;
    environ[num_env_vars + 1] = NULL;

    return (0);
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
