#include "libft2.h"

/* display => mostrar
Write a program that takes two strings and displays, without doubles, the
characters that appear in both strings, in the order they appear in the first
one.
The display will be followed by a \n.
If the number of arguments is not 2, the program displays \n.
Examples:
$>./inter "padinton" "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
padinto$
$>./inter ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
df6ewg4$
$>./inter "rien" "cette phrase ne cache rien" | cat -e
rien$
$>./inter | cat -e
$
*/


int ft_putchar(char c)
{
    return(write(1, &c, 1));
}

int main(int argc, char **argv)
{
    int i;
    int x;
    int used_character[256] = {};

	i = 0;
	//used_character[256] = {};
    if (argc == 3)
    {
        while (argv[1][i])
		{
			x = 0;
			while (argv[2][x])
			{
				if ((argv[1][i] == argv[2][x]) && !used_character[(int)argv[2][x]])
				{
					used_character[(int)argv[2][x]] = 1;  // Marcar como impreso
					ft_putchar(argv[2][x]);  // Imprimir el carácter común
				}
				x++;
			}
			i++;
		}
	}
	ft_putchar('\n');
	return(0);
}
/*
Debe ser simplemente !used_character[(int)argv[2][x]]. 
El valor de argv[2][x] es un carácter, y al usarlo directamente como índice, 
debemos convertirlo a un entero (usando el casting (int)) 
para usarlo como índice en el arreglo used_character.
*/
