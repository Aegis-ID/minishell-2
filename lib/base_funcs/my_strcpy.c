/*
** EPITECH PROJECT, 2023
** day03-06
** File description:
** some return0 functions
*/

char *my_strcpy(char *dest, const char *src)
{
    char *save = dest;

    while (*src != '\0') {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
    return save;
}
