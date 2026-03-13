#include "libft.h"

int ft_isascii(int c)
{
    if(c >= 0 && c <= 127)
        return (1);
    else
        return (0);
}

int main()
{
    int c = ft_isascii(123);
    ft_putnbr(c);
    write(1, "\n", 1);
    printf("isascii %d", c);
    return(0);
}
