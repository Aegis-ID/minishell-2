/*
** EPITECH PROJECT, 2024
** my_strlen_delim
** File description:
** new func
*/

#include "include/my.h"

int my_strlen_delim(char *str, int start, char delim)
{
    int count;

    for (count = 0; str[start] != '\0'; count++) {
        if (str[start] == delim)
            return count;
        start++;
    }
    return count;
}
