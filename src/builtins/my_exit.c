/*
** EPITECH PROJECT, 2024
** minishell
** File description:
** my exit
*/

#include "my.h"
#include "lib.h"

void my_exit(char *input, list parsed_env, list command, int status)
{
    mini_printf("exit\n");
    free(input);
    free_command(command);
    free_parsed_env(parsed_env);
    exit(status);
}
