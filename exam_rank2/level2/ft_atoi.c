#include "../level.h"

/*
Assignment name  : ft_atoi
Expected files   : ft_atoi.c
Allowed functions: None
--------------------------------------------------------------------------------

Write a function that converts the string argument str to an integer (type int)
and returns it.
It works much like the standard atoi(const char *str) function, see the man.
Your function must be declared as follows:
int	ft_atoi(const char *str);
*/

int	ft_atoi(const char *str)
{
    int negative = 1;
    int result = 0;

    while ((*str >= 9 && *str <= 13) || *str == 32)
        str++;
    if(*str == '-')
    {
        negative = -1;
        str++;
    }
    else if (*str == '+')
        str++;
    while (*str >= '0' && *str <= '9')
    {
        result = result * 10 + (*str - '0');
        str++;
    }
    return(result * negative);
}

int main()
{
    const char *str1 = "abv42abc";
    const char *str2 = "123v";
    const char *str3 = "   -42";
    const char *str4 = "+17";

    printf("1: %d\n", ft_atoi(str1)); // 0
    printf("2: %d\n", ft_atoi(str2)); // 123
    printf("3: %d\n", ft_atoi(str3)); // -42
    printf("4: %d\n", ft_atoi(str4)); // 17

    return(0);
}