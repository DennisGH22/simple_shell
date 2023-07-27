#ifndef SHELL_H
#define SHELL_H

/*LIBRARIES*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>

int execute_command(char **args);
char *_getenv(char *env_var);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
void _env(void);
char **split_string(char *str, char *delimiter);
char *_strcpy(char *dest, char *src);
int _strlen(char *s);
void *_malloc(unsigned int nmemb, unsigned int size);
char *_path(char *command);
int _getline(char *buff);

extern char **environ;

#endif