#include "libft2.h"

/*
Reproduce exactly the behavior of the function strpbrk
(man strpbrk).
The function should be prototyped as follows:
char	*ft_strpbrk(const char *s1, const char *s2);
*/

char	*ft_strpbrk(const char *s1, const char *s2)
{
    int i = 0;
    int x = 0;
    while(s1[i] != '\0')
    {
        x = 0;
        while(s2[x] != '0')
        {
            if(s1[i] == s2[x])
                return((char *)s1);
            x++;
        }
        i++;
    }
    return(NULL);
}

int main() {
    const char *s1 = "Hola mundo";
    //const char *s2 = "aeiou";
    const char *s2 = "xyz";


    char *result = strpbrk(s1, s2);

    if (result)
    {
        printf("Primera coincidencia '%s' es '%c'\n", s1, *result);
    }
    else
    {
        printf("No se encontraron coincidencias.\n");
    }

    return (0);
}