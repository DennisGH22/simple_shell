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
#include <fcntl.h>
#include <errno.h>
#include <limits.h>

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

typedef int (*builtin_func)(char **cmd, int er);

typedef struct {
    const char *command;
    builtin_func fun;
} builtin_entry;

int ch_dir(char **args, int err);
/* int echo_env(char **args, int err);
int echo_help(char **args, int err);
int execute_echo(char **args, int err);
int echo_history(char **args, int err); */

builtin_entry builtins[] = {
    {"cd", ch_dir},
    /* {"env", echo_env},
    {"help", echo_help},
    {"echo", execute_echo},
    {"history", echo_history}, */
    {NULL, NULL}
};

int _builtins(char **args, int err);

extern char **environ;

#endif
