/*
** EPITECH PROJECT, 2024
** handle command flags
** File description:
** minishell-2
*/

#include "my.h"
#include "lib.h"
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>

static int exec_pipe(char **command1, char **command2,
    list parsed_env, list history)
{
	int fd[2];
	int status = 0;
	pid_t pid;
    int save = dup(STDIN_FILENO);

	pipe(fd);
	pid = fork();
	if (pid == 0) {
		dup2(fd[1], STDOUT_FILENO);
        status = handle_execs(command1, parsed_env, history);
        free_double_char(command1);
        exit(1);
	} else {
        close(fd[1]);
        dup2(fd[0], STDIN_FILENO);
        status = handle_execs(command2, parsed_env, history);
        dup2(save, STDIN_FILENO);
        free_double_char(command2);
        close(fd[0]);
        waitpid(-1, &status, 0);
    }
    return status;
}

int handle_pipe(char *input, char **parsed_input,
    list parsed_env, list history)
{
    int status = 0;
    int size = 0;
    char *tokens = "\t\n ";
    char **command1 = {0};
    char **command2 = {0};

    parsed_input = str_to_word_array(input, "|");
    size = my_arraylen(parsed_input);
    for (int y = 0; y < size - 1; y++) {
        command1 = str_to_word_array(parsed_input[y], tokens);
        command2 = str_to_word_array(parsed_input[y + 1], tokens);
        status = exec_pipe(command1, command2, parsed_env, history);
    }
    return status;
}
