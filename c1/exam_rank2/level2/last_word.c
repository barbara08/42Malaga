#include "../level.h"

/*
Assignment name  : last_word
Expected files   : last_word.c
Allowed functions: write
--------------------------------------------------------------------------------

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
		int i;
	
		i = 0;
		//1
		while (argv[1][i])
			i++;
		//2
		i--;
		//3
		while (i >= 0 && (argv[1][i] == ' ' || argv[1][i] == '\t'))
			i--;
		//4
		while (i >= 0 && (argv[1][i] != ' ' && argv[1][i] != '\t'))
			i--;
		//5
		i++;
		//6
		while (argv[1][i] && (argv[1][i] != ' ' && argv[1][i] != '\t'))
		{
			write(1, &argv[1][i], 1);
			i++;
		}
	}
	else
		write(1, "\n", 1);
	
	return(0);
}

// 1. Ir al final de str
// 2. Posicionarse en la ultima posicion
// 3. Saltar los space/tab (hasta encontrar una letra)
// 4. Retroceder hasta el inicio de la última palabra
// 5. Posicionarse en el primer carácter de la última palabra
// 6. Imprimir la última palabra