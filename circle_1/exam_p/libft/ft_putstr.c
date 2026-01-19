#include <unistd.h>

/*
Imprimir un str
*/

void ft_putstr(char *str)
{
    while(*str)
        write(1, str++, 1);
}
/* 
int main()
{
    char *str = "jaja";
    ft_putstr(str);
    ft_putstr("\n");
    return(0);
}
*/