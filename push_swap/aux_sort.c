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

 void	ft_push_back_to_a(t_data *data)
{
    int idx;
    int moves;

    while (data->len_b > 0)
    {
        idx = ft_get_max_index(data->b, data->len_b);

        if (idx <= data->len_b / 2)
            while (idx-- > 0)
                rb(data->b, data->len_b);
        else
        {
            moves = data->len_b - idx;
            while (moves-- > 0)
                rrb(data->b, data->len_b);
        }
        pa(data->a, &data->len_a, data->b, &data->len_b);
    }
}


