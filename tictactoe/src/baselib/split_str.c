/**
 ** @file term_split_str.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "baselib.h"

#define MEM_FAIL "Memory allocation failed.\n"

static size_t count_bloc(char *str,
						 char parser)
{
	bool   detect;
	size_t i;
	size_t occurence;

	i = 0;
	detect = true;
	occurence = 1;
	while (str[i] != '\0')
	{
		if (str[i] == parser)
			detect = true;
		else if (detect)
		{
			detect = false;
			occurence++;
		}
		i++;
	}
	return (occurence);
}

static char *get_element(char 	*str,
						 char	parser,
				   		 size_t *k)
{
	char   *element;
	size_t start;

	while (str[*k] == parser)
		(*k)++;
	start = *k;
	while (str[*k] != parser && str[*k] != '\0')
		(*k)++;
	if ((element =
		std_strndup(&str[start], (*k) - start)) == NULL)
		return (NULL);
	return (element);
}

char **split_str(char *str,
				 char parser)
{
	char   **splitted;
	size_t i;
	size_t k;
	size_t bloc_count;

	bloc_count = count_bloc(str, parser);
	if ((splitted = malloc(sizeof(char*) * bloc_count)) == NULL)
		return (NULL);
	bloc_count--;
	splitted[bloc_count] = NULL;
	i = 0;
	k = 0;
	while (i < bloc_count)
	{
		if ((splitted[i] = get_element(str, parser, &k)) == NULL)
		{
			write(STDERR_FILENO, MEM_FAIL, 27);
			split_free(splitted);
			return (NULL);
		}
		i++;
	}
	return (splitted);
}

