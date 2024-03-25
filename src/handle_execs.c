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
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

static void check_errors(char **parsed_input, pid_t pid, int *status)
{
    if (pid == 0 || pid < 0)
        exit(1);
    else
        waitpid(pid, status, 0);
    if (*status == 139 || *status == 11)
        mini_dprintf(2, "Segmentation fault\n");
    if (*status == -1 || *status == 256) {
        mini_dprintf(2, "%s: Command not found.\n", parsed_input[0]);
        *status = 1;
    }
}

int exec_env_bin(char **parsed_input, list parsed_env)
{
    int status = 0;
    pid_t pid = fork();

    if (pid == 0) {
        if (my_strncmp(parsed_input[0], "./", 2) == 0 &&
            my_strlen(parsed_input[0]) > 2)
            status = exec_pwd_bin(parsed_input, parsed_env);
        if (check_pipe(parsed_input))
            status = exec_pipe(parsed_input, parsed_env);
        if (check_list_name(parsed_env, "PATH"))
            status = exec_binary(parsed_input, parsed_env);
    }
    check_errors(parsed_input, pid, &status);
    return status;
}
