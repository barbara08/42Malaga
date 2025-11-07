#include "../level.h"

/*
Assignment name  : ft_strcpy
Expected files   : ft_strcpy.c
Allowed functions:
--------------------------------------------------------------------------------

Reproduce the behavior of the function strcpy (man strcpy).
Your function must be declared as follows:
char    *ft_strcpy(char *s1, char *s2);
*/

char    *ft_strcpy(char *s1, char *s2)
{
    while (*s2)
    {
        *s1 = *s2;
        s1++;
        s2++;
    }
    *s1 = '\0';
    return(s1);
}

int main()
{
    char s1[] = "hola perico";
    char s2[] = "como vas perico de los palotes";

    ft_strcpy(s1, s2);
    printf("%s", s1);
    return(0);
}