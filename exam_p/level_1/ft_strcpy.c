#include <unistd.h>
#include <stdio.h>
/*
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
    char s1[] = "hola";
    char s2[] = "periquito";
    printf("s1: %s", s1);
    printf("\n");
    printf("s2: %s", s2);
    printf("\n");

    //char *strcpy = ft_strcpy(s1, s2); NO FUNCIONA
    ft_strcpy(s1, s2);
    printf("s1 después de llamar a la funcion: %s", s1);
    printf("\n");
    printf("s2 después de llamar a la funcion: %s", s2);
    
    return(0);
}
    