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
#include <linux/limits.h>

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
char *_itoa(unsigned int n);
int _isdigit(int c);
int is_all_digits(const char *str);
void exit_shell(char **cmd, char *input, char **argv, int c);
void print_error(char **cmd);

extern char **environ;

#endif
