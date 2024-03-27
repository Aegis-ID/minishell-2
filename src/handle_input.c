/*
** EPITECH PROJECT, 2024
** minishell
** File description:
** handle input
*/

#include "my.h"
#include "lib.h"
#include <string.h>

static list insert_command(list command, char *str)
{
    list node;
    list tmp = command;

    node = malloc(sizeof(*node));
    node->raw = my_strdup(strtok(str, " \t\n"));
    node->next = 0;
    if (is_empty_list(command))
        return node;
    while (tmp->next != 0)
        tmp = tmp->next;
    tmp->next = node;
    return command;
}

static void convert_input(char **parsed_input, char *input)
{
    char *separators = " \t\n";

    for (int i = 0; parsed_input[i] != 0; i++) {
        if (i == 0) {
            free(parsed_input[i]);
            parsed_input[i] = strtok(input, separators);
        } else {
            free(parsed_input[i]);
            parsed_input[i] = strtok(0, separators);
        }
    }
    return;
}

static int exec_input(char **parsed_input, list parsed_env, list command)
{
    if (parsed_input[0] != 0) {
        if (is_builtins_funcs(parsed_input[0]))
            return exec_builtins(parsed_input, parsed_env, command);
        return exec_env_bin(parsed_input, parsed_env);
    }
    return 1;
}

int handle_input(char *input, char **parsed_input,
    list parsed_env, list command)
{
    int status = 0;

    if (!is_str_empty(input)) {
        // command = insert_command(command, input);
        parsed_input = str_to_word_array(input, " ");
        convert_input(parsed_input, input);
        status = exec_input(parsed_input, parsed_env, command);
        free(parsed_input);
        return status;
    }
    return status;
}
