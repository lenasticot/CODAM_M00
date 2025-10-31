#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

char special_string(char c)
{
	return (0);
}

int	whatisthis(char s, char spechar)
{
	return (s == spechar);
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
int j;
char *result;

i = 0;
j = 0;
token = 0;
while (c[i])
{
    if (whatisthis(c[i], '%'))
    {
        i++;
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
		if (whatisthis(c[i], 'd'))

         // need to count the characters from the special charaacters as well
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
char *c = "He %s llo %s worl %s d";
int result;

result = ft_printf(c, "123", "ta darone", "ntm");
printf("%i", result);
}
