#include "main.h"

/**
 * _isBuiltin - Check if the command is a built-in command and execute it.
 * @arguments: The array of command arguments.
 * @buffer: The buffer used for storing data.
 * @argumentCount: The number of arguments in the command.
 *
 * @return: 0 if a built-in command is executed successfully or,
 * 1 if the command is not a built-in command or,
 * -1 if any of the required pointers are NULL.
*/

int _isBuiltin(const char **arguments, char *buffer, int argumentCount)
{
	if (arguments == NULL || *arguments == NULL || buffer == NULL)
	{
		return (-1);
	}

	if (isEnvCommand(arguments[0]))
	{
		_env();
		return (0);
	}
	else if (isExitCommand(arguments[0]))
	{
		return (2);
	}
	else if (isCdCommand(arguments[0]))
	{
		_cd(arguments, argumentCount);
		return (0);
	}
	else if (isHelpCommand(arguments[0]))
	{
		_help(arguments);
		return (0);
	}
	else if (isEchoCommand(arguments[0]))
	{
		_echo(arguments);
		return (0);
	}

	return (1);
}

/**
 * changeDirToHome - Change the current working directory to HOME directory.
 *
 * This function changes the current working directory to the HOME directory
 * obtained from the 'HOME' environment variable.
*/

void changeDirToHome(void)
{
    const char *homeDir = _getenv("HOME");
    chdir(homeDir);
}

/**
 * changeDirToPrev - Change the current working directory to the previous directory.
 *
 * This function changes the current working directory to the previous directory
 * obtained from the 'OLDPWD' environment variable.
*/

void changeDirToPrev(void)
{
    const char *oldPwdDir = _getenv("OLDPWD");
    chdir(oldPwdDir);
}

/**
 * changeDirToPath - Change the current working directory to a specified path.
 * @path: The path to which the current working directory will be changed.
 *
 * This function changes the current working directory to the specified 'path'.
*/

void changeDirToPath(const char *path)
{
    chdir(path);
}
