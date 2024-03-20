/*
** EPITECH PROJECT, 2024
** my putstr error
** File description:
** new func
*/

#include <unistd.h>

void my_putstr_error(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        write(2, &str[i], 1);
}
