#include "push_swap.h"

void	pa(int *a, int *len_a, int *b, int *len_b)
{
	int	i;

	if (*len_b > 0)
	{
		i = *len_a;
		while (i > 0)
		{
			a[i] = a[i - 1];
			i--;
		}
		a[0] = b[0];
		i = 0;
		while (i < *len_b - 1)
		{
			b[i] = b[i + 1];
			i++;
		}
		(*len_a)++;
		(*len_b)--;
		write(1, "pa\n", 3);
	}
}

void	pb(int *a, int *len_a, int *b, int *len_b)
{
	int	i;

	if (*len_a > 0)
	{
		i = *len_b;
		while (i > 0)
		{
			b[i] = b[i - 1];
			i--;
		}
		b[0] = a[0];
		i = 0;
		while (i < *len_a - 1)
		{
			a[i] = a[i + 1];
			i++;
		}
		(*len_b)++;
		(*len_a)--;
		write(1, "pb\n", 3);
	}
}
