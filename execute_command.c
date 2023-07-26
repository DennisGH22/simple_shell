#include "shell.h"

/**
 * exec_command - Execute a command and wait for the child process
 * @arguments: Array of arguments (including the command) to be executed
 * Return: Exit status of the child process
*/

int exec_command(char **arguments)
{
    pid_t pid;
    int exe_stat, status;

    pid = fork(); // Create a new child process

    if (pid == -1) // Fork failed
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    else if (pid == 0) // Child process
    {
        execvp(arguments[0], arguments); // Execute the command
        perror("execvp"); // If execvp returns, an error occurred
        exit(EXIT_FAILURE);
    }
    else // Parent process
    {
        if (waitpid(pid, &status, 0) == -1) // Wait for the child to finish
        {
            perror("waitpid");
            exit(EXIT_FAILURE);
        }

        if (WIFEXITED(status)) // Check if the child process terminated normally
            exe_stat = WEXITSTATUS(status); // Get the exit status of the child process
        else
            exe_stat = -1; // Something went wrong, set a non-standard error code

        return (exe_stat);
    }
}
