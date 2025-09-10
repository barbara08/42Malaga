#include "push_swap.h"
/*
ra rotate a: Desplaza hacia arriba todos los elementos del stack a una posición,
	de forma que el primer elemento se convierte en el último.
rb rotate b: Desplaza hacia arriba todos los elementos del stack b una posición,
	de forma que el primer elemento se convierte en el último.
rr ra y rb al mismo tiempo.
*/

//Función aux que recibe cualquier stack
void rotate(int stack[], int len)
{
	int i = 0;
	int first;

	if (len < 2)
		return;

	first = stack[0];
	while (i < len - 1)
	{
		stack[i] = stack[i + 1];
		i++;
	}
	stack[len - 1] = first;
}

void ra_rotate(int a[], int len_a)
{
	rotate(a, len_a);
	write(1, "ra\n", 3);
}

void rb_rotate(int b[], int len_b)
{
	rotate(b, len_b);
	write(1, "rb\n", 3);
}

void rr_rotate(int a[], int len_a, int b[], int len_b)
{
	rotate(a, len_a);
	rotate(b, len_b);
	write(1, "rr\n", 3);
}



/* Función para el main
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
}*/



/*ANTIGUO CODIGO NO SE SI ESTÁ BIEN

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
	write(1, "ra\n", 3);
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
	write(1, "rb\n", 3);
}
void rr_rotate(int a[], int len_a, int b[], int len_b)
{
	ra_rotate(a, len_a);
	rb_rotate(b, len_b);
	write(1, "rr\n", 3);
}



*/