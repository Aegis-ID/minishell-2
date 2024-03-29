/*
** EPITECH PROJECT, 2024
** header
** File description:
** my.h
*/

#ifndef __MY_H__
    #define __MY_H__
    #include "linked_lists.h"
    #include <stdlib.h>

/*shell prompt*/
void oh_my_wish(list parsed_env, int status);
/*command handling*/
int handle_input(char *input, char **p_input, list p_env, list hist);
int handle_execs(char **parsed_input, list parsed_env, list hist);
int handle_command_flags(char *input, char **p_input,
    list p_env, list hist);
/*exec_builtins*/
int is_builtins_funcs(char *str);
int exec_builtins(char **parsed_input, list parsed_env, list history);
/*exec_bin*/
int exec_pwd_bin(char **parsed_input, list parsed_env);
int exec_binary(char **parsed_input, list parsed_env);
/*command_flags*/
int handle_semicolons(char *input, char **parsed_input,
    list parsed_env, list history);
int handle_pipe(char *input, char **parsed_input,
    list parsed_env, list history);
/*builtins*/
void my_exit(char *input, list parsed_env, list history, int status);
char *get_pwd(void);
int my_cd(char **parsed_input, list parsed_env);
int my_env(list parsed_env);
int my_setenv(char **parsed_input, list parsed_env);
int my_unsetenv(char **parsed_input, list parsed_env);
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
/*memory_management*/
void free_node(list node);
void free_parsed_env(list parsed_env);
void free_history(list history);
void free_double_char(char **str);
#endif
