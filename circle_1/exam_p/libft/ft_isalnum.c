#include "libft.h"

int ft_isalnum(int c)
{
    if((c >= 48 && c <= 57)  || (c >= 'a' && c <= 'z'))
        return(1);
    else
        return(0);
}

int main()
{
    int c = 's';
    int cc = 5;
    ft_putstr("Is alpha: ");
    ft_putchar(c);
    ft_putchar('\n');
    ft_putstr("Is num: ");
    ft_putchar(cc);
    ft_putchar('\n');

    return(0);
}
