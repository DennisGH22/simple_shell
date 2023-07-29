#include "main.h"

void exit_shell(char **cmd, char *input, char **argv, int c) {
    int status;

    if (cmd[1] == NULL) {
        free(input);
        free(cmd);
        exit(EXIT_SUCCESS);
    }

    if (is_all_digits(cmd[1])) {
        status = _atoi(cmd[1]);
        free(input);
        free(cmd);
        exit(status);
    }

    print_error(argv, c, cmd);
    free(input);
    free(cmd);
    exit(EXIT_FAILURE);
}
