/*
** EPITECH PROJECT, 2024
** header
** File description:
** my.h
*/

#ifndef __MY_H__
    #define __MY_H__
    #include <stdlib.h>
    #include <string.h>
    #include <unistd.h>
    #include <sys/wait.h>
    #include <stdio.h>
    #include <signal.h>
    #include <errno.h>
    #include "lib.h"
    #include "linked_lists.h"

/*shell prompt*/
void oh_my_wish(list parsed_env);
/*handle_input*/
int handle_input(char *input, char **parsed_input,
    list parsed_env, list command);
/*memory_management*/
void free_node(list node);
void free_parsed_env(list parsed_env);
void free_command(list command);
void free_double_char(char **str);
/*exec_builtins*/
int is_builtins_funcs(char *str);
int exec_builtins(char **parsed_input, list parsed_env, list command);
/*my_exit*/
void my_exit(char *input, list parsed_env, list command, int status);
/*env builtins*/
int my_env(list parsed_env);
int my_setenv(char **parsed_input, list parsed_env);
int my_unsetenv(char **parsed_input, list parsed_env);
/*my_cd*/
char *get_pwd(void);
int my_cd(char **parsed_input, list parsed_env);
/*exec_env*/
int exec_env_bin(char **parsed_input, list parsed_env);
/*env_conversion*/
char *rawline(char *str1, char *str2);
char *env_to_str(list parsed_env, char *pathname);
char **env_to_array(list parsed_env);
list env_to_lists(char **env);
/*env_info*/
int check_list_name(list parsed_env, char *name);
char *get_list_raw(list parsed_env, char *pathname);
char *get_list_path(list parsed_env, char *pathname);
char **get_bin_paths(list parsed_env, char *pathname);
/*env_modifiers*/
list insert_env(list parsed_env, char *str);
void replace_env(list parsed_env, char *path, char *str);

#endif
