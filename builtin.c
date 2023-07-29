#include "main.h"

/*
 * _builtins - Find and execute a built-in command, if it exists.
 * @args: An array of strings containing the command and its arguments.
 * @err: An integer representing the last command's exit status.
 *
 * Return: The exit status of the executed command, if found.
 * -1 if the command is not a built-in or,
 * if it's not found in the 'builtins' array.
*/

int _builtins(char **args, int err)
{
	int i = 0;

	while (builtins[i].command != NULL) {
		if (_strcmp(args[0], builtins[i].command) == 0)
			return builtins[i].function(args, err);

		i++;
	}

	return (-1);
}

/**
 * change_directory - Change the current working directory.
 * @cmd: The command and arguments provided by the user.
 *
 * Return: On success, returns 0. On failure, returns -1.
*/

int ch_dir(char **cmd, __attribute__((unused))int er)
{
	int success = -1;
	char cwd[PATH_MAX];

	if (cmd[1] == NULL)
	{
		success = chdir(getenv("HOME"));
	}
	else if (strcmp(cmd[1], "-") == 0)
	{
		success = chdir(getenv("OLDPWD"));
	}
	else
	{
		success = chdir(cmd[1]);
	}

	if (success == -1)
	{
		perror("change_directory");
		return (-1);
	}
	else
	{
		getcwd(cwd, sizeof(cwd));
		setenv("OLDPWD", getenv("PWD"), 1);
		setenv("PWD", cwd, 1);
	}

	return (0);
}
