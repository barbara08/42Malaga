#include "push_swap.h"

// --- Auxiliares para sort_five ---
int	get_min_idx(int *a, int size)
{
	int	min;
	int	idx;
	int	i;

	min = a[0];
	idx = 0;
	i = 1;
	while (i < size)
	{
		if (a[i] < min)
		{
			min = a[i];
			idx = i;
		}
		i++;
	}
	return (idx);
}


// --- Auxiliares para big_sort ---

// --- get_max_idx (Ya estaba correcto, 2 parámetros) ---
int	get_max_idx(int *stack, int size)
{
	int	max;
	int	idx;
	int	i;

	max = stack[0];
	idx = 0;
	i = 1;
	while (i < size)
	{
		if (stack[i] > max)
		{
			max = stack[i];
			idx = i;
		}
		i++;
	}
	return (idx);
}

// --- ft_push_back_to_a (Ya estaba correcta, 1 parámetro) ---
// La mantengo aquí por completitud.
void	ft_push_back_to_a(t_data *data)
{
	int	max_idx;
	int	moves;

	while (data->len_b > 0)
	{
		max_idx = get_max_idx(data->b, data->len_b);
		if (max_idx <= data->len_b / 2)
		{
			while (max_idx-- > 0)
				rb(data->b, data->len_b);
		}
		else
		{
			moves = data->len_b - max_idx;
			while (moves-- > 0)
				rrb(data->b, data->len_b);
		}
		pa(data->a, &data->len_a, data->b, &data->len_b);
	}
}




/*
ORIGINAL, OK, se pasa de lineas

// --- Auxiliar 1: Crea copia ordenada (1 parámetro, función corta) ---
int	*get_sorted_copy(t_data *data)
{
	int	*arr;
	int	i;
	int	j;
	int	tmp;

	arr = malloc(sizeof(int) * data->total);
	if (!arr)
		return (NULL);
	i = -1;
	while (++i < data->total)
		arr[i] = data->a[i];
	i = -1;
	while (++i < data->total - 1)
	{
		j = -1;
		while (++j < data->total - 1 - i)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
	return (arr);
}

*/