#include "push_swap.h"

/*
Swaps
sa: Intercambia los dos primeros elementos del stack a.
sb: Intercambia los dos primeros elementos del stack b.
	*No hace nada si hay uno o menos elementos.
ss: Realiza sa y sb al mismo tiempo.
*/

//Función auxiliar que haga el swap sin imprimir nada
void swap(int stack[], int len)
{
	int tmp;

	if (len < 2)
		return;

	tmp = stack[0];
	stack[0] = stack[1];
	stack[1] = tmp;
}
void sa_swap(int a[], int len_a)
{
	swap(a, len_a);
	write(1, "sa\n", 3);
}

void sb_swap(int b[], int len_b)
{
	swap(b, len_b);
	write(1, "sb\n", 3);
}

void ss_swap(int a[], int len_a, int b[], int len_b)
{
	swap(a, len_a);
	swap(b, len_b);
	write(1, "ss\n", 3);
}



/* 
//Función para hacer imprimir, para el main
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
	int a[] = {1, 2, 3};
	int b[] = {4, 5, 6};
	int len_a = 3;
	int len_b = 3;

	printf("\nStacks sa y sb original:\n");
	print_testing('a', a, len_a);
	print_testing('b', b, len_b);

	sa_swap(a, len_a);
	sb_swap(b, len_b);

	printf("\nDespués de sa y sb:\n");
	print_testing('a', a, len_a);
	print_testing('b', b, len_b);

	ss_swap(a, len_a, b, len_b);

	printf("\nDespués de ss:\n");
	print_testing('a', a, len_a);
	print_testing('b', b, len_b);

	return (0);
}*/


/* ANTIGUO CODIGO, NO SE SI ESTA BIEN
void sa_swap(int a[], int len_a)
{
	int i = 0;
	int tmp;
	// Solo ejecutar si hay al menos 2 elementos
	while (len_a > 1 && i == 0)
	{
		tmp = a[0];
		a[0] = a[1];
		a[1] = tmp;
		write(1, "sa\n", 3); 
		i = 1; // Para salir del while después de 1 iteración
	}
}
void sb_swap(int b[], int len_b)
{
	int i = 0;
	int tmp;
	while (len_b > 1 && i == 0)
	{
		tmp = b[0];
		b[0] = b[1];
		b[1]= tmp;
		write(1, "sb\n", 3);
		i = 1;
	}
}

void ss_swap(int a[], int len_a, int b[], int len_b)
{
	sa_swap(a, len_a);
	sb_swap(b, len_b);
	write(1, "ss\n", 3);
}

*/
