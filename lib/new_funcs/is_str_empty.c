/*
** EPITECH PROJECT, 2024
** is str empty
** File description:
** new func
*/

int is_str_empty(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] > 32 && str[i] < 127)
            return 0;
    }
    return 1;
}
