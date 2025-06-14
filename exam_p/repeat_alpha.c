#include <unistd.h>
#include <stdio.h>
/*
Write a program called repeat_alpha that takes a string and display it
repeating each alphabetical character as many times as its alphabetical index,
followed by a newline.
'a' becomes 'a', 'b' becomes 'bb', 'e' becomes 'eeeee', etc...
Case remains unchanged.
If the number of arguments is not 1, just display a newline.

Examples:
$>./repeat_alpha "abc"
abbccc
$>./repeat_alpha "Alex." | cat -e
Alllllllllllleeeeexxxxxxxxxxxxxxxxxxxxxxxx.$
$>./repeat_alpha 'abacadaba 42!' | cat -e
abbacccaddddabba 42!$
$>./repeat_alpha | cat -e
$
$>
$>./repeat_alpha "" | cat -e
$
$>
*/

/*
Imprime el carácter c n veces
ft_putchar('b', 3);
Imprime: bbb
*/
void ft_putchar_n(char c, int n)
{
    while (n > 0)
    {
        write(1, &c, 1);
        n--;
    }
}

/*
Parámetro:
    char *str: cadena de caracteres terminada en \0.
Bucle while (*str)
    Mientras no se llegue al final de la cadena (*str != '\0'), se analiza cada carácter:
Condición if(*str >= 'a' && *str <= 'z'):
    Si el carácter está entre 'a' y 'z':
        Se calcula cuántas veces debe repetirse: *str - 'a' + 1
            Ejemplo: 'c' - 'a' + 1 = 2 + 1 = 3
            En ascii 'c' es 99 y 'a' es 97;     99 - 97 = 2
        Se llama a ft_putchar para imprimir ese carácter esa cantidad de veces.
Si no es una minúscula o mayuscula (puede ser número, símbolo, etc.), lo imprime una sola vez.
*/
void repeat_alpha(char *str)
{
    while (*str)
    {
        if(*str >= 'a' && *str <= 'z')
            ft_putchar_n(*str, *str - 'a' + 1);
        else if (*str >= 'A' && *str <= 'Z')
            ft_putchar_n(*str, *str - 'A' + 1);
        else
            write(1, str, 1);
        str++;
    }
}

void rrepeat_aalpha(char *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        if(str[i] >= 'a' && str[i] <= 'z')
            ft_putchar_n(str[i], str[i] - 'a' + 1);
        else if (str[i] >= 'A' && str[i] <= 'Z')
            ft_putchar_n(str[i], str[i] - 'A' + 1);
        else
            write(1, &str[i], 1);
        i++;
    }
}

int main(int argc, char **argv)
{
    if(argc == 2)
    {
        repeat_alpha(argv[1]);
        write(1, "\n", 1);
        rrepeat_aalpha(argv[1]);
    }
    else
        printf("Enter a Fhrase");
    write(1, "\n", 1);
    return(0);
}



