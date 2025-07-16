#include "push_swap.h"
/*
ra rotate a: Desplaza hacia arriba todos los elementos del stack a una posición,
	de forma que el primer elemento se convierte en el último.
rb rotate b: Desplaza hacia arriba todos los elementos del stack b una posición,
	de forma que el primer elemento se convierte en el último.
rr ra y rb al mismo tiempo.
*/


void ra_rotate(int a[], int len_a)
{
	int i;
	int first;
	if(len_a < 2)
		//Salir de la función sin hacer nada
		return;
	i = 0;
	first = a[0];
	while(i < len_a - 1)
	{
		a[i] = a[i + 1];
		i++;
	}
	a[len_a - 1] = first;
}

void rb_rotate(int b[], int len_b)
{
	int i;
	int first;
	if(len_b < 2)
		return;
	i = 0;
	first = b[0];
	while(i < len_b - 1)
	{
		b[i] = b[i + 1];
		i++;
	}
	b[len_b - 1] = first;
}
void rr_rotate(int a[], int len_a, int b[], int len_b)
{
	ra_rotate(a, len_a);
	rb_rotate(b, len_b);
}


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

	printf("\nStacks ra y rb original:\n");
	print_testing('a', a, len_a);
	print_testing('b', b, len_b);

	ra_rotate(a, len_a);
	rb_rotate(b, len_b);
	rr_rotate(a, len_a, b, len_b);


	printf("\nDespués de ra y rb y rr:\n");
	print_testing('a', a, len_a);
	print_testing('b', b, len_b);

	rr_rotate(a, len_a, b, len_b);

	printf("\nDespués de rr:\n");
	print_testing('a', a, len_a);
	print_testing('b', b, len_b);

	return (0);
}