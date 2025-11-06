#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>


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

// char	*ft_itoa(int n)
// {
// 	char		*result;
// 	int			token;
// 	int			is_neg;
// 	long int	num;

// 	num = n;
// 	is_neg = (num < 0);
// 	token = count_nbr(num);
// 	result = malloc(sizeof(char) * (token + 1));
// 	if (result == NULL)
// 		return (NULL);
// 	result[token--] = '\0';
// 	if (is_neg)
// 	{
// 		num = -num;
// 		result[0] = '-';
// 	}
// 	if (num == 0)
// 		result[0] = '0';
// 	while (num > 0)
// 	{
// 		result[token--] = (num % 10) + '0';
// 		num = num / 10;
// 	}
// 	return (result);
// }

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

char* ft_pointer(void *c)
{
    char *result;
	int i;
    int j;
    unsigned long temp;
	unsigned long c_bis;
    
	c_bis = (unsigned long)c;
	// cannot be count number because there is letters
	
    i = ft_strlen((char *)c) + 2;
    j = 0;
    result = malloc(sizeof(char) * i);
	result[0] = '0';
	result[1] = 'x';
    temp = 0;
    while (c_bis != 0)
    {
       temp = c_bis % 16;
       if (temp < 10)
        temp = temp + 48;
        else 
            temp = temp + 55;
       result[i] = temp;
       i--;
       c_bis = c_bis /16;
    }
     return (result);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

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

void	ft_unsigned_putnbr(unsigned int n)
{
	if (n <= 9 && n >= 0)
	{
		ft_putchar(n + '0');
		return ;
	}
	ft_putnbr (n / 10);
	ft_putnbr (n % 10);
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

// for pointers
    // Type expected: argument must be of type void * (or one promoted/cast to void ). Example: printf("%p\n", (void )ptr);
    // Output format: implementation-defined, but typically a hexadecimal representation of the address, often prefixed with 0x (e.g., 0x7ffee3b2a5c0). 
	// The exact width, lowercase/uppercase letters, and prefix are not guaranteed by the standard.
    // Behavior on mismatched type: passing a pointer type other than void * without casting leads 
	// to undefined behavior because printf expects an argument of the exact type it is specified to consume.
    // NULL pointer: printed representation is implementation-defined; common outputs include (nil) or 0x0.
    // Field width and flags: width, - (left adjust), and 0 (zero pad) may be supported by implementations; precision is not meaningful for %p in the standard and may be ignored.



int main (void)
{
	// testing multiple stuff
char *c = "test %d end\n";
int ft_test1;
int test1;

printf("TEST 1\n");
ft_test1 = ft_printf(c, 42);
printf("ft_test1: %i\n", ft_test1);

test1 = printf(c, 42);
printf("test1: %i\n", test1);

// testing NULL
// problem here
// printf("Test 2: \n");
// int ft_test2;
// int test2;

// ft_test2 = ft_printf("%p", NULL);
// test2 = printf("%p\n", NULL);

// printf("ft_test2: %p\n", ft_test2);
// printf("test2: %p\n", test2);
// // end of problem

// // testing 0
// // printf("Test 3: \n");
// // int ft_test3;
// // int test3;

// // ft_test3 = ft_printf(0);
// // test3 = printf(0);

// // printf("ft_test3: %i\n", ft_test3);
// // printf("test3: %i\n", test3);

// // testing null char
// printf("Test 4: \n");
// int ft_test4;
// int test4;

// ft_test4 = ft_printf("\0");
// test4 = printf("\0");

// printf("ft_test4: %i\n", ft_test4);
// printf("test4: %i\n", test4);


// // testing individual %
// printf("Test 5: \n");
// int ft_test5;
// int test5;
// // this one is not really good so far
// ft_test5 = ft_printf("bonj% our\n");
// test5 = printf("bonj% our\n");

// printf("ft_test5: %i\n", ft_test5);
// printf("test5: %i\n", test5);

// // testing hexadecimal printing
// printf("Test 6: \n");
// int ft_test6;
// int test6;
// ft_test6 = ft_printf("hexadecimal of %i is : %x\n", 12255, 12255);
// test6 = printf("hexadecimal of %i is : %x\n", 12255, 12255);

// printf("ft_test6: %i\n", ft_test6);
// printf("test6: %i\n", test6);

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

ft_test8 = ft_printf("max of int is %i but unsigned int can go above: %u\n", INT_MAX, INT_MAX +1);
test8 = printf("max of int is %i but unsigned int can go above: %u\n", INT_MAX, INT_MAX +1);

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