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
    list head = history;
    list node = malloc(sizeof(*node));

    node->raw = my_strndup(str, my_strlen(str) - 1);
    node->next = 0;
    if (is_empty_list(history))
        return node;
    while (history->next != 0)
        history = history->next;
    history->next = node;
    return head;
}

int handle_input(char *input, char **parsed_input,
    list parsed_env, list history)
{
    int status = 0;
    char *command_flags = ";<|>";

    if (!is_str_empty(input) && (input != 0)) {
        history = insert_history(history, input);
        if (are_in_str(command_flags, input)) {
            status = handle_command_flags(input, parsed_input,
                parsed_env, history);
        } else {
            parsed_input = str_to_word_array(input, " \t\n");
            status = handle_execs(parsed_input, parsed_env, history);
        }
    }
    return status;
}
