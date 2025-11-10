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
    char *dst = s1; //Guardar el puntero original
    while (*s2)
    {
        *s1 = *s2;
        s1++;
        s2++;
         printf(" (%p) " ,s1);
    }
    *s1 = '\0';
    return(dst); //Devilvemos el incio del destino
}

int main()
{
    char s1[31] = "hola perico";
    char s2[] = "como vas_____perico de los palotes";

    ft_strcpy(s1, s2);
    return(0);
}