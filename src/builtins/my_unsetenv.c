/*
** EPITECH PROJECT, 2024
** minishell
** File description:
** my_unsetenv
*/

#include "my.h"
#include "lib.h"

void delete_node(list parsed_env, char *path)
{
    list before = parsed_env;

    if (!check_list_name(parsed_env, path))
        return;
    while (my_strcmp(parsed_env->name, path) != 0) {
        before = parsed_env;
        parsed_env = parsed_env->next;
    }
    if (parsed_env->next == 0)
        before->next = 0;
    else
        before->next = parsed_env->next;
    free_node(parsed_env);
    parsed_env = 0;
    return;
}

int my_unsetenv(char **parsed_input, list parsed_env)
{
    int len = my_arraylen(parsed_input);

    if (len < 2) {
        mini_dprintf(2, "%s: Too few arguments.\n", parsed_input[0]);
        return 1;
    }
    for (int x = 1; x < len; x++)
        delete_node(parsed_env, parsed_input[x]);
    return 0;
}
