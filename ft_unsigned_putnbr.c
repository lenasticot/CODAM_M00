#include "libftprintf.h"

void	ft_unsigned_putnbr(unsigned int n)
{
	if (n <= 9)
	{
		ft_putchar(n + '0');
		return ;
	}
	ft_unsigned_putnbr (n / 10);
	ft_unsigned_putnbr (n % 10);
}