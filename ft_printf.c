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

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
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
    while (whatisthis(c[i], '%'))
    {
        i++;
		// check for %
		// do specific helper function to check all that shit
		// if nothing match, print the % normally - so need to go back?
		// or just print a new one
		// to think about it
		if(whatisthis(c[i], '%'))
			break;
		//check for char//string
        else if (whatisthis(c[i], 's') || (whatisthis(c[i], 'c')))
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
		else if ((whatisthis(c[i], 'd')) || (whatisthis(c[i], 'i')))
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
		else 
			write(1, "%", 1);
    }
    write(1, &c[i], 1);
    i++;
    token++;
}
token++;
va_end(special);
return (token);
}

int main (void)
{
	// testing multiple stuff
char *c = "He %i%s%% llo %s world.\t What a%,bout %% ?\n Now let's think about\n";
int ft_test1;
int test1;

printf("TEST 1\n");
ft_test1 = ft_printf(c, 123, "ta darone", "ntm", "hmm");
printf("ft_test1: %i\n", ft_test1);

test1 = printf(c, 123, "ta darone", "ntm", "hmm");
printf("test1: %i\n", test1);

// testing NULL
// problem here
printf("Test 2: \n");
int ft_test2;
int test2;

ft_test2 = ft_printf("%p", NULL);
test2 = printf("%p\n", NULL);

printf("ft_test2: %p\n", ft_test2);
printf("test2: %p\n", test2);
// end of problem

// testing 0
// printf("Test 3: \n");
// int ft_test3;
// int test3;

// ft_test3 = ft_printf(0);
// test3 = printf(0);

// printf("ft_test3: %i\n", ft_test3);
// printf("test3: %i\n", test3);

// testing null char
printf("Test 4: \n");
int ft_test4;
int test4;

ft_test4 = ft_printf("\0");
test4 = printf("\0");

printf("ft_test4: %i\n", ft_test4);
printf("test4: %i\n", test4);


// testing individual %
printf("Test 5: \n");
int ft_test5;
int test5;
// this one is not really good so far
ft_test5 = ft_printf("bonj% our\n");
test5 = printf("bonj% our\n");

printf("ft_test5: %i\n", ft_test5);
printf("test5: %i\n", test5);

// testing hexadecimal printing
printf("Test 6: \n");
int ft_test6;
int test6;
// ft_test6 = ft_printf(123456789);
test6 = printf("hexadecimal of %i is : %x\n", 12255, 12255);

// printf("ft_test6: %x\n", ft_test6);
printf("test6: %i\n", test6);


}


// Edge cases to check 
	// DONE
	// if c is NULL
	// should return -1
	// DONE

	// if format specifier is not specified
	// eg "%,"
	// need to print it normally

	// DONE
	//if % is the last char of the string
	// should ignore and returns -1 
	// calculate strlen 
	// if c[strlen] == % && c[strlen -1] != %
	// return -1
	// DONE

// for result where you put the content of the format specifier,
// could be good to use malloc for it to avoid issues 