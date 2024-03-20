/*
** EPITECH PROJECT, 2024
** my_strcat.c
** File description:
** base func
*/

#include "include/my.h"

char *my_strcat(const char *str1, const char *str2)
{
    int str_sum = my_strlen(str1) + my_strlen(str2);
    char *str = malloc(sizeof(char) * (str_sum + 1));
    int len = 0;

    for (int x = 0; str1[x] != '\0'; x++) {
        str[len] = str1[x];
        len++;
    }
    for (int k = 0; str2[k] != '\0'; k++) {
        str[len] = str2[k];
        len++;
    }
    str[str_sum] = '\0';
    return str;
}
