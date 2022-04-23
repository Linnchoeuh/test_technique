/**
 ** @file print_base.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "baselib.h"

int	print_base(int nbr,
			   int base)
{
	char c;
	int count;
	char nums[36] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	if (base > 35)
		return (-1);
	if (nbr < 0)
	{
		nbr = -nbr;
		write(STDOUT_FILENO, "-", 1);
	}
	c = nums[nbr % base];
	count = 1;
	if (nbr > base - 1)
		count += print_base(nbr / base, base);
	write(STDOUT_FILENO, &c, 1);
	return (count);
}
