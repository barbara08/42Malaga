#include "push_swap.h"

/*
pa push a: Toma el primer elemento del stack b y lo pone el primero en el stack a.
	No hace nada si b está vacío.
pb push b: Toma el primer elemento del stack a y lo pone el primero en el stack b.
	No hace nada si a está vacío.
*/

/*
para hacer push, hay que:
Sacar el primer elemento del origen (shifting hacia adelante).
Insertarlo en la cima del destino (shifting hacia atrás para abrir espacio).
*/

/*
pa:
Si b tiene elementos, mueve el primero a a.
Hace espacio en a desplazando todos sus elementos a la derecha.
Luego elimina ese elemento de b desplazando hacia adelante.

pb:
Lo mismo pero al revés.
*/



void pa_push(int a[], int *len_a, int b[], int *len_b)
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

void pb_push(int a[], int *len_a, int b[], int *len_b)
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


/* Funcion para el main
void print_testing(char name, int stack[], int len)
{
	int i = 0;
	printf("%c: ", name);
	while (i < len) {
		printf("%d ", stack[i]);
		i++;
	}
	printf("\n");
}

int main()
{
	int a[10] = {1, 2, 3};
	int b[10] = {4, 5};
	int len_a = 3;
	int len_b = 2;

	printf("\nStacks pa y pb original:\n");
	print_testing('a', a, len_a);
	print_testing('b', b, len_b);

	pa_push(a, &len_a, b, &len_b); // mueve 4 de b a a

	printf("\nDespués de pa:\n");
	print_testing('a', a, len_a);
	print_testing('b', b, len_b);

	pb_push(a, &len_a, b, &len_b); // mueve 4 de a a b

	printf("\nDespués de pb:\n");
	print_testing('a', a, len_a);
	print_testing('b', b, len_b);

	return (0);
}
*/



/* ANTIGUO CODIGO, NO SE SI ESTA BIEN
void pa_push(int a[], int *len_a, int b[], int *len_b)
{
	int i;
	int j;
	int k;

	//Solo si b NO está vacío
	i = 0;
	while (*len_b > 0 && i == 0)
	{
		// Mover elementos de a una posición hacia atrás para hacer espacio al inicio
		j = *len_a;
		while (j > 0)
		{
			a[j] = a[j - 1];
			j--;
		}
		// Poner el primer elemento de b en la cima de a
		a[0] = b[0];
		// Mover elementos de b una posición hacia adelante (eliminar el primer elemento)
		k = 0;
		while (k < *len_b - 1)
		{
			b[k] = b[k + 1];
			k++;
		}
		(*len_a)++;
		(*len_b)--;
		write(1, "pa\n", 3);
		i = 1; //no se si debe estar
	}
}

void pb_push(int a[], int *len_a, int b[], int *len_b)
{
	int i;
	int j;
	int k;

	i = 0;

	while (*len_a > 0 && i == 0)
	{
		j = *len_b;
		while (j > 0)
		{
			b[j] = b[j - 1];
			j--;
		}
		b[0] = a[0];
		k = 0;
		while (k < *len_a - 1)
		{
			a[k] = a[k + 1];
			k++;
		}
		(*len_b)++;
		(*len_a)--;
		write(1, "pb\n", 3);
		i = 1; //no se si debe estar
	}
}
*/