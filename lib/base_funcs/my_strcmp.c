/*
** EPITECH PROJECT, 2023
** day03-06
** File description:
** some return0 functions
*/

#include "include/my.h"

int my_strcmp(char const *s1, char const *s2)
{
    int len = my_strlen(s1);

    if (len < my_strlen(s2))
        len = my_strlen(s2);
    for (int i = 0; i < len; i++) {
        if (s1[i] < s2[i])
            return (my_strlen(s1) * -1);
        if (s1[i] > s2[i])
            return my_strlen(s1);
    }
    return 0;
}
