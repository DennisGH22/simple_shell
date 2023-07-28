#include "main.h"

/**
 * search_path - Search for the command in the directories
 * listed in the PATH environment variable.
 *
 * @command: The command to search for in the PATH.
 *
 * Return: The absolute path of the command if found,
 * or NULL if not found.
*/

char *env_path(char *command)
{
	char *path_copy, **path_dirs, *path_concatenated = NULL,
	*path_env = _getenv("PATH");
	int i, path_len = 0;

    struct stat file_info;

	if (stat(command, &file_info) == 0)
		return (command);

	path_copy = malloc(_strlen(path_env) + 1);
	if (path_copy == NULL)
		return (NULL);

	_strcpy(path_copy, path_env);
	path_dirs = _split(path_copy, ":");

	for (i = 0; path_dirs[i]; i++)
	{
		path_len = _strlen(path_dirs[i]);

		if (path_dirs[i][path_len - 1] != '/')
			path_concatenated = _strcat(path_dirs[i], "/");
		else
			path_concatenated = _strcat(path_dirs[i], command);

		if (path_concatenated == NULL)
			break;

		if (stat(path_concatenated, &file_info) == 0)
			break;
	}

	free(path_copy);

	if (!path_dirs[i])
	{
		free(path_dirs);
		return (NULL);
	}

	free(path_dirs);
	return (path_concatenated);
}
