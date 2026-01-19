#include "../level.h"

/*
Assignment name  : rostring
Expected files   : rostring.c
Allowed functions: write, malloc, free
--------------------------------------------------------------------------------

Write a program that takes a string and displays this string after rotating it
one word to the left.
Thus, the first word becomes the last, and others stay in the same order.
A "word" is defined as a part of a string delimited either by spaces/tabs, or
by the start/end of the string.
Words will be separated by only one space in the output.
If there's less than one argument, the program displays \n.
Example:
$>./rostring "abc   " | cat -e
abc$
$>
$>./rostring "Que la      lumiere soit et la lumiere fut"
la lumiere soit et la lumiere fut Que
$>
$>./rostring "     AkjhZ zLKIJz , 23y"
zLKIJz , 23y AkjhZ
$>
$>./rostring "first" "2" "11000000"
first
$>
$>./rostring | cat -e
$
$>
*/

int main(int argc, char **argv)
{
	int	i;
	int	start_first_word;
	int end_first_word;
	int printed;
	
	if (argc >= 2)
	{
		i = 0;
		printed = 0;

			// Saltar espacios iniciales hasta llegar a una letra
		while (argv[1][i] && (argv[1][i] == ' ' || argv[1][i] == '\t'))
			i++;
			//Situarnos en la 1º posicion de la primera palabra
		start_first_word = i;

			// Encontrar fin de la primera palabra
		while (argv[1][i] && (argv[1][i] != ' ' && argv[1][i] != '\t'))
			i++;
			//Situarnos en la últina posicion de la primera palabra
		end_first_word = i;

			// Saltar espacios después de la primera palabra NO HACA FALTA 
		//while (argv[1][i] && (argv[1][i] == ' ' || argv[1][i] == '\t'))
		//	i++;
		
			// Imprimir el resto de las palabras
		while (argv[1][i])
		{
			while (argv[1][i] && (argv[1][i] == ' ' || argv[1][i] == '\t'))
				i++;

			if(argv[1][i])
			{
				if(printed)
					write(1, " ", 1);
				while (argv[1][i] && (argv[1][i] != ' ' && argv[1][i] != '\t'))
				{
					write(1, &argv[1][i], 1);
					i++;
				}
				printed = 1;
			}
		}
			// Imprimir la primera palabra al final
		if(printed)
			write(1, " ",1);
		i = start_first_word;
		while (i < end_first_word)
		{
			write(1, &argv[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
