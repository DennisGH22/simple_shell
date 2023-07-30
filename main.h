#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <signal.h>
#include <fcntl.h>
#include <errno.h>
#include <limits.h>

#define ENV_COMMAND_LENGTH 3
#define EXIT_COMMAND_LENGTH 4
#define CD_COMMAND_LENGTH 2
#define HELP_COMMAND_LENGTH 4
#define ECHO_COMMAND_LENGTH 4

#define BUFFER_SIZE 1024

int execute_command(char **args);
int _strcmp(char *s1, char *s2);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
int _strlen(char *s);
char *_getenv(char *env_var);
char *env_path(char *command);
char **split_string(char *str, char *delimiter);
void *_calloc(unsigned int nmemb, unsigned int size);
int _getline(char *line);
void _env(void);
int _atoi(char *s);
int _isalpha(int c);
int _isdigit(int c);
char *_strncpy(char *dest, char *src, int n);
int _strncmp(char *s1, char *s2, int n);

int isEnvCommand(char *command);
int isExitCommand(char *command);
int isCdCommand(char *command);
int isHelpCommand(char *command);
int isEchoCommand(char *command);
int _isBuiltin(char **arguments, char *buffer, int argumentCount);
void printError(char **command, int count, char **argument);
int intError(int num);

int _changeDir(char **arguments, int count);
/* void _help(char **arguments);
void _echo(char **arguments); */

void changeDirToHome(void);
void changeDirToPrev(void);
void changeDirToPath(char *path);

extern char **environ;

#endif
