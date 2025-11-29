#include "push_swap.h"

int	ft_get_min_index(int *a, int size)
{
	int	min;
	int	min_index;
	int	i;

	min = a[0];
	min_index = 0;
	i = 1;
	while (i < size)
	{
		if (a[i] < min)
		{
			min = a[i];
			min_index = i;
		}
		i++;
	}
	return (min_index);
}


int	ft_get_max_index(int *stack, int size)
{
	int	max;
	int	max_index;
	int	i;

	max = stack[0];
	max_index = 0;
	i = 1;
	while (i < size)
	{
		if (stack[i] > max)
		{
			max = stack[i];
			max_index = i;
		}
		i++;
	}
	return (max_index);
}


