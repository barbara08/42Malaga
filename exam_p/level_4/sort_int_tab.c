#include "libft4.h"

/*
Write the following function:
void sort_int_tab(int *tab, unsigned int size);
It must sort (in-place) the 'tab' int array, that contains exactly 'size'
members, in ascending order.
Doubles must be preserved.
Input is always coherent.
*/

void	sort_int_tab(int *tab, unsigned int size)
{
	unsigned int	i = 0;
	int				temp;
	unsigned int	sorted = 0; //para indicar si el array ya está ordenado.

    //Si el array tiene 0 o 1 elemento, no hay nada que ordenar
	if (size < 2)
		return;
    // se repite hasta que el array esté completamente ordenado
	while (!sorted)
	{
        //ya está ordenado
		sorted = 1;
        //Reiniciar el índice para recorrer el array desde el principio
		i = 0;
        //compara cada par de elementos adyacentes
        //Se detiene en size - 1, porque tab[i + 1] debe ser válido
		while (i + 1 < size)
		{
            //Si el elemento actual es mayor que el siguiente, están desordenados
            //hacemos swap
			if (tab[i] > tab[i + 1])
			{
				// Intercambiamos los valores (swap)
				temp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = temp;
                //Como hicimos un cambio, significa que el array aún no estaba ordenado.
                //Así que marcamos sorted = 0 para repetir otra pasada
				sorted = 0;
			}
			i++;
		}
	}
}

//PARA COMPROBAR EN MAIN

//para probar el main
void	ft_putnbr(int n)
{
	char	c;
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if (n >= 10)
		ft_putnbr(n / 10);
	c = (n % 10) + '0';
	write(1, &c, 1);
}

/* Función para imprimir un array de enteros (para probar main)
Esta función imprime los elementos del array tab 
(que contiene enteros) en una sola línea, separados por espacios.
Después de imprimir todos los elementos, escribe un salto de línea.
*/
void	print_array(int *tab, unsigned int size)
{
	unsigned int	i = 0;
	while (i < size)
	{
		ft_putnbr(tab[i]);
		if (i + 1 < size)
			write(1, " ", 1);
		i++;
	}
	write(1, "\n", 1);
}

int	main(void)
{
	int	arr[] = {42, 0, -3, 7, 7, 15, 1};
	unsigned int size = 7;

	write(1, "Before: ", 8);
	print_array(arr, size);

	sort_int_tab(arr, size);

	write(1, "After:  ", 8);
	print_array(arr, size);

	return (0);
}