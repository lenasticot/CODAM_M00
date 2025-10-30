#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

char special_string(char c);

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*tmps1;
	unsigned char	*tmps2;
	size_t			i;

	tmps1 = (unsigned char *)s1;
	tmps2 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (i < n)
	{
		if (tmps1[i] != tmps2[i])
			return (tmps1[i] - tmps2[i]);
		i++;
	}
	return (0);
}

int ft_printf(const char *c, ...)
{

    // while char c
    // if c == %
    // check for next character
    // act upon and print with special rule
    // if special character (eg "\")
    // check for next character and act upon
    // else
    // print c with write

// int i;

va_list special;
va_start(special, c);

// this is the basic print situation without any problem
// do i need to count how many arguments I will receive? 

int token;
int i;

i = 0;
token = 0;
while (*c)
{
    if ((ft_memcmp((const void *)c, '%', 1)) == 0)
    {
        i++;
        if((ft_memcmp(*c, 's', 1)) == 0)
        { 
         // fetch the argument and print it
            write(1, va_arg(special, char), 1);
            i++;
        }
         // need to count the characters from the special charaacters as well

    }
    write(1, &c, 1);
    i++;
    token++;
}

va_end(special);
return (token);
}



int main (void)
{
char *c = "Hello orld";

ft_printf(c);
}
