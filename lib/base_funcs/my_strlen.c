/*
** EPITECH PROJECT, 2023
** day03-06
** File description:
** some return0 functions
*/

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i = i + 1;
    }
    return i;
}
