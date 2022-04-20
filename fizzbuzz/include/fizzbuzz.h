/**
 ** @file fizzbuzz.h
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#ifndef		__FIZZBUZZ_H__
#define 	__FIZZBUZZ_H__

#include	<unistd.h>
#include	<stdbool.h>

#include	"baselib.h"

enum e_arg_val
{
	START_VAL,
	END_VAL
};

bool check_args(int argc,
			  char **argv);

void fizzbuzz(ssize_t *num_interval);

int	print_base(int nbr,
			   int base);

#endif