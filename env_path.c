#include "main.h"

/**
 * search_path - Search for the command in the directories listed in the PATH environment variable.
 * @command: The command to search for in the PATH.
 * Return: The absolute path of the command if found, or NULL if not found.
*/

char *env_path(const char *command)
{
	char *path_env = getenv("PATH");
	if (path_env == NULL || command == NULL || *command == '\0')
		return (NULL);

	char *path_env_copy = strdup(path_env);
	if (path_env_copy == NULL)
		return (NULL);

	char *path_dir;
	char *path_concatenated = NULL;
	const char *delimiter = ":";

	struct stat file_info;
	char *result_path = NULL;

	path_dir = strtok(path_env_copy, delimiter);
	while (path_dir != NULL)
	{
		size_t path_len = strlen(path_dir);

		if (path_dir[path_len - 1] != '/')
			asprintf(&path_concatenated, "%s/%s", path_dir, command);
		else
			asprintf(&path_concatenated, "%s%s", path_dir, command);

		if (path_concatenated == NULL)
			break;

		if (stat(path_concatenated, &file_info) == 0)
		{
			result_path = strdup(path_concatenated);
			free(path_concatenated);
			break;
		}

		free(path_concatenated);
		path_dir = strtok(NULL, delimiter);
	}

	free(path_env_copy);
	return (result_path);
}
