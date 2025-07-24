#include "libft3.h"

/*
Write a program that displays the number of arguments passed to it, followed by
a newline.
If there are no arguments, just display a 0 followed by a newline.
Example:
$>./paramsum 1 2 3 5 7 24
6
$>./paramsum 6 12 24 | cat -e
3$
$>./paramsum | cat -e
0$
$>
*/

void ft_putnbr(unsigned int n)
{
	if(n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	char c;
	if(n >= 10)
		ft_putnbr(n / 10);
	c = (n % 10) + '0';
	write(1, &c, 1);
}
int main(int argc, char **argv)
{
	(void)argv;
	ft_putnbr(argc - 1);
	write(1, "\n", 1);
	return(0);
}


/* MI MAIN, OK, PERO MÁS LARGO Y NO HACE FALTA WHYLE
int main(int argc, char **argv)
{
	(void)argv;
	int count_param = 0;
	while(count_param + 1 < argc)
		count_param++;
	ft_putnbr(count_param);
	return(0);
}
*/


/*
PARA IMPRIMIR SOLO HASTA 9 DIGITOS (NO HACE FALTA LA FUNCION ft_putnbr)
int main(int argc, char **argv)
{
	(void)argv;
	int count_param = 0;
	// Contar argumentos (sin contar el nombre del programa)
	while(count_param + 1 < argc)
		count_param++;
	char c = count_param + '0';  //convierte el nº a carácter ASCII
	write(1, "Con write: ", 12);
	write(1, &c, 1);
	write(1, "\n", 1);
	printf("Con pritnf: %d\n", count_param);
	return(0);
}
*/