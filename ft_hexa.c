#include "libftprintf.h"

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
