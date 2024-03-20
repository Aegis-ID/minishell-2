/*
** EPITECH PROJECT, 2024
** minishell 1
** File description:
** my_setenv
*/

#include "include/my.h"

list new_node(char *str)
{
    list node;

    node = malloc(sizeof(*node));
    node->name = my_strndup(str, my_strlen_delim(str, 0, '='));
    node->path = my_strdup(str + (my_strlen_delim(str, 0, '=') + 1));
    node->raw = rawline(node->name, node->path);
    node->next = 0;
    return node;
}

list insert_env(list parsed_env, char *str)
{
    list tmp = parsed_env;

    if (is_empty_list(parsed_env))
        return new_node(str);
    while (tmp->next != 0)
        tmp = tmp->next;
    tmp->next = new_node(str);
    return parsed_env;
}

void replace_env(list parsed_env, char *path, char *str)
{
    if (!check_list_name(parsed_env, path))
        return;
    while (my_strcmp(parsed_env->name, path) != 0)
        parsed_env = parsed_env->next;
    free(parsed_env->path);
    free(parsed_env->raw);
    parsed_env->path = my_strdup(str + (my_strlen_delim(str, 0, '=') + 1));
    parsed_env->raw = rawline(parsed_env->name, parsed_env->path);
    return;
}

static int my_setenv_insert(char **parsed_input, list parsed_env)
{
    int len = my_arraylen(parsed_input);
    char *insert = 0;

    if (len == 2)
        insert = rawline(parsed_input[1], "\0");
    else
        insert = rawline(parsed_input[1], parsed_input[2]);
    if (check_list_name(parsed_env, parsed_input[1]))
        replace_env(parsed_env, parsed_input[1], insert);
    else
        parsed_env = insert_env(parsed_env, insert);
    free(insert);
    return 1;
}

static int is_alphanumeric(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] < 'A' || str[i] > 'Z') &&
            (str[i] < 'a' || str[i] > 'z') &&
            (str[i] < '0' || str[i] > '9') &&
            str[i] != '_')
            return 0;
    }
    return 1;
}

static int is_letter(char c)
{
    if ((c < 'A' || c > 'Z') &&
        (c < 'a' || c > 'z') &&
        c != '_')
        return 0;
    return 1;
}

static int is_variable_name_valid(char **parsed_input)
{
    if (!is_letter(parsed_input[1][0]))
        mini_dprintf(2,
        "%s: Variable name must begin with a letter.\n",
        parsed_input[0]);
    if (!is_alphanumeric(parsed_input[1] + 1))
        mini_dprintf(2,
        "%s: Variable name must contain alphanumeric characters.\n",
        parsed_input[0]);
    return 1;
}

int my_setenv(char **parsed_input, list parsed_env)
{
    int len = my_arraylen(parsed_input);

    if (len == 1)
        return my_env(parsed_env);
    if (len >= 2) {
        if (!is_letter(parsed_input[1][0]) ||
            !is_alphanumeric(parsed_input[1] + 1))
            return is_variable_name_valid(parsed_input);
    }
    if (len > 3) {
        mini_dprintf(2, "%s: Too many arguments.\n", parsed_input[0]);
        return 1;
    }
    return my_setenv_insert(parsed_input, parsed_env);
}
