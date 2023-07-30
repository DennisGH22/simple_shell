#include "main.h"

/**
 * _changeDir - Change the current working directory.
 * @args: The array of command arguments.
 * @count: The number of arguments in the command.
 *
 * @return: Always returns 0.
*/

int _changeDir(char **args, int count)
{
	char hyphen[] = "-", *hsh = "./hsh";
	char *buff = malloc(sizeof(char) * MAX_PATH_LENGTH);

	if (args[1] == NULL)
	{
		/* Change to HOME directory */
		char *home_path = _getenv("HOME");
		if (!home_path)
			printError(&hsh, count, arguments);
		else
		{
			chdir(home_path);
			setenv("OLDPWD", _getenv("PWD"), 1);
			setenv("PWD", getcwd(buff, MAX_PATH_LENGTH), 1);
		}
	}
	else if (_strcmp(args[1], hyphen) == 0)
	{
		/* Change to the previous directory (OLDPWD) */
		char *old_pwd = _getenv("OLDPWD");
		if (!old_pwd)
			setenv("OLDPWD", _getenv("PWD"), 1);
		else
		{
			chdir(old_pwd);
			setenv("OLDPWD", _getenv("PWD"), 1);
			setenv("PWD", getcwd(buff, MAX_PATH_LENGTH), 1);
		}
		write(1, _getenv("PWD"), _strlen(_getenv("PWD")));
		printf("\n");
	}
	else if (args[1] != NULL && args[1] != hyphen)
	{
		/* Change to a specified directory */
		if (access(args[1], F_OK) == -1)
			printError(&hsh, count, arguments);
		else
		{
			setenv("OLDPWD", _getenv("PWD"), 1);
			chdir(args[1]);
			setenv("PWD", getcwd(buff, MAX_PATH_LENGTH), 1);
		}
	}
	free(buff);
	return (0);
}
