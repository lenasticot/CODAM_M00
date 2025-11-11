#include "ft_printf.h"

char	*ft_hexa_lower(unsigned int c)
{
	char	*result;
	int		i;
	int		temp;

	i = count_hex_digits(c);
	result = malloc(sizeof(char) * i + 1);
	result[i] = '\0';
	temp = 0;
	while (c != 0)
	{
		temp = c % 16;
		if (temp < 10)
			temp = temp + 48;
		else
			temp = temp + 87;
		result[--i] = temp;
		c = c / 16;
	}
	return (result);
}
