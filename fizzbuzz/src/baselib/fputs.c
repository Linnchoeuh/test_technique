/**
 ** @file fputs.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "fizzbuzz.h"

ssize_t std_fputs(int fd,
				  char *str)
{
	return (write(fd, str, std_strlen(str)));
}