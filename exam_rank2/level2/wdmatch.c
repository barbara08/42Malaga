#include "../level.h"
/*
Assignment name  : wdmatch
Expected files   : wdmatch.c
Allowed functions: write
--------------------------------------------------------------------------------

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
	if(argc == 3)
	{
		int i = 0;
		int j = 0;

		//1. Recorremos [1]
		while (argv[1][i])
		{
			//2. Recorremos [2] hasta encontar el caracter de [1]
			while (argv[2][j] && argv[2][j] != argv[1][i])
				j++;
			//3. Si [2] llega al final y NO encuentra caracter en [1] terminamos
			if (argv[2][j] == '\0')
			{
				write(1, "\n", 1);
				return(0);
			}
			//4. Si hemos encontrado caracter en [1] avanzamos al siguiente caracter de [1]
			i++;
			j++;
		}
		//5. Si terminamos [1] correctamente formamos la palabra
		i = 0;
		while (argv[1][i])
		{
			write(1, &argv[1][i], 1);
			i++;
		}
	}
	else
		write(1, "\n", 1);

	return(0);
}
// 1. Recorrer la primera cadena (argv[1])
// 2. Recorrer la segunda cadena (argv[2]) hasta encontrar el carácter actual de argv[1]
// 3. Si llegamos al final de argv[2] y NO encontramos el carácter, nos salimos
	//ya que no es posible formar la cadena
// 4. Si encontramos el carácter, pasamos al siguiente carácter de argv[1] y argv[2]
// 5. Si terminamos de recorrer argv[1] exitosamente, la cadena se puede formar
