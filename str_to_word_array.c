/*
** EPITECH PROJECT, 2024
** str_to_word_array
** File description:
** new func
*/

#include "lib.h"
#include <stdlib.h>
#include <stdio.h>

static int is_in_str(char *str, char c)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == c)
            return 1;
    return 0;
}

static int get_str_size(char *str, char *delim, int begin)
{
    int size = 0;

    for (int i = begin; str[i] != '\0'; i++) {
        if (is_in_str(delim, str[i]))
            return size;
        size++;
    }
    return size;
}

static int get_delim_size(char *str, char *delim, int begin)
{
    int size = 0;

    for (int i = begin; str[i] != '\0'; i++) {
        if (!is_in_str(delim, str[i]))
            return size;
        size++;
    }
    return size;
}

char **str_to_word_array(char *str, char *delim)
{
    int size = 0;
    int begin = 0;
    int str_size = 0;
    char **array = 0;

    for (int i = 0; str[i] != '\0'; i++)
        if (is_in_str(delim, str[i]))
            size++;
    array = malloc(sizeof(char *) * (size + 1));
    for (int y = 0; y < size; y++) {
        str_size = get_str_size(str, delim, begin);
        if (!is_in_str(delim, str[begin])) {
            array[y] = my_strndup(str + begin, str_size);
            begin += str_size + 1;
        } else
            begin += get_delim_size(str, delim, begin);
    }
    array[size] = 0;
    return array;
}

int main(int argc, char **argv)
{
    char **tkt = 0;

    if (argc != 3)
        return 84;
    tkt = str_to_word_array(argv[1], argv[2]);
    for (int i = 0; tkt[i] != 0; i++)
        printf("%s\n", tkt[i]);
    return 0;
}
