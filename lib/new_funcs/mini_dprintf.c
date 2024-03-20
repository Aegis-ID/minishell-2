/*
** EPITECH PROJECT, 2023
** display stdargs
** File description:
** part C
*/

#include <stdarg.h>
#include <unistd.h>
#include "include/my.h"

int my_dputchar(int fd, char c)
{
    return write(fd, &c, 1);
}

void my_dputstr(int fd, char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        write(fd, &str[i], 1);
}

void my_dput_nbr(int fd, int nb)
{
    int i = 0;

    if (nb < 0) {
        my_dputchar(fd, '-');
        nb *= (-1);
    }
    if (nb >= 0 && nb <= 9) {
        my_dputchar(fd, nb + 48);
    } else {
        i = (nb % 10);
        nb = (nb / 10);
        my_dput_nbr(fd, nb);
        my_dputchar(fd, i + 48);
    }
}

static void char_cases(int fd, const char *format, va_list lptr, int k)
{
    char c;
    char *s;

    switch (format[k]) {
    case 'c':
        c = (char) va_arg(lptr, int);
        my_dputchar(fd, c);
        break;
    case 's':
        s = (va_arg(lptr, char *));
        my_dputstr(fd, s);
        break;
    }
}

static void digit_cases(int fd, const char *format, va_list lptr, int k)
{
    int d;
    int i;

    switch (format[k]) {
    case 'd':
        d = (va_arg(lptr, int));
        my_dput_nbr(fd, d);
        break;
    case 'i':
        i = (va_arg(lptr, int));
        my_dput_nbr(fd, i);
        break;
    case '%':
        my_dputchar(fd, '%');
        break;
    }
}

void mini_dprintf(int fd, char const *format, ...)
{
    va_list lptr;
    int k = 0;

    va_start(lptr, format);
    for (k = 0; format[k] != '\0'; k++) {
        if (format[k] == '%') {
            k++;
            char_cases(fd, format, lptr, k);
            digit_cases(fd, format, lptr, k);
            va_end(lptr);
        } else
            my_dputchar(fd, format[k]);
    }
    return;
}
