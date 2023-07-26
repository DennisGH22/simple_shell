#include "shell.h"

/**
 * tokenize - the input line into tokens using specified delimiters.
 *
 * @line: The input line to be split into tokens.
 *
 * Return: An array of strings (tokens) obtained from the input line.
*/

char **tokenize(char *line)
{
    int length = 0;
    int capacity = 16;

    // Allocate memory for an initial capacity of tokens.
    char **tokens = malloc(capacity * sizeof(char*));
    if (!tokens)
    {
        perror("err");
        exit(1);
    }

    char *delimiters = " \t\r\n";
    char *token = strtok(line, delimiters);

    // Iterate through the input line and split it into tokens.
    while (token != NULL)
    {
        tokens[length] = token;
        length++;

        // Resize the tokens array if it reaches its capacity.
        if (length >= capacity)
        {
            capacity = (int) (capacity * 1.5);
            tokens = realloc(tokens, capacity * sizeof(char*));
            if (!tokens)
            {
                perror("err");
                exit(1);
            }
        }

        token = strtok(NULL, delimiters);
    }

    tokens[length] = NULL; // Add a NULL element to mark the end of tokens.
    return (tokens); // Return the array of tokens.
}
