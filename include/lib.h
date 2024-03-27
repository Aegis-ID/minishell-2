/*
** EPITECH PROJECT, 2024
** minishell 1
** File description:
** lib header
*/

#ifndef __LIB__
    #define __LIB__
/*base_funcs*/
void my_putstr(char const *str);
void mini_printf(char const *format, ...);
int my_putchar(char c);
int my_put_nbr(int nb);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int delim);
int my_strlen(char const *str);
char *my_strcpy(char *dest, const char *src);
char *my_strcat(const char *str1, const char *str2);
char *my_strdup(const char *str);
char *my_strndup(char *str, int n);
/*new_funcs*/
void mini_dprintf(int fd, char const *format, ...);
int is_str_empty(char *str);
int is_array_empty(char **array);
int my_strlen_delim(char *str, int start, char delim);
int count_char_in_str(char *str, char c);
int my_arraylen(char **array);
int my_array_strlen(char **array);
int my_readfile(char *filepath);
char **str_to_word_array(char *str, char *delim);

#endif /* !__LIB__ */
