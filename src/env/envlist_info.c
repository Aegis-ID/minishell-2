/*
** EPITECH PROJECT, 2024
** minishell
** File description:
** get list info
*/

#include "include/my.h"

int check_list_name(list parsed_env, char *name)
{
    while (parsed_env != 0) {
        if (my_strcmp(parsed_env->name, name) == 0)
            return 1;
        parsed_env = parsed_env->next;
    }
    return 0;
}

char *get_list_raw(list parsed_env, char *pathname)
{
    if (!check_list_name(parsed_env, pathname))
        return 0;
    while (parsed_env != 0) {
        if (my_strcmp(parsed_env->name, pathname) == 0)
            return parsed_env->raw;
        parsed_env = parsed_env->next;
    }
    return 0;
}

char *get_list_path(list parsed_env, char *pathname)
{
    if (!check_list_name(parsed_env, pathname))
        return 0;
    while (parsed_env != 0) {
        if (my_strcmp(parsed_env->name, pathname) == 0)
            return parsed_env->path;
        parsed_env = parsed_env->next;
    }
    return 0;
}

static char **parse_bin_paths(char *str, int len)
{
    int max_y = count_char_in_str(str, ':') + 1;
    char **map = malloc(sizeof(char *) * (max_y + 2));
    int limit = 0;

    for (int y = 0; y < max_y; y++) {
        if (y < max_y - 1)
            limit = my_strlen_delim(str, len, ':');
        else
            limit = my_strlen_delim(str, len, '\0');
        map[y] = malloc(sizeof(char) * (limit + 2));
        for (int x = 0; x < limit; x++) {
            map[y][x] = str[len];
            len++;
        }
        map[y][limit] = '/';
        map[y][limit + 1] = '\0';
        len++;
    }
    map[max_y] = 0;
    return map;
}

char **get_bin_paths(list parsed_env, char *pathname)
{
    while (parsed_env != 0) {
        if (my_strcmp(pathname, parsed_env->name) == 0)
            return parse_bin_paths(parsed_env->path, 0);
        parsed_env = parsed_env->next;
    }
    return 0;
}
