/*
** EPITECH PROJECT, 2023
** display stdargs
** File description:
** part C
*/

#include <stdarg.h>
#include "include/my.h"

static void b_cases(const char *format, va_list lptr, int k)
{
    char *s;
    int d;

    switch (format[k]) {
    case 's':
        s = (va_arg(lptr, char *));
        my_putstr(s);
        break;
    case 'd':
        d = (va_arg(lptr, int));
        my_put_nbr(d);
        break;
    }
}

static void s_cases(const char *format, va_list lptr, int k)
{
    int i;
    char c;

    switch (format[k]) {
    case 'c':
        c = (char) va_arg(lptr, int);
        my_putchar(c);
        break;
    case 'i':
        i = (va_arg(lptr, int));
        my_put_nbr(i);
        break;
    case '%':
        my_putchar('%');
        break;
    }
}

void mini_printf(char const *format, ...)
{
    va_list lptr;
    int k = 0;

    va_start(lptr, format);
    for (k = 0; format[k] != '\0'; k++) {
        if (format[k] == '%') {
            k++;
            b_cases(format, lptr, k);
            s_cases(format, lptr, k);
            va_end(lptr);
        } else {
            my_putchar(format[k]);
        }
    }
}
