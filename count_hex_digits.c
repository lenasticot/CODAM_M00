#include "libftprintf.h"

int	count_hex_digits(unsigned long b)
{
	int	i;

	i = 0;
	if (b == 0)
		return (1);
	while (b != 0)
	{
		i++;
		b = b / 16;
	}
	return (i);
}