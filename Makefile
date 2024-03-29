##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## A Base Makefile
##

NAME		=	mysh

INCLUDE 	=	./include/

SUBDIRS		=	lib/

SRC		=	src/main.c	\
			src/env/env_conversion.c	\
			src/env/envlist_info.c	\
			src/execs/exec_builtins.c	\
			src/execs/exec_bin.c	\
			src/builtins/my_env.c	\
			src/builtins/my_setenv.c	\
			src/builtins/my_unsetenv.c 	\
			src/builtins/my_cd.c	\
			src/builtins/my_exit.c	\
			src/command_flags/handle_semicolons.c	\
			src/handle_input.c	\
			src/handle_execs.c	\
			src/handle_command_flags.c	\
			src/memory_management.c	\
			src/shell_prompt.c	\

CC		?=	gcc

LIBRARIES	=	mylib.a

CPPFLAGS	=	-iquote $(INCLUDE)

CFLAGS 		=	-Wall -Wextra

DEBUG		=	-g

OBJ		=	$(SRC:.c=.o)

all: $(NAME) clean

$(NAME):	$(OBJ)
		$(MAKE) -C $(SUBDIRS) all
		$(CC) -o $(NAME) $(OBJ) $(LIBRARIES)

clean:
		$(MAKE) -C $(SUBDIRS) clean
		rm -f $(OBJ)
		rm -f *log

fclean: clean
		$(MAKE) -C $(SUBDIRS) fclean
		rm -f $(NAME)

re: fclean all
	$(MAKE) clean
	$(MAKE) -C $(SUBDIRS) clean

debug: CPPFLAGS += $(DEBUG)
debug: CFLAGS += $(DEBUG)
debug:	$(OBJ)
		$(MAKE) -C $(SUBDIRS) debug
		$(CC) -o $(NAME) $(OBJ) $(LIBRARIES)
		$(MAKE) clean

.PHONY: all clean fclean re debug
