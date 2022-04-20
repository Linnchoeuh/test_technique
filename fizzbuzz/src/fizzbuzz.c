/**
 ** @file fizzbuzz.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "fizzbuzz.h"

void fizzbuzz(ssize_t *num_interval)
{
	while (num_interval[START_VAL] <= num_interval[END_VAL])
	{
		if (num_interval[START_VAL] % 3 == 0)
			write(STDOUT_FILENO, "Fizz", 4);
		if (num_interval[START_VAL] % 5 == 0)
			write(STDOUT_FILENO, "Buzz", 4);
		if (num_interval[START_VAL] % 3 != 0 &&
			num_interval[START_VAL] % 5 != 0)
			print_base(num_interval[START_VAL], 10);
		num_interval[START_VAL]++;
		write(STDOUT_FILENO, "\n", 1);
	}
}