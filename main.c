#include "ft_printf.h"

// what need to be done
	// add the token counter - DONE
	// reverse hexa - DONE
	// make sure all test works correctly and add missing test
	// francinette 
	// norminette - DONE
	// check for remaining issues
	// submit

 
int main (void)
{
	// testing %d
// char *c = "test %d end\n";
// int ft_test1;
// int test1;

// printf("TEST 1\n");
// ft_test1 = ft_printf(c, 42);
// printf("ft_test1: %i\n", ft_test1);

// test1 = printf(c, 42);
// printf("test1: %i\n", test1);

// 	// testing NULL
// printf("Test 2: \n");
// int ft_test2;
// int test2;
// char *a = NULL;

// test2 = printf("%s\n", a);
// ft_test2 = ft_printf("%s\n", a);


// printf("ft_test2: %d\n", ft_test2);
// printf("test2: %d\n", test2);

// 	// testing 0
// // printf("Test 3: \n");
// // int ft_test3;
// // int test3;

// // ft_test3 = ft_printf(0);
// // test3 = printf(0);

// // printf("ft_test3: %i\n", ft_test3);
// // printf("test3: %i\n", test3);

// // testing null char
// // printf("Test 4: \n");
// // int ft_test4;
// // int test4;

// // ft_test4 = ft_printf('\0');
// // test4 = printf('\0');

// // printf("ft_test4: %i\n", ft_test4);
// // printf("test4: %i\n", test4);


// // testing individual %
// // printf("Test 5: \n");
// // int ft_test5;
// // int test5;

// // ft_test5 = ft_printf("bonj% wur\n");
// // test5 = printf("bonj% wur\n");

// // printf("ft_test5: %i\n", ft_test5);
// // printf("test5: %i\n", test5);

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
char *d7 = "Mange tes morts";

ft_test7 = ft_printf("Pointer of %s is : %p; but pointer of %s is : %p\n", c7, c7, d7, d7);
test7 = printf("Pointer of %s is : %p; but pointer of %s is : %p\n", c7, c7, d7, d7);

printf("ft_test7: %i\n", ft_test7);
printf("test7: %i\n", test7);

int ft_test7_2;
int test7_2;

ft_test7_2 = ft_printf("%p\n", (void *)0);
test7_2 = printf("%p\n", (void *)0);

printf("ft_test7_2: %i\n", ft_test7_2);
printf("test7_2: %i\n", test7_2);

// testing the %u response
// printf("Test 8: \n");
// int ft_test8;
// int test8;

// ft_test8 = ft_printf("max of int is %i but unsigned int can go above: %u\n", INT_MAX, INT_MAX +1);
// test8 = printf("max of int is %i but unsigned int can go above: %u\n", INT_MAX, INT_MAX +1);

// printf("ft_test8: %i\n", ft_test8);
// printf("test8: %i\n", test8);

}