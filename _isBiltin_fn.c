#include "main.h"

/**
 * isEnvCommand - Check if the command is "env".
 * @command: The command to check.
 *
 * Return: 1 if the command is "env", 0 otherwise.
*/

int isEnvCommand(const char *command)
{
    return (_strcmp(command, "env") == 0 && _strlen(command) == ENV_COMMAND_LENGTH);
}

/**
 * isExitCommand - Check if the command is "exit".
 * @command: The command to check.
 *
 * Return: 1 if the command is "exit", 0 otherwise.
*/

int isExitCommand(const char *command)
{
    return (_strcmp(command, "exit") == 0 && _strlen(command) == EXIT_COMMAND_LENGTH);
}

/**
 * isCdCommand - Check if the command is "cd".
 * @command: The command to check.
 *
 * Return: 1 if the command is "cd", 0 otherwise.
*/

int isCdCommand(const char *command)
{
    return (_strcmp(command, "cd") == 0 && _strlen(command) == CD_COMMAND_LENGTH);
}

/**
 * isHelpCommand - Check if the command is "help".
 * @command: The command to check.
 *
 * Return: 1 if the command is "help", 0 otherwise.
*/

int isHelpCommand(const char *command)
{
    return (_strcmp(command, "help") == 0 && _strlen(command) == HELP_COMMAND_LENGTH);
}

/**
 * isEchoCommand - Check if the command is "echo".
 * @command: The command to check.
 *
 * Return: 1 if the command is "echo", 0 otherwise.
*/

int isEchoCommand(const char *command)
{
    return (_strcmp(command, "echo") == 0 && _strlen(command) == ECHO_COMMAND_LENGTH);
}
