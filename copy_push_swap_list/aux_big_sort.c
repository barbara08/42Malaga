#include "push_swap.h"

//Funciones auxiliares para big_sort.c
// --Aux 1
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

// Aux 1.1: Devuelve una copia ordenada de A
int	*ft_get_sorted_copy(t_data *data)
{
	int	*array;
	int	i;

	// 1. Asignación de memoria
	array = malloc(sizeof(int) * data->total);
	if (!array)
		return (NULL);
	
	// 2. Copia de elementos
	i = -1;
	while (++i < data->total)
		array[i] = data->a[i];
	
	// 3. Ordenamiento
	ft_bubble_sort(array, data->total);
	
	return (array);
}


// --- Auxiliar 2: Mueve elemento a B y optimiza rotación (3 parámetros, función corta) ---
// max_val es el punto medio del chunk (pivote)
void	ft_move_to_b(t_data *data, int i, int max_value)
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
	if (data->len_b > 1 && data->b[0] < max_value)
		rb(data->b, data->len_b);
}

// --- Auxiliar 3: Lógica de Chunks (3 parámetros, <= 25 líneas) ---
// Reemplaza ft_push_chunk_to_b, integrando la lógica del bucle
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
				ft_move_to_b(data, i, sorted[chunk * chunk_size + chunk_size / 2]);
				i = -1; // Reiniciar búsqueda tras mover
			}
			i++;
		}
		chunk++;
	}
}

