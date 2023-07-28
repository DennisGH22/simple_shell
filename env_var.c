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
    int env_index = 0, char_index;
    int match_status;

    for (; environ[env_index]; env_index++)
    {
        match_status = 1;

        for (char_index = 0; environ[env_index][char_index] != '='; char_index++)
        {
            if (environ[env_index][char_index] != env_var[char_index])
                match_status = 0;
        }

        if (match_status == 1)
            break;
    }

    return (&environ[env_index][char_index + 1]);
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

