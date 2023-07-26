#ifndef SHELL_H
#define SHELL_H

#define MAX_COMMAND_LENGTH 100
#define MAX_ARGS 10

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <termios.h>

void execute_command(char **args, char **envp);
void handle_signal(int signum);
void run_shell();

#endif
