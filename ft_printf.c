#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

char special_string(char c)
{
	return (0);
}

int	count_nbr(int a)
{
	int	i;

	i = 0;
	if (a <= 0)
		i++;
	while (a != 0)
	{
		i++;
		a = a / 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char		*result;
	int			token;
	int			is_neg;
	long int	num;

	num = n;
	is_neg = (num < 0);
	token = count_nbr(num);
	result = malloc(sizeof(char) * (token + 1));
	if (result == NULL)
		return (NULL);
	result[token--] = '\0';
	if (is_neg)
	{
		num = -num;
		result[0] = '-';
	}
	if (num == 0)
		result[0] = '0';
	while (num > 0)
	{
		result[token--] = (num % 10) + '0';
		num = num / 10;
	}
	return (result);
}

int	whatisthis(char s, char spechar)
{
	return (s == spechar);
}

int ft_printf(const char *c, ...)
{
va_list special;
va_start(special, c);

int token;
int i;
int j;
char *result;

i = 0;
j = 0;
token = 0;
while (c[i])
{
    while (whatisthis(c[i], '%'))
    {
        i++;
		// check for %
		if(whatisthis(c[i], '%'))
			break;
		//check for char//string
        if (whatisthis(c[i], 's') || (whatisthis(c[i], 'c')))
        { 
			result = va_arg(special, char*);
        	i++;
			j = 0;
			while (result[j])
			{
				write(1, &result[j], 1);
				j++;
				token++;
			}
        }
		// check for int/digit
		if ((whatisthis(c[i], 'd')) || (whatisthis(c[i], 'i')))
		{

		
			result = ft_itoa(va_arg(special, int));
			i++;
			j = 0;
			while (result[j])
			{
				write(1, &result[j], 1);
				j++;
				token++;
			}
		}
    }
    write(1, &c[i], 1);
    i++;
    token++;
}
va_end(special);
return (token);
}

int main (void)
{
char *c = "He %i%s%% llo %s world. What about %% ?\n Now let's think about\n";
int result;
int ouiresult;

result = ft_printf(c, 123, "ta darone", "ntm", "hmm");
printf("%i\n", result);

ouiresult = printf(c, 123, "ta darone", "ntm", "hmm");
printf("%i\n", result);


}

			// need to check if va_arg isanum
			// if not its not working
			// actually its ok normal reaction of the function