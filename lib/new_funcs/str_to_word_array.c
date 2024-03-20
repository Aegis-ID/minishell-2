/*
** EPITECH PROJECT, 2024
** str_to_word_array
** File description:
** new func
*/

#include "include/my.h"

char **str_to_word_array(char *str, int len, char delim)
{
    int max_y = count_char_in_str(str, delim) + 1;
    char **map = malloc(sizeof(char *) * (max_y + 1));
    int limit = 0;

    for (int y = 0; y < max_y; y++) {
        if (y < max_y - 1)
            limit = my_strlen_delim(str, len, delim);
        else
            limit = my_strlen_delim(str, len, '\0');
        map[y] = malloc(sizeof(char) * (limit + 1));
        for (int x = 0; x < limit; x++) {
            map[y][x] = str[len];
            len++;
        }
        map[y][limit] = '\0';
        len++;
    }
    map[max_y] = 0;
    return map;
}
