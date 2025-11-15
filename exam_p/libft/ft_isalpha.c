#include <stdio.h>
#include <unistd.h>

/*
Verificar si un carácter es una letra del alfabeto 
(ya sea mayúscula o minúscula)
The isalpha()
returns zero if the character tests false
returns non-zero if the character tests true.
*/

int ft_isalpha(int c)
{
        if((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
            return(1);
        else
            return(0);
}

int main()
{
    int c = 3;
    int ftisalpha = ft_isalpha(c);
    printf("Is alpha: %d\n", ftisalpha);
    return(0);
}