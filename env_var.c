#include "main.h"

/**
 * _getenv - Get the value of an environment variable.
 * @env_var: Name of the environment variable to retrieve.
 *
 * Return: A pointer to the value of the environment variable,
 * or NULL if not found.
*/


char *_getenv(const char *env_var)
{
    char **env_ptr;
    char *current_env_var;
    const char *target_var_ptr;

    if (env_var == NULL || *env_var == '\0')
        return (NULL);

    for (env_ptr = environ; *env_ptr; env_ptr++)
    {
        current_env_var = *env_ptr;
        target_var_ptr = env_var;

        for (; *current_env_var && *current_env_var == *target_var_ptr; current_env_var++, target_var_ptr++)
            ;

        if (*current_env_var == '=' && *target_var_ptr == '\0')
            return (current_env_var + 1);
    }

    return (NULL);
}

/**
 * _env - Print all environment variables.
*/

void _env(void)
{
    char **env_ptr;

    for (env_ptr = environ; *env_ptr; env_ptr++)
    {
        printf("%s\n", *env_ptr);
    }
}
