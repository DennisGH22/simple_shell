#ifndef SHELL_H
#define SHELL_H

/*LIBRARIES*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>

/*PROTOTYPES*/
int _strcmp(char *s1, char *s2);
char *_strcpy(char *dest, char *src);
char *env_path(char *command);
char **split_string(char *str, char *sep);
char *_strcat(char *dest, char *src);
int _strlen(char *s);
char *_getenv(char *env_var);
void *_malloc(unsigned int b);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void _env(void);
int execute_command(char **args);
int empty_line(char *buff);

/* GLOBAL VAR*/
extern char **environ;

#endif
