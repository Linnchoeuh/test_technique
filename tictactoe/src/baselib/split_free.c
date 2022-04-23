/**
 ** @file term_split_free.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "baselib.h"

void split_free(char **splitted)
{
	size_t i;

	if (splitted == NULL)
		return;
	i = 0;
	while (splitted[i] != NULL)
	{
		free(splitted[i]);
		++i;
	}
	free(splitted);
}

