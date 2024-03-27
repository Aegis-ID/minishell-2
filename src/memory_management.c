/*
** EPITECH PROJECT, 2024
** minishell
** File description:
** input && historys history
*/

#include "my.h"

void free_node(list node)
{
    free(node->raw);
    free(node->name);
    free(node->path);
    node->next = 0;
    free(node);
    node = 0;
    return;
}

void free_double_char(char **str)
{
    for (int y = 0; str[y] != 0; y++)
        free(str[y]);
    free(str);
    return;
}

void free_parsed_env(list parsed_env)
{
    while (parsed_env != 0) {
        free(parsed_env->raw);
        free(parsed_env->name);
        free(parsed_env->path);
        parsed_env = parsed_env->next;
    }
    free(parsed_env);
    return;
}

void free_history(list history)
{
    while (history != 0) {
        free(history->raw);
        history = history->next;
    }
    free(history);
    return;
}
