/*
** EPITECH PROJECT, 2024
** minishell
** File description:
** handle commands
** Authorized functions:
** malloc, free, exit, opendir, readdir, closedir,
** getcwd, chdir, fork, stat, lstat, fstat, open, close, getline, strtok,
** strtok_r, read, write, execve, access, isatty, wait, wait-pid, wait3,
** wait4, signal, kill, getpid, strerror, perror, strsignal
*/

#include "my.h"
#include "lib.h"
#include <errno.h>
#include <string.h>
#include <unistd.h>

int exec_pwd_bin(char **parsed_input, list parsed_env)
{
    char *pwd = get_pwd();
    char *tmp = my_strcat(pwd, "/");
    char *command = my_strcat(tmp, parsed_input[0] + 2);
    char **env_array = env_to_array(parsed_env);
    int status = 0;

    status = execve(command, parsed_input, env_array);
    free(pwd);
    free(tmp);
    free(command);
    free_double_char(env_array);
    if (status == -1)
        mini_dprintf(2, "%s: %s\n", strerror(errno));
    return status;
}

int exec_binary(char **parsed_input, list parsed_env)
{
    char **bin_paths = get_bin_paths(parsed_env, "PATH");
    char **env_array = env_to_array(parsed_env);
    char *command = 0;
    int status = 0;

    for (int y = 0; bin_paths[y] != 0; y++) {
        command = my_strcat(bin_paths[y], parsed_input[0]);
        status = execve(command, parsed_input, env_array);
        free(command);
    }
    free_double_char(env_array);
    free_double_char(bin_paths);
    return status;
}
