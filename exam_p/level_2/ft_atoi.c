#include <stdio.h>
/*
Write a function that converts the string argument str to an integer (type int)
and returns it.
It works much like the standard atoi(const char *str) function, see the man.
Your function must be declared as follows:
int	ft_atoi(const char *str);
*/

int	ft_atoi(const char *str)
{
    int result = 0;
    int negative = 1;

    while ((*str >= 9 && *str <= 13) || *str == 32)
        str++;
    if(*str == '-')
    { 
        negative = -1;
        str++;
    }
    else if(*str == '+')
        str++;
    while(*str >= '0' && *str <= '9')
    {
        result = result * 10 + (*str - '0');
        str++;
    }
    return(result * negative);
}

int main(void)
{
	const char *test1 = "   123";
	const char *test2 = "-456";
	const char *test3 = "+789";
	const char *test4 = "   \t\n\r\f\v42abc";
	const char *test5 = "abc123";
	const char *test6 = "2147483647"; // INT_MAX
	const char *test7 = "-2147483648"; // INT_MIN

	printf("ft_atoi(\"%s\") = %d\n", test1, ft_atoi(test1));
	printf("ft_atoi(\"%s\") = %d\n", test2, ft_atoi(test2));
	printf("ft_atoi(\"%s\") = %d\n", test3, ft_atoi(test3));
	printf("ft_atoi(\"%s\") = %d\n", test4, ft_atoi(test4));
	printf("ft_atoi(\"%s\") = %d\n", test5, ft_atoi(test5));
	printf("ft_atoi(\"%s\") = %d\n", test6, ft_atoi(test6));
	printf("ft_atoi(\"%s\") = %d\n", test7, ft_atoi(test7));

	return 0;
}
