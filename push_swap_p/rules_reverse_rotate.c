#include "push_swap.h"

/*
rra reverse rotate a: Desplaza hacia abajo todos los elementos del stack a 
	una posición, de forma que el último elemento se convierte en el primero.
rrb reverse rotate b: Desplaza hacia abajo todos los elementos del stack b
	una posición, de forma que el último elemento se convierte en el primero.
rrr rra y rrb al mismo tiempo.
*/

// Función auxiliar que haga el reverse rotate sin imprimir
void reverse_rotate(int stack[], int len)
{
	int i;
	int last;

	if (len < 2)
		return;

	last = stack[len - 1];
	i = len - 1;
	while (i > 0)
	{
		stack[i] = stack[i - 1];
		i--;
	}
	stack[0] = last;
}
void rra_reverse_rotate(int a[], int len_a)
{
	reverse_rotate(a, len_a);
	write(1, "rra\n", 4);
}

void rrb_reverse_rotate(int b[], int len_b)
{
	reverse_rotate(b, len_b);
	write(1, "rrb\n", 4);
}

void rrr_reverse_rotate(int a[], int len_a, int b[], int len_b)
{
	reverse_rotate(a, len_a);
	reverse_rotate(b, len_b);
	write(1, "rrr\n", 4);
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
	int a[10] = {1, 2, 3, 4};
	int b[10] = {5, 6, 7};
	int len_a = 4;
	int len_b = 3;

	printf("\nStacks rra y rrb reverse original:\n");
	print_testing('a', a, len_a);
	print_testing('b', b, len_b);

	rra_reverse_rotate(a, len_a);
	rrb_reverse_rotate(b, len_b);

	printf("\nDespués de rra y rrb reverse:\n");
	print_testing('a', a, len_a);
	print_testing('b', b, len_b);

	rrr_reverse_rotate(a, len_a, b, len_b);

	printf("\nDespués de rrr:\n");
	print_testing('a', a, len_a);
	print_testing('b', b, len_b);

	return (0);
}
*/

/*ANTIGUO CODIGO, NO SE SI FUNCIONA 
void rra_reverse_rotate(int a[], int len_a)
{
	int i;
	int last;

	if(len_a < 2)
		return;
	// Guardamos el último elemento
	last = a[len_a - 1];
	// Mover todos los elementos una posición hacia atrás (de derecha a izquierda)
	i = len_a - 1;
	while(i > 0)
	{
		a[i] = a[i - 1];
		i--;
	}
	// Colocamos el último elemento al principio
	a[0] = last;
}

void rrb_reverse_rotate(int b[], int len_b)
{
	int i;
	int last;

	if(len_b < 2)
		return;
	last = b[len_b - 1];
	i = len_b - 1;
	while(i > 0)
	{
		b[i] = b[i - 1];
		i--;
	}
	b[0] = last;
}

void rrr_reverse_rotate(int a[], int len_a, int b[], int len_b)
{
	rra_reverse_rotate(a, len_a);
	rrb_reverse_rotate(b, len_b);
	write(1, "rrr\n", 4);
}




*/