/*
** EPITECH PROJECT, 2024
** is array empty
** File description:
** new_funcs
*/

#include "include/my.h"

int is_array_empty(char **array)
{
    int i = my_arraylen(array) + my_array_strlen(array);

    if (i == 0)
        return 1;
    return 0;
}
