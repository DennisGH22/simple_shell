#include "shell.h"

/* Main shell loop */
int loop(ShellData *data, char **args)
{
    ssize_t read_result = 0;
    int builtin_result = 0;
    char input_buffer[4096];

    for (; read_result != -1 && builtin_result != -2; data->line_counter++)
    {
        if (data->is_interactive)
            puts("$ ");

        fflush(stdout);
        read_result = get_input(input_buffer);
        if (read_result != -1)
        {
            // Tokenize the input and store it in data->arguments
            int i = 0;
            char *token = strtok(input_buffer, " \t\n");
            while (token && i < MAX_ARGS - 1)
            {
                data->arguments[i] = strdup(token);
                token = strtok(NULL, " \t\n");
                i++;
            }
            data->arguments[i] = NULL;

            builtin_result = is_builtin(data->arguments[0]) ? execute_builtin(data) : execute_external(data);
        }
        else if (data->is_interactive)
        {
            putchar('\n');
        }

        // Free memory allocated for arguments
        for (int i = 0; data->arguments[i]; i++)
        {
            free(data->arguments[i]);
            data->arguments[i] = NULL;
        }
    }

    write_history(data);

    if (!data->is_interactive && data->exit_status)
        exit(data->exit_status);

    if (builtin_result == -2)
    {
        if (data->exit_status == -1)
            exit(data->exit_status);

        exit(data->exit_status);
    }

    return (builtin_result);
}

int is_builtin(const char *cmd)
{
    static const char *builtin_commands[] = {
		"exit",
		"help",
		"cd"
	};

    for (int i = 0; builtin_commands[i]; i++)
	{
        if (strcmp(cmd, builtin_commands[i]) == 0)
		{
            return (1);
        }
    }

    return (0);
}

int execute_builtin(ShellData *data) 
{
    for (int i = 0; builtins[i].cmd; i++)
	{
        if (strcmp(data->arguments[0], builtins[i].cmd) == 0)
		{
            return builtins[i].func(data);
        }
    }

    return (-1); // Command not found (should not reach this point)
}

/* Execute an external command */
void execute_external(ShellData *data)
{
    pid_t pid = fork();

    if (pid == -1)
    {
        perror("Error:");
        return;
    }

    if (pid == 0)
    {
        execvp(data->arguments[0], data->arguments);
        perror("Error:");
        exit(1);
    }
    else
    {
        wait(&(data->exit_status));

        if (WIFEXITED(data->exit_status))
        {
            data->exit_status = WEXITSTATUS(data->exit_status);

            if (data->exit_status == 126)
                print_error(data, "Permission denied\n");
        }
    }
}
