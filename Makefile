##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## A Base Makefile
##

NAME		=	mysh

INCLUDE 	=	./

SUBDIRS		=	lib/

SRC		=	src/main.c							\
			src/builtins/my_env.c 				\
			src/builtins/my_setenv.c 			\
			src/builtins/my_unsetenv.c 			\
			src/builtins/my_cd.c 				\
			src/builtins/my_exit.c 				\
			src/env/env_conversion.c 			\
			src/env/envlist_info.c 				\
			src/memory_management.c 			\
			src/handle_input.c 					\
			src/exec_env_bin.c 					\
			src/exec_builtins.c					\
			src/shell_prompt.c 					\

CC		?=	gcc

CHECKLEAKS	=	-fsanitize=address

CPPFLAGS	=	-Wall -Wextra -I $(INCLUDE)

CFLAGS 		=	-Wall -Wextra

OBJ		=	$(SRC:.c=.o)

all: $(NAME) clean

$(NAME):	$(OBJ)
		$(MAKE) -C $(SUBDIRS) all
		$(CC) -o $(NAME) $(OBJ) mylib.a

clean:
		$(MAKE) -C $(SUBDIRS) clean
		rm -f $(OBJ)
		rm -f *log

fclean: clean
		$(MAKE) -C $(SUBDIRS) fclean
		rm -f $(NAME)

re: fclean all
	$(MAKE) -C $(SUBDIRS) re

.PHONY: all clean fclean re
