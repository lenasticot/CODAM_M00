#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

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
char* ft_hexa(int c)
{
    char *result;
    int i;
    int j;
    int temp;
    
    i = count_nbr(c);
    j = 0;
    result = malloc(sizeof(char) * i);
    temp = 0;
    while (c != 0)
    {
       temp = c % 16;
       if (temp < 10)
        temp = temp + 48;
        else 
            temp = temp + 55;
       result[j] = temp;
       j++;
       c = c /16;
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
		// check for hexa
		// the function is backword at the moment
		// also need to do 2 different things if it is lowercase or uppercase
		// should add the tolower/toupper function for that
		else if ((whatisthis(c[i], 'x')) || (whatisthis(c[i], 'X')))
			{
				result = ft_hexa(va_arg(special, int));
				i++;
				j = 0;
				while (result[j])
				{
					write(1, &result[j], 1);
					j++;
					token++;
				}
			}
		else if (whatisthis(c[i], 'p'))
			{
				result = &va_arg(special, char*);
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
ft_test6 = ft_printf("hexadecimal of %i is : %x\n", 12255, 12255);
test6 = printf("hexadecimal of %i is : %x\n", 12255, 12255);

printf("ft_test6: %i\n", ft_test6);
printf("test6: %i\n", test6);

// testing the %p response
printf("Test 7: \n");
int ft_test7;
int test7;
char *c7 = "Hello World";

ft_test7 = ft_printf("Pointer of %s is : %p\n", c7, c7);
test7 = printf("Pointer of %s is : %p\n", c7, c7);

printf("ft_test7: %i\n", ft_test7);
printf("test7: %i\n", test7);

// testing the %u response
printf("Test 8: \n");
int ft_test8;
int test8;

ft_test8 = ft_printf("unsigned decimal of %i is %u\n", INT_MAX + 1, INT_MAX +1);
test8 = printf("unsigned decimal of %i is %u\n", INT_MAX +1, INT_MAX +1);

printf("ft_test8: %i\n", ft_test8);
printf("test8: %i\n", test8);

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