/*
** EPITECH PROJECT, 2024
** handle command flags
** File description:
** minishell-2
*/

#include "my.h"
#include "lib.h"

int handle_command_flags(char *input, char **parsed_input,
    list parsed_env, list history)
{
    int status = 0;

    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] == ';' && (input[i + 1] != ';')) {
            status = handle_semicolons(input, parsed_input,
            parsed_env, history);
        }
    }
    return status;
}
