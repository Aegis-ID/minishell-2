/*
** EPITECH PROJECT, 2024
** my_aclen
** File description:
** new func
*/

#include "include/my.h"

int my_arraylen(char **array)
{
    int len = 0;

    for (; array[len] != 0; len++);
    return len;
}
