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

#include "include/my.h"

static void exec_pwd_bin(char **parsed_input, list parsed_env)
{
    char *pwd = get_pwd();
    char *tmp = my_strcat(pwd, "/");
    char *command = my_strcat(tmp, parsed_input[0] + 2);
    char **env_array = env_to_array(parsed_env);
    int status = 0;

    printf("%s\n", command);
    status = execve(command, parsed_input, env_array);
    free(pwd);
    free(tmp);
    free(command);
    free_double_char(env_array);
    if (status == -1)
        mini_dprintf("%s: %s\n", strerror(errno));
}

static void exec_binary(char **parsed_input, list parsed_env)
{
    char **bin_paths = get_bin_paths(parsed_env, "PATH");
    char **env_array = env_to_array(parsed_env);
    char *command = 0;

    for (int y = 0; bin_paths[y] != 0; y++) {
        command = my_strcat(bin_paths[y], parsed_input[0]);
        execve(command, parsed_input, env_array);
        free(command);
    }
    free_double_char(env_array);
    free_double_char(bin_paths);
}

static void check_errors(char **parsed_input, int status, int pid)
{
    if (status == 139 || status == 11)
        mini_dprintf(2, "Segmentation fault\n");
    if (pid == 0 || pid < 0) {
        mini_dprintf(2, "%s: Command not found.\n", parsed_input[0]);
        exit(1);
    }
}

int exec_env_bin(char **parsed_input, list parsed_env)
{
    int status = 0;
    int pid = fork();

    if (pid == 0) {
        if (my_strncmp(parsed_input[0], "./", 2) == 0 &&
            my_strlen(parsed_input[0]) > 2)
            exec_pwd_bin(parsed_input, parsed_env);
        if (check_list_name(parsed_env, "PATH"))
            exec_binary(parsed_input, parsed_env);
        else
            mini_dprintf(2, "TERM environment variable not set.\n");
    }
    waitpid(pid, &status, 0);
    check_errors(parsed_input, status, pid);
    return status;
}
