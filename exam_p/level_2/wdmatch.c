#include "libft2.h"

/*
Write a program that takes two strings and checks whether it's possible to
write the first string with characters from the second string, while respecting
the order in which these characters appear in the second string.
If it's possible, the program displays the string, followed by a \n, otherwise
it simply displays a \n.
If the number of arguments is not 2, the program displays a \n.
Examples:
$>./wdmatch "faya" "fgvvfdxcacpolhyghbreda" | cat -e
faya$
$>./wdmatch "faya" "fgvvfdxcacpolhyghbred" | cat -e
$
$>./wdmatch "quarante deux" "qfqfsudf arzgsayns tsregfdgs sjytdekuoixq " | cat -e
quarante deux$
$>./wdmatch "error" rrerrrfiiljdfxjyuifrrvcoojh | cat -e
$
$>./wdmatch | cat -e
$
*/


int main(int argc, char **argv)
{
    int i;
    int x;
    if(argc == 3)
    {
        i = 0;
        x = 0;
        // Recorrer la primera cadena (argv[1])
        while(argv[1][i])
        {
            // Avanzar en la segunda cadena (argv[2]) hasta encontrar el carácter actual de argv[1]
            while(argv[2][x] && argv[2][x] != argv[1][i])
                x++;
            // Si llegamos al final de argv[2] sin encontrar el carácter, no es posible formar la cadena
            if (argv[2][x] ==  '\0')
            {
                write(1, "\n", 1);
                return(0);
            }
            // Si encontramos el carácter, pasamos al siguiente carácter de argv[1]
            i++;
            x++;
        }
        i = 0;
        // Si terminamos de recorrer argv[1] exitosamente, la cadena se puede formar
        while(argv[1][i])
        {
            write(1, &argv[1][i], 1);
            i++;
        }
    }
    write(1, "\n", 1);
    return(0);
}