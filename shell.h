#ifndef _SHELL_H_
#define _SHELL_H_

#include <errno.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>


void _exit(char **args);
void _exec(char **args);
int builtins();
void _cd(char **args);
char** tokenize(char *line);
char *_getline();

// Definition of a structure to represent built-in commands and their corresponding functions.
struct builtin {
    char *name;
    void (*func)(char **args);
};

// Array of struct builtins representing the list of available built-in commands.
struct builtin builtins[] = {
    {"help", help},
    {"exit", exit},
    {"cd", cd},
};

#endif