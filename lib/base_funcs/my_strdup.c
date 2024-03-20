/*
** EPITECH PROJECT, 2024
** my_strdup
** File description:
** base_func
*/

#include "include/my.h"

char *my_strdup(const char *str)
{
    int len = my_strlen(str);
    char *dup = malloc(sizeof(char) * (len + 1));

    for (int x = 0; x < len; x++)
        dup[x] = str[x];
    dup[len] = '\0';
    return dup;
}
