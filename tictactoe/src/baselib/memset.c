/**
 ** @file memset.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "baselib.h"

void *std_memset(void *ptr,
				 int value,
				 size_t	count)
{
	char *a;

	a = (char*) ptr;
	while (count > 0)
	{
		a[count - 1] = value;
		count = count - 1;
	}
	return (ptr);
}

