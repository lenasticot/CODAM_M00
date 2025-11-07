#include "libftprintf.h"

void	ft_putnbr(int n)
{
	if (n == (-2147483648))
	{
		write (1, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if (n <= 9 && n >= 0)
	{
		ft_putchar(n + '0');
		return ;
	}
	ft_putnbr (n / 10);
	ft_putnbr (n % 10);
}