/*
** EPITECH PROJECT, 2024
** minishell
** File description:
** my_env.c
*/

#include "include/my.h"

int my_env(list parsed_env)
{
    for (int i = 0; parsed_env != NULL; i++) {
        mini_printf("%s\n", parsed_env->raw);
        parsed_env = parsed_env->next;
    }
    return 0;
}
