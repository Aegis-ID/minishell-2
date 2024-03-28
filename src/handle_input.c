/*
** EPITECH PROJECT, 2024
** minishell
** File description:
** handle input
*/

#include "my.h"
#include "lib.h"
#include <string.h>

static list insert_history(list history, char *str)
{
    list node = {0};
    list tmp = history;

    node = malloc(sizeof(*node));
    node->raw = my_strdup(strtok(str, " \t\n"));
    node->next = 0;
    if (is_empty_list(history))
        return node;
    while (tmp->next != 0)
        tmp = tmp->next;
    tmp->next = node;
    return history;
}

int exec_input(char **parsed_input,
    list parsed_env, list history)
{
    if (parsed_input[0] != 0) {
        if (is_builtins_funcs(parsed_input[0]))
            return exec_builtins(parsed_input, parsed_env, history);
        return exec_env_bin(parsed_input, parsed_env);
    }
    return 1;
}

static int get_begin(int position, char *input, char *delim)
{
    int begin = position;

    while (is_in_str(input[begin], delim))
        begin++;
    return begin;
}

static int exec_multiple_command(char *input, char **parsed_input,
    list parsed_env, list history)
{
    int status = 0;
    int begin = 0;
    char *command = 0;
    char *command_flags = ";<|> ";

    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] == ';') {
            command = my_strndup(input + begin, i - begin);
            parsed_input = str_to_word_array(command, "\t\n ;");
            status = exec_input(parsed_input, parsed_env, history);
            begin = get_begin(i, input, command_flags);
        }
    }
    free(command);
    return status;
}

int handle_input(char *input, char **parsed_input,
    list parsed_env, list history)
{
    char *command_flags = ";<|>";

    if (!is_str_empty(input)) {
        /* history = insert_history(history, input); */
        if (are_in_str(command_flags, input)) {
            return exec_multiple_command(input, parsed_input,
                parsed_env, history);
        } else {
            parsed_input = str_to_word_array(input, " \t\n");
            return exec_input(parsed_input, parsed_env, history);
        }
    }
    return 84;
}
