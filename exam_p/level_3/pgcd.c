#include "libft3.h"
/*
Write a program that takes two strings representing two strictly positive
integers that fit in an int.
Display their highest common denominator followed by a newline (It's always a
strictly positive integer).
If the number of parameters is not 2, display a newline.
Examples:
$> ./pgcd 42 10 | cat -e
2$
$> ./pgcd 42 12 | cat -e
6$
$> ./pgcd 14 77 | cat -e
7$
$> ./pgcd 17 3 | cat -e
1$
$> ./pgcd | cat -e
$
Allowed functions: printf, atoi, malloc, free
*/


//PROGRAMA SIN USAR ALGORITMO (para calcular hcf) (OK)
int main(int argc, char **argv)
{
	int n1 = 0;
	int n2 = 0;

	if(argc == 3)
	{
		n1 = atoi(argv[1]);
		n2 = atoi(argv[2]);

		if(n1 > 0 && n2 > 0)
		{
			while (n1 != n2)
			{
				if(n1 > n2)
					n1 = n1 - n2;
				else
					n2 = n2 - n1;
			}
			printf("%d", n1);
		}
	}
	printf("\n");
	return(0);
}

/* 
//PROGRAMA USANDO EL ALGORITMO DE EUCLIDES (OK)
int main(int argc, char **argv)
{
	int n1 = 0;
	int n2 = 0;
	int tmp;

	if(argc == 3)
	{
		n1 = atoi(argv[1]);
		n2 = atoi(argv[2]);

		if(n1 > 0 && n2 > 0)
		{
		// Para calcular el MCD usando el algoritmo de Euclides
		//while(n2 != 0) //Este usa los negativos y no lo queremos
			while(n2 > 0)
			{
				tmp = n2;
				n2 = n1 % n2;
				n1 = tmp;
			}
			printf("%d\n", n1);
			return(0); //Poner este return, así no sale el \n de abajo cuando se imprime aquí
		}
	}
	//Poner el return de arriba, así no sale el \n de aquí
	//Si no son exactamente 2 argumentos o alguno no es > 0
	printf("\n");  
	return(0);
}
*/