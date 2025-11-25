#include "push_swap.h"

/*
Swaps
sa: Intercambia los dos primeros elementos del stack a.
sb: Intercambia los dos primeros elementos del stack b.
	*No hace nada si hay uno o menos elementos.
ss: Realiza sa y sb al mismo tiempo.
*/

void swap(int stack[], int len)
{
	int tmp;

	if (len < 2)
		return;

	tmp = stack[0];
	stack[0] = stack[1];
	stack[1] = tmp;
}

void sa(int a[], int len_a)
{
	swap(a, len_a);
	write(1, "sa\n", 3);
}

void sb(int b[], int len_b)
{
	swap(b, len_b);
	write(1, "sb\n", 3);
}

void ss(int a[], int len_a, int b[], int len_b)
{
	swap(a, len_a);
	swap(b, len_b);
	write(1, "ss\n", 3);
}

/*
int main()
{
	int a[] = {1, 2, 3};
	int b[] = {4, 5, 6};
	int len_a = 3;
	int len_b = 3;

	printf("\nStacks sa y sb original:\n");
	ft_print_stack('a', a, len_a);
	ft_print_stack('b', b, len_b);

	sa(a, len_a);
	sb(b, len_b);

	printf("\nDespués de sa y sb:\n");
	ft_print_stack('a', a, len_a);
	ft_print_stack('b', b, len_b);

	ss(a, len_a, b, len_b);

	printf("\nDespués de ss:\n");
	ft_print_stack('a', a, len_a);
	ft_print_stack('b', b, len_b);

	return (0);
}

*/