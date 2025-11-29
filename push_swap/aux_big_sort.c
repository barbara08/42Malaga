#include "push_swap.h"

void	ft_bubble_sort(int *array, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = -1;
	while (++i < size - 1)
	{
		j = -1;
		while (++j < size - 1 - i)
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
			}
		}
	}
}

int	*ft_get_sorted_copy(t_data *data)
{
	int	*array;
	int	i;

	array = malloc(sizeof(int) * data->total);
	if (!array)
		return (NULL);
	i = -1;
	while (++i < data->total)
		array[i] = data->a[i];
	ft_bubble_sort(array, data->total);
	return (array);
}

void	ft_index_array(int *a, int *sorted, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (a[i] == sorted[j])
			{
				a[i] = j;
				break;
			}
			j++;
		}
		i++;
	}
}

void	ft_radix_sort(t_data *data)
{
	int	i;
	int	j;
	int	max_bits;
	int	size;

	size = data->len_a;
	max_bits = 0;
	while ((size - 1) >> max_bits)
		max_bits++;
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < data->len_a)
		{
			if (((data->a[0] >> i) & 1) == 0)
				pb(data->a, &data->len_a, data->b, &data->len_b);
			else
				ra(data->a, data->len_a);
			j++;
		}
		while (data->len_b > 0)
			pa(data->a, &data->len_a, data->b, &data->len_b);
		i++;
	}
}

