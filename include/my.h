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
/*handle_input*/
int handle_input(char *input, char **parsed_input, list parsed_env,
    list history);
int exec_input(char **parsed_input, list parsed_env, list history);
/*memory_management*/
void free_node(list node);
void free_parsed_env(list parsed_env);
void free_history(list history);
void free_double_char(char **str);
/*exec_builtins*/
int is_builtins_funcs(char *str);
int exec_builtins(char **parsed_input, list parsed_env, list history);
/*my_exit*/
void my_exit(char *input, list parsed_env, list history, int status);
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
/*exec_bin*/
int exec_pwd_bin(char **parsed_input, list parsed_env);
int exec_binary(char **parsed_input, list parsed_env);
int exec_pipe(char **parsed_input, list parsed_env);
/*exec_pipe*/
int check_pipe(char **parsed_input);
/*exec_semicolon*/
int exec_semicolon(char **parsed_input, list parsed_env);
#endif
