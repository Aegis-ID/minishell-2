/*
** EPITECH PROJECT, 2023
** day03-06
** File description:
** Put numbers
*/

#include "include/my.h"

int my_put_nbr(int nb)
{
    int i = 0;

    if (nb < 0) {
        write(1, "-", 1);
        nb = nb * (-1);
    }
    if (nb >= 0 && nb <= 9) {
        my_putchar(nb + 48);
    } else {
        i = (nb % 10);
        nb = (nb / 10);
        my_put_nbr(nb);
        my_putchar(i + 48);
    }
    return nb;
}
