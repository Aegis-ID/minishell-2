##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## A Lib Makefile
##

NAME		=	mylib.a

INCLUDE 	=	../

SRC		=	base_funcs/mini_printf.c		\
			base_funcs/my_put_nbr.c 		\
			base_funcs/my_putchar.c 		\
			base_funcs/my_putstr.c 			\
			base_funcs/my_strcmp.c 			\
			base_funcs/my_strncmp.c			\
			base_funcs/my_strlen.c 			\
			base_funcs/my_strcat.c			\
			base_funcs/my_strcpy.c 			\
			base_funcs/my_strdup.c 			\
			base_funcs/my_strndup.c 		\
			new_funcs/mini_dprintf.c		\
			new_funcs/my_strlen_delim.c 	\
			new_funcs/count_char_in_str.c 	\
			new_funcs/str_to_word_array.c 	\
			new_funcs/linked_lists.c 		\
			new_funcs/my_arraylen.c 		\
			new_funcs/my_array_strlen.c 	\
			new_funcs/my_readfile.c 		\
			new_funcs/is_str_empty.c 		\
			new_funcs/is_array_empty.c		\

CC		?=	gcc

CPPFLAGS	=	-W -Wall -Wextra -Werror -I $(INCLUDE)

CFLAGS 		=	-W -Wall -Wextra -Werror

OBJ		=	$(SRC:.c=.o)

all: $(NAME) clean

$(NAME):	$(OBJ)
		ar rcs $(NAME) $(OBJ) && cp $(NAME) ../

clean:
		rm -f $(OBJ) 	\
		rm *log			\

fclean: clean
		rm -f $(NAME)		\
		rm -f ../$(NAME)	\

re: fclean all

.PHONY: all clean fclean re
