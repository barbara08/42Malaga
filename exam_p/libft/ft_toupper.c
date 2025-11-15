#include "libft.h"


int	ft_toupper(int c)
{
    if(c >= 'a' && c <= 'z')
        c = c - 32;
    return (c);
}

int main()
{
    int c = 'b';
    int x = 'B';
    printf("c: %d\n", c);
    printf("x: %d\n", x);

    printf("toupper: %d\n", ft_toupper(c));
    printf("toupper: %d", ft_toupper(x));

}