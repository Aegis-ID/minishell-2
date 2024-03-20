/*
** EPITECH PROJECT, 2024
** count char in str
** File description:
** new func
*/

#include "include/my.h"

int count_char_in_str(char *str, char c)
{
    int count = 0;

    for (int y = 0; str[y] != '\0'; y++) {
        if (str[y] == c)
            count++;
    }
    return count;
}
