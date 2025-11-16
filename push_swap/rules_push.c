#include "push_swap.h"

/*
pa push a: Toma el primer elemento del stack b y lo pone el primero en el stack a.
	No hace nada si b está vacío.
pb push b: Toma el primer elemento del stack a y lo pone el primero en el stack b.
	No hace nada si a está vacío.
*/

void pa(int a[], int *len_a, int b[], int *len_b)
{
	if (*len_b > 0)
	{
		int j = *len_a;
		// Mover elementos de a hacia atrás
		while (j > 0)
		{
			a[j] = a[j - 1];
			j--;
		}

		a[0] = b[0];

		int k = 0;
		// Mover elementos de b hacia adelante
		while (k < *len_b - 1)
		{
			b[k] = b[k + 1];
			k++;
		}

		(*len_a)++;
		(*len_b)--;

		write(1, "pa\n", 3);
	}
}

void pb(int a[], int *len_a, int b[], int *len_b)
{
	if (*len_a > 0)
	{
		int j = *len_b;
		// Mover elementos de b hacia atrás
		while (j > 0)
		{
			b[j] = b[j - 1];
			j--;
		}

		b[0] = a[0];

		int k = 0;
		// Mover elementos de a hacia adelante
		while (k < *len_a - 1)
		{
			a[k] = a[k + 1];
			k++;
		}

		(*len_b)++;
		(*len_a)--;

		write(1, "pb\n", 3);
	}
}


/*

int main()
{
	int a[10] = {1, 2, 3};
	int b[10] = {4, 5};
	int len_a = 3;
	int len_b = 2;

	printf("\nStacks pa y pb original:\n");
	ft_print_stack('a', a, len_a);
	ft_print_stack('b', b, len_b);

	pa(a, &len_a, b, &len_b); // mueve 4 de b a a

	printf("\nDespués de pa:\n");
	ft_print_stack('a', a, len_a);
	ft_print_stack('b', b, len_b);

	pb(a, &len_a, b, &len_b); // mueve 4 de a a b

	printf("\nDespués de pb:\n");
	ft_print_stack('a', a, len_a);
	ft_print_stack('b', b, len_b);

	return (0);
}
*/

/* EXPLICACIÓN DE LA FUNCIÓN pa

if (*len_b > 0)
	Antes de hacer “pa”, se verifica que B no esté vacía.
	Si B tiene al menos un elemento, se puede hacer el push

int j = *len_a;
	j empieza en la longitud actual de A.
	Ejemplo: si A tiene 4 elementos, j = 4
	Esto se usa para mover los elementos de A una posición hacia abajo

while (j > 0)
{
    a[j] = a[j - 1];
    j--;
}
	Este while desplaza todos los elementos de A hacia abajo una posición,
	para liberar el índice 0.
	Ej:
	A = [3, 7, 10, 12]
	len_a = 4
	A = [?, 3, 7, 10, 12]

a[0] = b[0];
	Se coloca el primer elemento de B en el primer lugar de A.

int k = 0;
	k se usará para recorrer B.


// Mover elementos de b hacia adelante
while (k < *len_b - 1)
{
    b[k] = b[k + 1];
    k++;
}
	Este while desplaza todos los elementos de B hacia arriba, 
	porque el primero ya fue movido a A.
	Ej:
	B = [9, 5, 2, 1]
	B = [5, 2, 1, ?]

(*len_a)++;
	Como A recibió un nuevo elemento, su longitud aumenta en 1.

(*len_b)--;
	Como B perdió un elemento, su longitud disminuye en 1.

*/

