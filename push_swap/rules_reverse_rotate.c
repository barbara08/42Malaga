#include "push_swap.h"

void	reverse_rotate(int *stack, int len)
{
	int	i;
	int	last;

	if (len < 2)
		return ;
	last = stack[len - 1];
	i = len - 1;
	while (i > 0)
	{
		stack[i] = stack[i - 1];
		i--;
	}
	stack[0] = last;
}

void	rra(int *a, int len_a)
{
	reverse_rotate(a, len_a);
	write(1, "rra\n", 4);
}

void	rrb(int *b, int len_b)
{
	reverse_rotate(b, len_b);
	write(1, "rrb\n", 4);
}

void	rrr(int *a, int len_a, int *b, int len_b)
{
	reverse_rotate(a, len_a);
	reverse_rotate(b, len_b);
	write(1, "rrr\n", 4);
}
