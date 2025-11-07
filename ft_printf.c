#include "libftprintf.h"

int ft_printf(const char *c, ...)
{
va_list special;
va_start(special, c);
int token;
int i;
int j;
int len;
char *result;

i = 0;
j = 0;
token = 0;
len = ft_strlen(c);
if(c == NULL || (c[i] == '%' && c[i +1] == '\0') || (c[len] == '%' && c[len -1] != '%'))
	return (-1);
while (c[i])
{
    if (whatisthis(c[i], '%'))
    {
		if(whatisthis(c[i +1], '%'))
		{ 
				write (1, "%", 1);
				token++;
		}
        else if (whatisthis(c[i +1], 's'))
        { 
			result = va_arg(special, char*);
			j = 0;
			while (result[j])
			{
				write(1, &result[j], 1);
				j++;
				token++;
			}
		}
		else if (whatisthis(c[i + 1], 'c'))
			{
				ft_putchar(va_arg(special, int));
				token++;
			}
		else if ((whatisthis(c[i + 1], 'd')) || (whatisthis(c[i + 1], 'i')))
				ft_putnbr(va_arg(special, int));
		else if (whatisthis(c[i + 1], 'u'))
				ft_unsigned_putnbr(va_arg(special, unsigned int));
		else if ((whatisthis(c[i + 1], 'x')) || (whatisthis(c[i + 1], 'X')))
			{
				result = ft_hexa(va_arg(special, int));
				j = 0;
				while (result[j])
				{
					write(1, &result[j], 1);
					j++;
					token++;
				}
			}
		else if (whatisthis(c[i + 1], 'p'))
			{
				result = ft_pointer(va_arg(special, void *));
				j = 0;
				while (result[j])
				{
					write(1, &result[j], 1);
					j++;
					token++;
				}
			}
		i += 2;
    }
	else
	{ 
    write(1, &c[i], 1);
    i++;
    token++;
	}
}
va_end(special);
return (token);
}




