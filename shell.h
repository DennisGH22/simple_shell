#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_ARGS 1024

typedef struct {
	char *arguments[MAX_ARGS];
	int line_counter;
	int is_interactive;
	int exit_status;
} ShellData;

typedef struct {
	char *cmd;
	int (*func)(ShellData *);
} BuiltinCmd;

/* Main shell loop */
int loop(ShellData *data, char **args);

/* Check if a command is a builtin command */
int is_builtin(const char *cmd);

/* Execute a builtin command */
int execute_builtin(ShellData *data);

/* Execute an external command */
void execute_external(ShellData *data);

// Array of struct builtins representing the list of available built-in commands.
BuiltinCmd builtins[] = {
	{"cd", _cd_},
	{"exit", _exit_},
	{"help", _help_}
};

#endif