#include "libft2.h"

/*
Write a program that takes two strings and displays, without doubles, the
characters that appear in either one of the strings.
The display will be in the order characters appear in the command line, and
will be followed by a \n.
If the number of arguments is not 2, the program displays \n.
Example:
$>./union zpadinton "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
zpadintoqefwjy$
$>./union ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
df6vewg4thras$
$>./union "rien" "cette phrase ne cache rien" | cat -e
rienct phas$
$>./union | cat -e
$
$>
$>./union "rien" | cat -e
$
$>
*/

int main(int argc, char **argv)
{
    int i = 0;
    int used_character[256] = {};

    if (argc == 3)
    {
        // Marcar todos los caracteres como presentes en argv[1] y argv[2]
        while (argv[1][i])
        {
            used_character[(int)argv[1][i]] = 1;
            i++;
        }
        i = 0;
        while (argv[2][i])
        {
            used_character[(int)argv[2][i]] = 1;
            i++;
        }
        // Imprimir sin duplicados en orden de aparición
        i = 0;
        while (argv[1][i])
        {
            if(used_character[(int)argv[1][i]])
            {
                write(1, &argv[1][i], 1);
                used_character[(int)argv[1][i]] = 0; // Evita imprimirlo otra vez
            }
            i++;
        }
        i = 0;
        while (argv[2][i])
        {
            if(used_character[(int)argv[2][i]])
            {
                write(1, &argv[2][i], 1);
                used_character[(int)argv[2][i]] = 0;
            }
            i++;
        }
    }
    write(1, "\n", 1);
    return(0);
}
