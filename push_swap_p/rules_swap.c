#include "push_swap.h"

void	swap(int *stack, int len)
{
	int	tmp;

	if (len < 2)
		return ;
	tmp = stack[0];
	stack[0] = stack[1];
	stack[1] = tmp;
}

void	sa(int *a, int len_a)
{
	swap(a, len_a);
	write(1, "sa\n", 3);
}

void	sb(int *b, int len_b)
{
	swap(b, len_b);
	write(1, "sb\n", 3);
}

void	ss(int *a, int len_a, int *b, int len_b)
{
	swap(a, len_a);
	swap(b, len_b);
	write(1, "ss\n", 3);
}
