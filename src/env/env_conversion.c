/*
** EPITECH PROJECT, 2024
** minishell
** File description:
** env_conversion
*/

#include "my.h"
#include "lib.h"

list env_to_lists(char **env)
{
    list parsed_env = new_list();

    for (int y = 0; env[y] != 0; y++)
        if (my_strncmp(env[y], "OLDPWD", 6) != 0)
            parsed_env = insert_env(parsed_env, env[y]);
    return parsed_env;
}

char **env_to_array(list parsed_env)
{
    int len = list_len(parsed_env);
    char **converted_env = malloc(sizeof(char *) * (len + 1));

    for (int y = 0; y < len; y++){
        converted_env[y] = parsed_env->raw;
        parsed_env = parsed_env->next;
    }
    converted_env[len] = 0;
    return converted_env;
}

char *env_to_str(list parsed_env, char *pathname)
{
    while (parsed_env != 0) {
        if (my_strcmp(parsed_env->name, pathname) == 0)
            return parsed_env->path;
        parsed_env = parsed_env->next;
    }
    return 0;
}

char *rawline(char *str1, char *str2)
{
    char *insert = 0;
    char *tmp = 0;

    tmp = my_strcat(str1, "=");
    insert = my_strcat(tmp, str2);
    free(tmp);
    return insert;
}
