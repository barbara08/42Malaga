#include <stdio.h>
#include <unistd.h>

/*
Verificar si un carácter es un digito. 
The isdigit() 
return zero if the character tests false
return non-zero if the character tests true.
*/

void ft_putchar(char c)
{
    write(1, &c, 1);
}

void ft_putstr(char *str)
{
    while(*str)
        write(1, str++, 1);
}

int ft_isdigit(int c)
{
    if(c >= 48 && c <= 57)
        return(1);
    else
        return(0);
}

//OTRA FORMA DE HACER LA FUNCION

int fft_iisdigit(int c)
{
    return (c >= '0' && c <= '9');
}

int main()
{
    int c = 'g';
    int cc = 'g';
    int ftisdigit =ft_isdigit(c);
    int fftiisdigit = fft_iisdigit(cc);
    
    printf("Is digit (with printf): %d\n", ftisdigit);
    printf("IIs ddigit (with printf): %d\n", fftiisdigit);
    ft_putchar('\n');
    ft_putstr("Is digit (whith write): ");
    ft_putchar(ftisdigit + '0'); // Convierte 0 o 1 en carácter ASCII '0' o '1'
    ft_putstr("\n");
    ft_putstr("IIs ddigit (whith write): ");
    ft_putchar(ftisdigit + '0'); // Convierte 0 o 1 en carácter ASCII '0' o '1'
    ft_putstr("\n");
    return(0);
}