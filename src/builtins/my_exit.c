/*
** EPITECH PROJECT, 2024
** minishell
** File description:
** my exit
*/

#include "my.h"
#include "lib.h"

void my_exit(char *input, list parsed_env, list history, int status)
{
    mini_printf("exit\n");
    free(input);
    free_history(history);
    free_parsed_env(parsed_env);
    exit(status);
}
