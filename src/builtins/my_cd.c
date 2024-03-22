/*
** EPITECH PROJECT, 2024
** minishell
** File description:
** my_cd.c
*/

#include "my.h"
#include "lib.h"
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>

char *get_pwd(void)
{
    size_t size = 4096;
    char *pwd = malloc(sizeof(char) * size);

    getcwd(pwd, size);
    return pwd;
}

static void update_pwd(list parsed_env, char *pwd)
{
    size_t size = 4096;
    char *old_pwd = rawline("OLDPWD", pwd);
    char *new_pwd = malloc(sizeof(char) * size);
    char *tmp = 0;

    if (check_list_name(parsed_env, "OLDPWD"))
        replace_env(parsed_env, "OLDPWD", old_pwd);
    else
        parsed_env = insert_env(parsed_env, old_pwd);
    getcwd(new_pwd, size);
    tmp = rawline("PWD", new_pwd);
    if (check_list_name(parsed_env, "PWD"))
        replace_env(parsed_env, "PWD", tmp);
    else
        parsed_env = insert_env(parsed_env, new_pwd);
    free(new_pwd);
    free(old_pwd);
    free(tmp);
}

static int home_case(list parsed_env)
{
    char *home = get_list_path(parsed_env, "HOME");
    char *pwd = 0;

    if (home == 0) {
        mini_dprintf(2, "cd: No home directory.\n");
        return 1;
    }
    pwd = get_pwd();
    chdir(home);
    update_pwd(parsed_env, pwd);
    free(pwd);
    return 0;
}

static int union_case(list parsed_env)
{
    char *old_pwd = get_list_path(parsed_env, "OLDPWD");
    char *pwd = 0;

    if (old_pwd == 0) {
        mini_dprintf(2, ": No such file or directory.\n");
        return 1;
    }
    pwd = get_pwd();
    chdir(old_pwd);
    mini_printf("~%s\n", old_pwd);
    update_pwd(parsed_env, pwd);
    free(pwd);
    return 0;
}

static int basic_case(char **parsed_input, list parsed_env)
{
    int status = 0;
    char *pwd = 0;

    if (my_arraylen(parsed_input) > 2) {
        mini_dprintf(2, "cd: Too many arguments.\n");
        return 1;
    }
    status = chdir(parsed_input[1]);
    if (status == -1) {
        mini_dprintf(2, "%s: %s.\n", parsed_input[1], strerror(errno));
        return 1;
    }
    pwd = get_pwd();
    update_pwd(parsed_env, pwd);
    free(pwd);
    return status;
}

int my_cd(char **parsed_input, list parsed_env)
{
    int len = my_arraylen(parsed_input);

    if (len == 1 && my_strcmp("cd", parsed_input[0]) == 0)
        return home_case(parsed_env);
    if (len == 2 && my_strcmp(parsed_input[1], "-") == 0)
        return union_case(parsed_env);
    if (len >= 2)
        return basic_case(parsed_input, parsed_env);
    return 1;
}
