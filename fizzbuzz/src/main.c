/**
 ** @file main.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "fizzbuzz.h"

int main(int argc,
		 char **argv)
{
	ssize_t num_interval[2];

	if (!check_args(argc, argv))
		return (84);
	num_interval[START_VAL] = std_atoi(argv[1]);
	num_interval[END_VAL] = std_atoi(argv[2]);
	fizzbuzz(num_interval);
	return (0);
}