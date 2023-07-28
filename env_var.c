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

/**
 * _setenv - Set an environment variable or update its value.
 * @arg: The array.
 *
 * Return: 0 on success, -1 on allocation failure, or if name or value is NULL.
*/

void _setenv(char **arv)
{
    int i, j, k;
    char *var_name = arv[1];
    char *var_value = arv[2];

    if (!var_name || !var_value)
    {
        perror(_getenv("_"));
        return;
    }

    for (i = 0; environ[i]; i++)
    {
        j = 0;
        while (var_name[j] && environ[i][j] == var_name[j])
        {
            j++;
        }

        if (var_name[j] == '\0' && environ[i][j] == '=')
        {
            k = 0;
            while (var_value[k])
            {
                environ[i][j + 1 + k] = var_value[k];
                k++;
            }
            environ[i][j + 1 + k] = '\0';
            return;
        }
    }

    int num_env_vars = 0;
    for (i = 0; environ[i]; i++)
        num_env_vars++;

    char **new_env = realloc(environ, sizeof(char *) * (num_env_vars + 2));
    if (new_env == NULL)
        return;

    environ = new_env;

    char *new_env_var = malloc(strlen(var_name) + strlen(var_value) + 2);
    if (new_env_var == NULL)
        return;

    j = 0;
    while (var_name[j])
    {
        new_env_var[j] = var_name[j];
        j++;
    }
    new_env_var[j] = '=';
    k = 0;
    while (var_value[k])
    {
        new_env_var[j + 1 + k] = var_value[k];
        k++;
    }
    new_env_var[j + 1 + k] = '\0';

    environ[num_env_vars] = new_env_var;
    environ[num_env_vars + 1] = NULL;
}

/**
 * _unsetenv - Remove an environment variable from the environment.
 * @arg: The array
 *
 * Return: 0 on success, -1 if the variable was not found.
*/

void _unsetenv(char **arv)
{
    if (!arv[1])
    {
        perror(_getenv("_"));
        return;
    }

    char *variable_name = arv[1];

    char **env_var_ptr = environ;

    while (*env_var_ptr)
    {
        char *env_var = *env_var_ptr;

        char *p = variable_name;
        char *q = env_var;

        while (*p && *p == *q)
        {
            p++;
            q++;
        }

        if (*p == '\0' && *q == '=')
            break;

        env_var_ptr++;
    }

    if (*env_var_ptr)
    {
        free(*env_var_ptr);

        while (env_var_ptr[1])
        {
            env_var_ptr[0] = env_var_ptr[1];
            env_var_ptr++;
        }

        env_var_ptr[0] = NULL;

        environ = realloc(environ, (env_var_ptr - environ + 1) * sizeof(char *));
    }
}

