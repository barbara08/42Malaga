#include "libft.h"

int ft_tolower(int c)
{
    if(c >= 'A' && c <= 'Z')
        c = c + 32;
    return(c);
}

int main()
{
    int c = 'V';
    printf("tolower: %d", ft_tolower(c));
    return(0);
}
