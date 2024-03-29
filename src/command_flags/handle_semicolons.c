/*
** EPITECH PROJECT, 2024
** handle semicolons
** File description:
** minishell-2
*/

#include "my.h"
#include "lib.h"


static int get_begin(int position, char *input, char *delim)
{
    int begin = position;

    while (is_in_str(input[begin], delim))
        begin++;
    return begin;
}

static char **get_command(char *input)
{
    int len = 0;
    int begin = 0;
    int size = count_char_in_str(input, ';') + 1;
    char **command = malloc(sizeof(char *) * (size + 1));

    for (int i = 0; input[i] != '\0'; i++)
        if (input[i] == ';') {
            command[len] = my_strndup(input + begin, i - begin);
            begin = get_begin(i, input, ";");
            len++;
        }
    command[len] = my_strndup(input + begin, my_strlen(input) - begin);
    command[size] = 0;
    return command;
}

int handle_semicolons(char *input, char **parsed_input,
    list parsed_env, list history)
{
    int status = 0;
    char **command = get_command(input);

    for (int y = 0; command[y] != 0; y++) {
        parsed_input = str_to_word_array(command[y], "\t\n ;");
        status = handle_execs(parsed_input, parsed_env, history);
    }
    free_double_char(command);
    return status;
}
