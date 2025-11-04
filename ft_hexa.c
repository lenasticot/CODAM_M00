
#include <stdio.h>
#include <stdlib.h>

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
// the function works but the issue is that right now it is backword 
// so eventually could turn it upside down without my printf? 
// or try something here direclty
// need to think about it
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

int main(void)
{
    int a;

    a = 5675;
    char *result = ft_hexa(a);
    printf("%s", result);

    
}