#include "push_swap.h"

void	rotate(int *stack, int len)
{
	int	i;
	int	first;

	if (len < 2)
		return ;
	i = 0;
	first = stack[0];
	while (i < len - 1)
	{
		stack[i] = stack[i + 1];
		i++;
	}
	stack[len - 1] = first;
}

void	ra(int *a, int len_a)
{
	rotate(a, len_a);
	write(1, "ra\n", 3);
}

void	rb(int *b, int len_b)
{
	rotate(b, len_b);
	write(1, "rb\n", 3);
}

void	rr(int *a, int len_a, int *b, int len_b)
{
	rotate(a, len_a);
	rotate(b, len_b);
	write(1, "rr\n", 3);
}
