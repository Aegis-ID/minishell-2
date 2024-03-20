/*
** EPITECH PROJECT, 2024
** linked lists
** File description:
** new funcs
*/

#include "include/linked_lists.h"

list new_list(void)
{
    return NULL;
}

my_bool is_empty_list(list li)
{
    if (li == NULL)
        return true;
    return false;
}

int list_len(list li)
{
    int size = 0;

    if (!is_empty_list(li)) {
        for (; li != NULL; ++size)
            li = li->next;
    }
    return size;
}
