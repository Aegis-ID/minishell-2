/*
** EPITECH PROJECT, 2024
** is in array
** File description:
** new funcs
*/

#include "lib.h"

int is_in_array(char **array, char c)
{
    for (int i = 0; array[i] != 0; i++)
        if (is_in_str(c, array[i]))
            return 1;
    return 0;
}
