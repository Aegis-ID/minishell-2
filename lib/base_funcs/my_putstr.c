/*
** EPITECH PROJECT, 2023
** day03-06
** File description:
** some return0 functions
*/

#include <unistd.h>

void my_putstr(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        write(1, &str[i], 1);
    }
}
