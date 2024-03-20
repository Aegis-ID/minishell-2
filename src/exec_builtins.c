/*
** EPITECH PROJECT, 2024
** minishell
** File description:
** built in funcs
*/

#include "include/my.h"


static char **builtins_funcs(void)
{
    int builtins = 5;
    char **array = malloc(sizeof(char *) * (builtins + 1));

    array[0] = my_strdup("cd");
    array[1] = my_strdup("env");
    array[2] = my_strdup("setenv");
    array[3] = my_strdup("unsetenv");
    array[4] = my_strdup("history");
    array[builtins] = 0;
    return array;
}

int is_builtins_funcs(char *str)
{
    char **builtins = builtins_funcs();

    for (int i = 0; builtins[i] != 0; i++) {
        if (my_strcmp(str, builtins[i]) == 0) {
            free_double_char(builtins);
            return 1;
        }
    }
    free_double_char(builtins);
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
    return 0;
}
