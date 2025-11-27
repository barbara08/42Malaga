#include "push_swap.h"

void reverse_rotate(int *stack, int len)
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

void rra(int *a, int len_a)
{
	reverse_rotate(a, len_a);
	write(1, "rra\n", 4);
}

void rrb(int *b, int len_b)
{
	reverse_rotate(b, len_b);
	write(1, "rrb\n", 4);
}

void rrr(int *a, int len_a, int *b, int len_b)
{
	reverse_rotate(a, len_a);
	reverse_rotate(b, len_b);
	write(1, "rrr\n", 4);
}



/*
int main()
{
	int a[10] = {1, 2, 3, 4};
	int b[10] = {5, 6, 7};
	int len_a = 4;
	int len_b = 3;

	printf("\nStacks rra y rrb reverse original:\n");
	ft_print_stack('a', a, len_a);
	ft_print_stack('b', b, len_b);

	rra(a, len_a);
	rrb(b, len_b);

	printf("\nDespués de rra y rrb reverse:\n");
	ft_print_stack('a', a, len_a);
	ft_print_stack('b', b, len_b);

	rrr(a, len_a, b, len_b);

	printf("\nDespués de rrr:\n");
	ft_print_stack('a', a, len_a);
	ft_print_stack('b', b, len_b);

	return (0);
}
*/