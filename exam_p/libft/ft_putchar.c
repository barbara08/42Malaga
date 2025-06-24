#include <unistd.h>

/*
Imprimir solo un caracter
*/

void ft_putchar(char c)
{
    write(1, &c, 1);
}

/* 
int main()
{
    int c = 'j';
    int cc = 'j';
    // Convierte 0 o 1 en carácter ASCII '0' o '1'
    ft_putchar(c + '0'); //Imprime el nº ASCII que es '?'
    ft_putchar('\n');
    ft_putchar(cc); //Imprime la letra 'j'
    ft_putchar('\n');
    return(0);
}
*/
