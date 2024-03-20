/*
** EPITECH PROJECT, 2024
** array len
** File description:
** new func
*/

#include "include/my.h"

int my_array_strlen(char **array)
{
    int count = 0;

    for (int y = 0; array[y] != 0; y++)
        count += my_strlen(array[y]);
    return count;
}
