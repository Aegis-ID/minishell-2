/*
** EPITECH PROJECT, 2024
** handle semicolons
** File description:
** minishell-2
*/

#include "my.h"
#include "lib.h"

int handle_semicolons(char *input, char **parsed_input,
    list parsed_env, list history)
{
    int status = 0;
    char *tokens = "\t\n ";
    char **command = str_to_word_array(input, ";");

    for (int y = 0; command[y] != 0; y++) {
        parsed_input = str_to_word_array(command[y], tokens);
        status = handle_execs(parsed_input, parsed_env, history);
    }
    free_double_char(command);
    return status;
}
