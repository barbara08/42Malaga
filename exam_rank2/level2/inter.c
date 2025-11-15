#include "../level.h"
/*
Assignment name  : inter
Expected files   : inter.c
Allowed functions: write
--------------------------------------------------------------------------------

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
 
int main(int argc, char **argv)
{
	if(argc == 3)
	{
		int i;
		int j;
		int used_character[256] = {};

		i = 0;
		while (argv[1][i])
		{
			j = 0;
			while (argv[2][j])
			{
				if(argv[1][i] == argv[2][j] && !used_character[(int)argv[2][j]])
				{
					used_character[(int)argv[2][j]] = 1;
					write(1, &argv[2][j], 1);
				}
				j++;
			}
			i++;
		}
	}
	else
		write(1, "\n", 1);
	
	return(0);
}


//OTRA FORMA, OK
/* 
int main(int argc, char **argv)
{
	if (argc == 3)
	{
		int i;
		int present_in_second[256] = {};
		int printed[256] = {};
		unsigned char c;

		// 1. Marcar los caracteres que existen en la segunda cadena
		i = 0;
		while (argv[2][i])
		{
			present_in_second[(unsigned char)argv[2][i]] = 1;
			i++;
		}

		// 2. Recorrer la primera cadena y mostrar solo si aparece en la segunda
		i = 0;
		while (argv[1][i])
		{
			c = argv[1][i];
			if (present_in_second[c] && !printed[c])
			{
				printed[c] = 1;
				write(1, &c, 1);
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
*/