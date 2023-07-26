#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <ctype.h>


int exec_command(char **arguments);
int _isalpha(int c);
int _atoi(char *s);

#endif