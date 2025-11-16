#include "push_swap.h"
/*
ra rotate a: Desplaza hacia arriba todos los elementos del stack a una posición,
	de forma que el primer elemento se convierte en el último.
rb rotate b: Desplaza hacia arriba todos los elementos del stack b una posición,
	de forma que el primer elemento se convierte en el último.
rr ra y rb al mismo tiempo.
*/

void rotate(int stack[], int len)
{
	int i;
	int first;

	if (len < 2)
		return;

	i = 0;
	first = stack[0];
	while (i < len - 1)
	{
		stack[i] = stack[i + 1];
		i++;
	}
	stack[len - 1] = first;
}

void ra(int a[], int len_a)
{
	rotate(a, len_a);
	write(1, "ra\n", 3);
}

void rb(int b[], int len_b)
{
	rotate(b, len_b);
	write(1, "rb\n", 3);
}

void rr(int a[], int len_a, int b[], int len_b)
{
	rotate(a, len_a);
	rotate(b, len_b);
	write(1, "rr\n", 3);
}

/*
int main()
{
	int a[10] = {1, 2, 3, 4};
	int b[10] = {5, 6, 7};
	int len_a = 4;
	int len_b = 3;

	printf("\nStacks ra y rb original:\n");
	ft_print_stack('a', a, len_a);
	ft_print_stack('b', b, len_b);

	ra(a, len_a);
	rb(b, len_b);
	rr(a, len_a, b, len_b);


	printf("\nDespués de ra y rb y rr:\n");
	ft_print_stack('a', a, len_a);
	ft_print_stack('b', b, len_b);

	rr(a, len_a, b, len_b);

	printf("\nDespués de rr:\n");
	ft_print_stack('a', a, len_a);
	ft_print_stack('b', b, len_b);

	return (0);
}
*/

/* EXPLICACION DE LA FUNCION rotate
int first;
	guardará el primer elemento del stack

first = stack[0];
	Guarda el primer elemento de la pila antes de mover nada.
	Esto es importante porque ese elemento terminará en la última posición.

while (i < len - 1)
{
    stack[i] = stack[i + 1];
    i++;
}
	Este while desplaza todos los elementos una posición hacia arriba.
	Ej:
	[3, 7, 10, 12]
	[7, 10, 12, ?]
	El último elemento queda libre momentáneamente

stack[len - 1] = first;
	Coloca el primer elemento (que guardamos en first) al final del array

*/
