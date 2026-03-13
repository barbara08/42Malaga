#include "libft.h"

int ft_isprint(int c)
{
    if(c >= 32 && c <= 126)
        return (1);
    else
        return(0);
}

int main()
{
    int c = ft_isprint(44);
    write(1, "write: ", 7);
    ft_putnbr(c);
    write(1, "\n", 1);
    printf("printf: %d", c);
    return(0);
}
