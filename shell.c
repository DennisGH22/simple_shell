#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_INPUT_LENGTH 1024
#define MAX_ARGS 64

void execute_command(char* args[]) {
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        // Child process
        execvp(args[0], args);
        perror("execvp");
        exit(EXIT_FAILURE);
    } else {
        // Parent process
        int status;
        waitpid(pid, &status, 0);
    }
}

void parse_input(char* input, char* args[]) {
    char* token;
    int arg_count = 0;

    token = strtok(input, " \t\n");
    while (token != NULL && arg_count < MAX_ARGS) {
        args[arg_count++] = token;
        token = strtok(NULL, " \t\n");
    }
    args[arg_count] = NULL; // Set the last element to NULL to indicate the end of args array
}

int main() {
    char input[MAX_INPUT_LENGTH];
    char* args[MAX_ARGS];

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

        parse_input(input, args);

        if (args[0] != NULL) {
            if (strcmp(args[0], "exit") == 0) {
                // Exit the shell
                break;
            }

            execute_command(args);
        }
    }

    return 0;
}
