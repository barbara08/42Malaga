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

void	ft_move_to_b(t_data *data, int i, int mid)
{
	int	len;

	len = data->len_a;

	/* Rotar por el camino más corto */
	if (i <= len / 2)
	{
		while (i > 0)
		{
			ra(data->a, data->len_a);
			i--;
		}
	}
	else
	{
		while (i < len)
		{
			rra(data->a, data->len_a);
			i++;
		}
	}

	/* Enviar a B */
	pb(data->a, &data->len_a, data->b, &data->len_b);

	/* Si es pequeño, rotarlo en B */
	if (data->b[0] < mid)
		rb(data->b, data->len_b);
}

void	ft_push_chunks_to_b(t_data *data, int *sorted, int chunk_size)
{
	int	chunk_start;
	int	chunk_end;
	int	mid;
	int	i;

	chunk_start = 0;
	while (chunk_start < data->total)
	{
		chunk_end = chunk_start + chunk_size - 1;
		if (chunk_end >= data->total)
			chunk_end = data->total - 1;

        /* midpoint correcto del chunk */
		mid = sorted[(chunk_start + chunk_end) / 2];

		i = 0;
		while (i < data->len_a)
		{
			if (data->a[i] >= sorted[chunk_start]
				&& data->a[i] <= sorted[chunk_end])
			{
				ft_move_to_b(data, i, mid);
				i = -1; // reiniciar porque A cambió de tamaño
			}
			i++;
		}
		chunk_start += chunk_size;
	}
}









/* 
void	ft_move_to_b(t_data *data, int i, int max_value)
{
	if (i <= data->len_a / 2)
		while (i-- > 0)
			ra(data->a, data->len_a);
	else
		while (i++ < data->len_a)
			rra(data->a, data->len_a);
	pb(data->a, &data->len_a, data->b, &data->len_b);
	if (data->len_b > 1 && data->b[0] < max_value)
		rb(data->b, data->len_b);
}

void	ft_push_chunks_to_b(t_data *data, int *sorted, int chunk_size)
{
	int	chunk;
	int	limit;
	int	i;

	chunk = 0;
	while (chunk * chunk_size < data->total)
	{
		limit = (chunk + 1) * chunk_size - 1;
		if (limit >= data->total)
			limit = data->total - 1;
		i = 0;
		while (i < data->len_a)
		{
			if (data->a[i] >= sorted[chunk * chunk_size] && data->a[i] <= sorted[limit])
			{
				ft_move_to_b(data, i, sorted[(chunk * chunk_size + chunk_size) / 2]);
				i = -1;
			}
			i++;
		}
		chunk++;
	}
}*/
