/*
** EPITECH PROJECT, 2024
** minishell
** File description:
** built in funcs
*/

#include "my.h"
#include "lib.h"
#include "builtins.h"

int is_builtins_funcs(char *str)
{
    char **builtins = (char **)BUILTINS_FUNCS;

    for (int i = 0; builtins[i] != 0; i++)
        if (my_strcmp(str, builtins[i]) == 0)
            return 1;
    return 0;
}

int exec_builtins(char **parsed_input, list parsed_env, list command)
{
    if (my_strcmp(parsed_input[0], "cd") == 0)
        return my_cd(parsed_input, parsed_env);
    if (my_strcmp(parsed_input[0], "env") == 0)
        return my_env(parsed_env);
    if (my_strcmp(parsed_input[0], "setenv") == 0)
        return my_setenv(parsed_input, parsed_env);
    if (my_strcmp(parsed_input[0], "unsetenv") == 0)
        return my_unsetenv(parsed_input, parsed_env);
    if (my_strcmp(parsed_input[0], "history") == 0)
        return my_env(command);
    return 1;
}
