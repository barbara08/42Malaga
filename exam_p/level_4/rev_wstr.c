#include "libft4.h"

/*
Allowed functions: write, malloc, free

Write a program that takes a string as a parameter, and prints its words in
reverse order.
A "word" is a part of the string bounded by spaces and/or tabs, or the
begin/end of the string.
If the number of parameters is different from 1, the program will display
'\n'.
In the parameters that are going to be tested, there won't be any "additional"
spaces (meaning that there won't be additionnal spaces at the beginning or at
the end of the string, and words will always be separated by exactly one space).
Examples:
$> ./rev_wstr "You hate people! But I love gatherings. Isn't it ironic?" | cat -e
ironic? it Isn't gatherings. love I But people! hate You$
$>./rev_wstr "abcdefghijklm"
abcdefghijklm
$> ./rev_wstr "Wingardium Leviosa" | cat -e
Leviosa Wingardium$
$> ./rev_wstr | cat -e
$
$>
La función Imprime las palabras en orden inverso
*/

int main(int argc, char **argv)
{
    char    *str;
    int     i = 0;
    int     c;
    int     start;
    int     end;

    if (argc == 2)
    {
        str = argv[1];
        // Primero buscamos el final del string
        while (str[i])
            i++;
        // Posicionamos en el último carácter
        i--; 
        // Recorremos hacia atrás
        while (i >= 0)
        {
            // Saltamos espacios si hay
            while (i >= 0 && str[i] == ' ')
                i--;
            if (i < 0)
                break;
            // fin de la palabra
            end = i; 
            // Buscamos el inicio de la palabra
            while (i >= 0 && str[i] != ' ')
                i--;
            start = i + 1;
            // Escribimos la palabra carácter por carácter (ft_putstr)
            c = start;
            while (c <= end)
            {
                write(1, &str[c], 1);
                c++;
            }
            // Si aún quedan palabras por delante, imprimimos un espacio
            if (i > 0)
                write(1, " ", 1);
        }
    }
    write(1, "\n", 1);
    return (0);
}
