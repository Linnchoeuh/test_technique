/**
 ** @file check_arg.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "fizzbuzz.h"

#define MISS_ARG "Error: Not enough argument.\n"
#define NO_NUM_ARG "Error: Arguments must be number.\n"
#define INEQUAL_NUMS \
"Error: the second parameter must be greater than the first one.\n"

bool check_args(int argc,
			  char **argv)
{
	if (argc < 3)
	{
		std_fputs(STDERR_FILENO, MISS_ARG);
		return (false);
	}
	if (!std_str_is_number(argv[1]) ||
		!std_str_is_number(argv[2]))
	{
		std_fputs(STDERR_FILENO, NO_NUM_ARG);
		return (false);
	}
	if (std_atoi(argv[1]) > std_atoi(argv[2]))
	{
		std_fputs(STDERR_FILENO, INEQUAL_NUMS);
		return (false);
	}
	return (true);
}