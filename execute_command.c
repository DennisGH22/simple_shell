#include "shell.h"

/**
 * exec - Executes the given command with the provided arguments.
 *
 * @args: An array of strings containing the command and its arguments.
*/


void _exec(char **args)
{
    // Check if the command is a built-in and execute it if it is.
    for (int i = 0; i < _builtins(); i++)
    {
        if (strcmp(args[0], builtins[i].name) == 0)
        {
            builtins[i].func(args);
            return;
        }
    }

    // If the command is not a built-in, fork a new process and execute the command.
    pid_t child_pid = fork();

    if (child_pid == 0)
    {
        // Child process: Execute the command.
        execvp(args[0], args);
        perror("err"); // Print an error if execvp fails.
        exit(1); // Terminate the child process with an error status.
    }
    else if (child_pid > 0)
    {
        // Parent process: Wait for the child process to complete.
        int status;
        do
        {
            waitpid(child_pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }
    else
    {
        // Fork failed, print an error.
        perror("err");
    }
}
