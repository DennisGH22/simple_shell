#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <signal.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

#define PRINTER(c) (write(STDOUT_FILENO, c, _strlen(c)))

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
char *_itoa(unsigned int n);
void exit_shell(char **cmd, char *input, char **argv, int c);

extern char **environ;

#endif
