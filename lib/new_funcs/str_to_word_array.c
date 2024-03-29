/*
** EPITECH PROJECT, 2024
** str_to_word_array
** File description:
** new func
*/

#include "lib.h"
#include <stdlib.h>

static int get_array_size(char *str, char *delim)
{
    int size = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (!is_in_str(str[i], delim) && is_in_str(str[i + 1], delim))
            size++;
        if (!is_in_str(str[i], delim) && (str[i + 1] == '\0'))
            size++;
    }
    return size;
}

static int get_str_size(char *str, char *delim, int begin)
{
    int size = 0;

    for (int i = begin; str[i] != '\0'; i++) {
        if (is_in_str(str[i], delim))
            return size;
        size++;
    }
    return size;
}

static void check_begin(char *str, char *delim, int *begin)
{
    int size = my_strlen(str);

    if (is_in_str(str[*begin], delim))
        while (is_in_str(str[*begin], delim) && *begin < size)
            *begin += 1;
    return;
}

char **str_to_word_array(char *str, char *delim)
{
    int size = get_array_size(str, delim);
    char **array = malloc(sizeof(char *) * (size + 1));
    int begin = 0;
    int str_size = 0;

    for (int y = 0; y < size; y++) {
        check_begin(str, delim, &begin);
        str_size = get_str_size(str, delim, begin);
        array[y] = my_strndup(str + begin, str_size);
        begin += str_size + 1;
    }
    array[size] = 0;
    return array;
}
