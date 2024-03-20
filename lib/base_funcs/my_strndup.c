/*
** EPITECH PROJECT, 2024
** my_strndup
** File description:
** base_func
*/

#include "include/my.h"

char *my_strndup(char *str, int n)
{
    int len = n;
    char *dup = malloc(sizeof(char) * (len + 1));

    for (int x = 0; x < len; x++)
        dup[x] = str[x];
    dup[len] = '\0';
    return dup;
}
