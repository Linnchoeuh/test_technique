/**
 ** @file strlen.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "baselib.h"

size_t std_strlen(char *str)
{
	return ((str[0] != '\0') ? std_strlen(&str[1]) + 1 : 0);
}