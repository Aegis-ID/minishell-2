/*
** EPITECH PROJECT, 2024
** Minishell - 2
** File description:
** main
** Authorized functions:
** malloc, free, exit, opendir, readdir, closedir,
** getcwd, chdir, fork, stat, lstat, fstat, open, close, getline, strtok,
** strtok_r, read, write, execve, access, isatty, wait, wait-pid, wait3,
** wait4, signal, kill, getpid, strerror, perror, strsignal, pipe, dup, dup2
*/

#include "my.h"
#include "lib.h"
#include <unistd.h>
#include <stdio.h>

static char **generate_env(void)
{
    size_t size = 4096;
    int row = 2;
    char *pwd = malloc(sizeof(char) * size);
    char **env = malloc(sizeof(char *) * (row +1));

    getcwd(pwd, size);
    env[0] = my_strdup(pwd);
    env[1] = my_strdup("PATH=/sbin:/bin:/usr/bin:/usr/sbin");
    env[2] = 0;
    free(pwd);
    return env;
}

int minishell(char **env)
{
    size_t size = 0;
    int status = 0;
    int exit_status = 0;
    char *input = 0;
    char **parsed_input = 0;
    list parsed_env = env_to_lists(env);
    list command = new_list();

    while (1) {
        oh_my_wish(parsed_env, status);
        exit_status = getline(&input, &size, stdin);
        if (exit_status == -1 || my_strcmp(input, "exit\n") == 0)
            my_exit(input, parsed_env, command, status);
        status = handle_input(input, parsed_input, parsed_env, command);
    }
    return status;
}

int main(int argc, char **argv, char **env)
{
    if (argc == 1) {
        if (is_array_empty(env))
            env = generate_env();
        return minishell(env);
    }
    if (argc == 2 && my_strcmp(argv[1], "-h") == 0) {
        my_readfile("readme.txt");
        return 0;
    }
    return 84;
}
