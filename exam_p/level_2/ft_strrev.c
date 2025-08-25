#include "libft2.h"

/*
Write a function that reverses (in-place) a string.
It must return its parameter.
Your function must be declared as follows:
char    *ft_strrev(char *str);
-----
Invertir en su lugar (in-palce)
quiere decir que dentro del mismo arreglo de caracteres, 
transformas "hola" en "aloh" sin crear otra cadena.
*/

char    *ft_strrev(char *str)
{
    int i;
    int x;
    int tmp;

    // Calculamos la longitud de la cadena
    i = 0;
    while(str[i])
        i++;
    
    // Intercambiamos caracteres desde ambos extremos hacia el centro
		//usamos dos índices: 
		//i (inicio) y x (final), 
		//y mientras i < x, intercambiamos los caracteres en esas posiciones
    x = i - 1;
    i = 0;
    while(i < x)
    {
        tmp = str[i];
        str[i] = str[x];
        str[x] = tmp;
        i++;
        x--;
    }
    return(str);
}

int main()
{
    //char *str = "hola"; //Esto lo toma como una constante y no se puede modificar
    char str[] = "chocolate"; //Ahora es un array modificable y no se pone como puntero

    printf("b: %s\n", str);
    char *ftstrrev = ft_strrev(str);
    printf("ft_strrev: %s", ftstrrev);
    return(0);
}