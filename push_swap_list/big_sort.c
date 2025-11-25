#include "push_swap.h"

// --Aux 1
static void	ft_bubble_sort(int *arr, int size)
{
	int	i = -1;
	int	j;
	int	tmp;

	while (++i < size - 1)
	{
		j = -1;
		while (++j < size - 1 - i)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
}
// Aux 1.1
int	*get_sorted_copy(t_data *data)
{
	int	*arr;
	int	i;

	// 1. Asignación de memoria
	arr = malloc(sizeof(int) * data->total);
	if (!arr)
		return (NULL);
	
	// 2. Copia de elementos
	i = -1;
	while (++i < data->total)
		arr[i] = data->a[i];
	
	// 3. Ordenamiento
	ft_bubble_sort(arr, data->total);
	
	return (arr);
}


// --- Auxiliar 2: Mueve elemento a B y optimiza rotación (3 parámetros, función corta) ---
// max_val es el punto medio del chunk (pivote)
void	move_to_b(t_data *data, int i, int max_val)
{
	// 1. Poner el numero arriba en A
	if (i <= data->len_a / 2)
		while (i-- > 0)
			ra(data->a, data->len_a);
	else
		while (i++ < data->len_a)
			rra(data->a, data->len_a);
			
	// 2. Empujar a B
	pb(data->a, &data->len_a, data->b, &data->len_b);
	
	// 3. Optimizar B: Rotar a B si es menor que el pivote (para ordenar en B)
	if (data->len_b > 1 && data->b[0] < max_val)
		rb(data->b, data->len_b);
}

// --- Auxiliar 3: Lógica de Chunks (3 parámetros, <= 25 líneas) ---
// Reemplaza ft_push_chunk_to_b, integrando la lógica del bucle
void	push_chunks_to_b(t_data *data, int *sorted, int chunk_sz)
{
	int	chunk;
	int	limit;
	int	i;

	chunk = 0;
	while (chunk * chunk_sz < data->total)
	{
		limit = (chunk + 1) * chunk_sz - 1;
		if (limit >= data->total)
			limit = data->total - 1;
		i = 0;
		while (i < data->len_a)
		{
			if (data->a[i] >= sorted[chunk * chunk_sz] && data->a[i] <= sorted[limit])
			{
				move_to_b(data, i, sorted[chunk * chunk_sz + chunk_sz / 2]);
				i = -1; // Reiniciar búsqueda tras mover
			}
			i++;
		}
		chunk++;
	}
}


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