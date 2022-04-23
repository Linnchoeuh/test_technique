/**
 ** @file get_entry.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "entry_reader.h"

char **get_entry(char *entry_header)
{
	char *command;
	char **splitted_command;

	std_fputs(STDOUT_FILENO, entry_header);
	if ((command = read_entry()) == NULL)
		return (NULL);
	splitted_command = split_str(command, ' ');
	free(command);
	return (splitted_command);
}

