/*
** EPITECH PROJECT, 2024
** linked lists
** File description:
** new funcs
*/

#ifndef __LINKED_LISTS__
    #define __LINKED_LISTS__
    #include <stddef.h>

typedef enum {
    false,
    true
}my_bool;

typedef struct list {
    char *raw;
    char *name;
    char *path;
    struct list *next;
}*list;

list new_list(void);
my_bool is_empty_list(list li);
int list_len(list li);

#endif /* !__LINKED_LISTS__ */
