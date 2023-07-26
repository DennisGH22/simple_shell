#ifndef SHELL_H
#define SHELL_H

#define MAX_COMMAND_LENGTH 100
#define MAX_ARGS 10

void executeCommand(char** args);

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#endif
