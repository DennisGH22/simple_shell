#include "shell.h"

/**
 * main - Runs an infinite loop to get user input and execute commands.
 *
 * @return: Always 0 (Success).
*/

int main(void)
{
    while (1)
    {
        char prompt[] = "$ ";
        write(1, prompt, sizeof(prompt) - 1);

        char *line = _getline();
        char **tokens = tokenize(line);

        if (tokens[0] != NULL)
        {
            _exec(tokens);
        }

        free(tokens);
        free(line);
    }

    return (0);
}