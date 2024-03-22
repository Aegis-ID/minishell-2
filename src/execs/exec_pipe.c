/*
** EPITECH PROJECT, 2024
** minishell 2
** File description:
** exec pipe
*/

#include "lib.h"
#include "my.h"

int check_pipe(char **parsed_input)
{
    for (int i = 0; parsed_input[i] != 0; i++)
        if (my_strcmp(parsed_input[i], "|") == 0)
            return 1;
    return 0;
}

static char **get_parsed_pipe(char **parsed_input,
    int begin, int end)
{
    int size = 0;
    char **parsed_pipe = 0;
    int x = 0;

    parsed_pipe = malloc(sizeof(char *) * ((size) + 1));
    for (int i = 0; parsed_input[i] != 0; i++) {
        if (my_strcmp(parsed_input[i], "|") != 0) {
            parsed_pipe[x] = my_strndup(parsed_input[i],
                my_strlen_delim(parsed_input[i], 0, '|'));
            x++;
        }
    }
    parsed_pipe[size] = 0;
    return parsed_pipe;
}

int exec_pipe(char **parsed_input, list parsed_env)
{
    char **parsed_pipe = 0;
    int status = 0;
    int begin = 0;

    for (int i = 0; parsed_pipe[i] != 0; i++) {
        if (my_strcmp(parsed_pipe[i], "|") == 0) {
            parsed_pipe = get_parsed_pipe(parsed_input, begin, i);
            status = exec_binary(parsed_pipe, parsed_env);
            free_double_char(parsed_pipe);
            begin += i + 1;
        }
    }
    return status;
}
