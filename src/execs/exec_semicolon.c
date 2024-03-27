/*
** EPITECH PROJECT, 2024
** minishell
** File description:
** semicolon
*/

#include "lib.h"
#include "my.h"

int is_in_str(char *str, char c)
{
	for (int i = 0; str[i] != '\0'; i++)
		if (str[i] == c)
			return 1;
	return 0;
}

int is_in_array(char **array, char c)
{
    for (int i = 0; array[i] != 0; i++)
		if (is_in_str(array[i], c))
            return 1;
    return 0;
}

char **reparse_input(char **parsed_input, int begin, char delim)
{
	int size = 0;
	char **reparsed_input = 0;

	for (int y = begin; parsed_input[y] != 0; y++) {
		if (is_in_str(parsed_input[y], delim))
			break;
		size++;
	}
	reparsed_input = malloc(sizeof(char *) * (size + 1));
	for (int i = begin; i < size; i++)
		reparsed_input[i] = my_strdup(parsed_input[i]);
	reparsed_input[size] = 0;
	return reparsed_input;
}

int exec_semicolon(char **parsed_input, list parsed_env)
{
	int status = 0;
	int begin = 0;
	char **reparsed_input = 0;

	for (int i = 0; parsed_input[i] != 0; i++) {
		if (is_in_str(parsed_input[i], ';')) {
			reparsed_input = reparse_input(parsed_input, begin, ';');
			status = exec_binary(reparsed_input, parsed_env);
			begin = i + 1;
		}
	}
    return status;
}
