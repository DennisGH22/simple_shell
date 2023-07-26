#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include "shell.h"

#define MAX_INPUT_LENGTH 1024

void execute_command(char* command) {
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        // Child process
        char* args[] = {command, NULL};
        if (execvp(command, args) == -1) {
            perror("execvp");
            exit(EXIT_FAILURE);
        }
    } else {
        // Parent process
        int status;
        waitpid(pid, &status, 0);
    }
}

int main() {
    char input[MAX_INPUT_LENGTH];

    while (1) {
        printf("Shell > ");
        fflush(stdout);

        if (fgets(input, MAX_INPUT_LENGTH, stdin) == NULL) {
            // End of input (e.g., CTRL+D pressed)
            break;
        }

        // Remove newline character at the end
        if (input[strlen(input) - 1] == '\n') {
            input[strlen(input) - 1] = '\0';
        }

        if (strcmp(input, "exit") == 0) {
            // Exit the shell
            break;
        }

        execute_command(input);
    }

    return 0;
}
