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

    if (is_in_str(';', input))
        handle_semicolons(input, parsed_input, parsed_env,
            history);
    return status;
}
