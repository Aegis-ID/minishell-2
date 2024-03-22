/*
** EPITECH PROJECT, 2024
** Minishell - 1
** File description:
** shell prompt
*/

#include "my.h"
#include "lib.h"
#include <unistd.h>

static void print_dir(void)
{
    size_t size = 4096;
    char *pwd = malloc(sizeof(char) * size);
    int limit = 0;
    int len = 0;

    getcwd(pwd, size);
    limit = count_char_in_str(pwd, '/');
    my_putstr("~/");
    for (int tmp = 0; tmp < limit; len++) {
        if (pwd[len] == '/')
            tmp++;
        if (pwd[len] == '/' && tmp > 3)
            my_putstr("../");
    }
    mini_printf("%s\n", (pwd + len));
    free(pwd);
}

void oh_my_wish(list parsed_env)
{
    char *user = get_list_path(parsed_env, "USER");
    int blue = 34;
    int cyan = 36;
    int check = 0;

    if (user == 0) {
        user = my_strdup("user");
        check = 1;
    }
    mini_printf("\033[1;%dm%s\033[0m", cyan, user);
    mini_printf("@");
    mini_printf("\033[1;%dmminishell-1 \033[0m", blue);
    print_dir();
    mini_printf("\033[1;%dm%% \033[0m", blue);
    if (check)
        free(user);
}
