/**
 ** @file baselib.h
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#ifndef		__BASELIB_H__
#define 	__BASELIB_H__

#include	<unistd.h>
#include	<stdbool.h>

#define	IS_CHAR_NUMBER(nbr) ((nbr) >= '0' && (nbr) <= '9')

size_t std_strlen(char *str);

ssize_t	std_atoi(const char	*str);

ssize_t std_fputs(int fd,
				  char *str);

bool std_str_is_number(const char *s);

#endif