#include "libft2.h"
/*
Reproduce the behavior of the function strcmp (man strcmp).
Your function must be declared as follows:
int    ft_strcmp(char *s1, char *s2);
*/

int    ft_strcmp(char *s1, char *s2)
{
    while ((*s1 || *s2) && (*s1 == *s2))
    {
        s1++;
        s2++;
    }
    return (*s1 - *s2);
}

int main()
{
    char *s1 = "AB";
    char *s2 = "ABC";
    printf("ft_strcmp(\"%d\")\n", ft_strcmp(s1, s2));
    //write(1, "\n", 1);
   // printf("%d", ft_strcmp(s1, s2));
    return(0);
}