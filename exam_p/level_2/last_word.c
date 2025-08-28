
#include "libft2.h"
/* display => mostrar
Write a program that takes a string and displays its last word followed by a \n.
A word is a section of string delimited by spaces/tabs or by the start/end of
the string.
If the number of parameters is not 1, or there are no words, display a newline.
Example:
$> ./last_word "FOR PONY" | cat -e
PONY$
$> ./last_word "this        ...       is sparta, then again, maybe    not" | cat -e
not$
$> ./last_word "   " | cat -e
$
$> ./last_word "a" "b" | cat -e
$
$> ./last_word "  lorem,ipsum  " | cat -e
lorem,ipsum$
$>
*/

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        int i = 0;
        // Ir al final del string
        while (argv[1][i])
            i++;
        i--;   // apuntar al último carácter válido
        // Saltar espacios o tabs al final
        while (i >= 0 && (argv[1][i] == ' ' || argv[1][i] == '\t'))
            i--;
        // Retroceder hasta el inicio de la última palabra
        while (i >= 0 && argv[1][i] != ' ' && argv[1][i] != '\t')
            i--;
        i++; // posicionarse en el primer carácter de la última palabra
        // Imprimir la última palabra
        while (argv[1][i] && argv[1][i] != ' ' && argv[1][i] != '\t')
        {
            write(1, &argv[1][i], 1);
            i++;
        }
    }
    write(1, "\n", 1);
    return (0);
}


//OTRA FORMA DE HACERLO, OK
/*
int main(int argc, char **argv)
{
    if (argc == 2)
    {
        int i = 0;
        // 1. Ir al final del string
        while (argv[1][i])
            i++;
        // apuntar al último carácter válido
        i--;

        // 2. Saltar espacios/tabs al final
        while (i >= 0 && (argv[1][i] == ' ' || argv[1][i] == '\t'))
            i--;

        // 3. Encontrar fin de la última palabra
        int end = i;

        // 4. Retroceder hasta el inicio de la palabra
        while (i >= 0 && argv[1][i] != ' ' && argv[1][i] != '\t')
            i--;
        i++;  // posicionarse en el primer carácter de la última palabra

        // 5. Imprimir la palabra
        while (i <= end)
        {
            write(1, &argv[1][i], 1);
            i++;
        }
    }
    write(1, "\n", 1);
    return (0);
}
*/
