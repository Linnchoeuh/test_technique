/**
 ** @file str_is_num.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "fizzbuzz.h"

static bool	num_check(const char *s)
{
	if (s[0] == '\0')
		return (true);
	else if (!IS_CHAR_NUMBER(s[0]))
		return (false);
	return (num_check(&s[1]));
}

bool std_str_is_number(const char *s)
{
	size_t start;

	start = 0;
	if (s == NULL)
		return (false);
	if (s[0] == '-' && s[1] != '\0')
		start = 1;
	return (num_check(&s[start]));
}
