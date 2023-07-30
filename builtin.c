#include "main.h"

/**
 * _cd - Change the current working directory.
 * @arguments: The array of command arguments.
 * @argumentCount: The number of arguments in the command.
 *
 * @return: Always returns 0.
*/

int _changeDir(char **arguments, int argumentCount)
{
    char hyphen[] = "-";
    const char *homeEnvVar = "HOME";
    const char *oldPwdEnvVar = "OLDPWD";
    const char *pwdEnvVar = "PWD";

    if (arguments == NULL || arguments[1] == NULL)
    {
        if (_getenv(homeEnvVar) == NULL)
            printError(arguments[0], argumentCount, arguments);
        else
        {
            changeDirToHome();
            setenv(oldPwdEnvVar, _getenv(pwdEnvVar), 1);
            setenv(pwdEnvVar, getcwd(NULL, 0), 1);
        }
    }
    else if (_strcmp(arguments[1], hyphen) == 0)
    {
        if (_getenv(oldPwdEnvVar) == NULL)
            setenv(oldPwdEnvVar, _getenv(pwdEnvVar), 1);
        else
        {
            changeDirToPrev();
            write(1, _getenv(pwdEnvVar), _strlen(_getenv(pwdEnvVar)));
            _printf("\n");
        }
    }
    else
    {
        if (access(arguments[1], F_OK) == -1)
            printError(arguments[0], argumentCount, arguments);
        else
        {
            setenv(oldPwdEnvVar, _getenv(pwdEnvVar), 1);
            changeDirToPath(arguments[1]);
            setenv(pwdEnvVar, getcwd(NULL, 0), 1);
        }
    }
    
    return (0);
}
