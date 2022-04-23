/**
 ** @file read_entry.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "entry_reader.h"

#define RD_FAIL "Read error.\n"

#define REALLOC_FAIL "Memory reallocation failed.\n"

static char *add_charac(char *src,
				  		char add)
{
	char   *new;
	size_t i;
	size_t len;

	len = std_strlen(src);
	if ((new = malloc(len + 2)) == NULL)
	{
		free(src);
		return (NULL);
	}
	i = 0;
	while (i < len)
	{
		new[i] = src[i];
		i++;
	}
	new[i] = add;
	new[i + 1] = '\0';
	free(src);
	return (new);
}

char *read_entry(void)
{
	char	*content;
	char	get;
	ssize_t byte;

	if ((content = std_strdup("")) == NULL)
		return (NULL);
	get = ' ';
	while (get != '\n')
	{
		byte = read(STDIN_FILENO, &get, 1);
		if (get != '\n' && byte <= 0)
		{
			(byte < 0) ? write(STDERR_FILENO, RD_FAIL, 12) :
						 write(STDOUT_FILENO, "\n", 1);
			free(content);
			return (NULL);
		}
		if (get != '\n' && (content = add_charac(content, get)) == NULL)
		{
			write(STDERR_FILENO, REALLOC_FAIL, 29);
			return (NULL);
		}
	}
	return (content);
}

