#include "push_swap.h"

void ft_sort_three(int *stack_a, int size_a)
{
	if (size_a != 3)
		return;
	if (ft_is_sorted(stack_a, size_a))
		return;

	int a = stack_a[0];
	int b = stack_a[1];
	int c = stack_a[2];

	if (a > b && b < c && a < c)
		sa(stack_a, size_a);
	else if (a > b && b > c)
	{
		sa(stack_a, size_a);
		rra(stack_a, size_a);
	}
	else if (a > b && b < c && a > c)
		ra(stack_a, size_a);
	else if (a < b && b > c && a < c)
	{
		sa(stack_a, size_a);
		ra(stack_a, size_a);
	}
	else if (a < b && b > c && a > c)
		rra(stack_a, size_a);
}

void ft_sort_five(int *a, int *size_a, int *b, int *size_b)
{
	int min_value; 
	int min_index; 
	int i; // para recorrer el stack
	int j; // para ejecutar rotaciones

	while (*size_a > 3)
	{
		min_value = a[0];
		min_index = 0;

		/* encontrar el mínimo */
		/*Recorremos todo el stack para localizar el valor mínimo y su posición. */
		i = 1;
		while (i < *size_a)
		{
			/*Si encontramos un número menor → actualizamos min_value y min_index. */
			if (a[i] < min_value)
			{
				min_value = a[i];
				min_index = i;
			}
			i++;
		}

			/* rotaciones hacia arriba */
			/*Si el mínimo está en la mitad superior del stack, conviene usar rotaciones normales (ra). */
			/*Son más pocas rotaciones */
		if (min_index <= *size_a / 2)
		{
			j = 0;
			/*Ejecuta ra tantas veces como sea necesario para llevar el mínimo a la posición 0 */
			while (j < min_index)
			{
				ra(a, *size_a);
				j++;
			}
		}
			/* rotaciones hacia abajo */
			/*Si el mínimo está en la mitad inferior */
		else
		{
    		int moves = *size_a - min_index;
    		while (moves-- > 0)
        		rra(a, *size_a);  
		}
		/*Una vez que el mínimo está arriba del stack A, lo enviamos al stack B */
		/*Repetimos el ciclo hasta que A tenga solo 3 números */
		pb(a, size_a, b, size_b);
	}
	/*Cuando size_a == 3, usamos la función ordenar 3 números */
	ft_sort_three(a, *size_a);
	/* Sacamos todos los elementos de B y los devolvemos a A*/
	while (*size_b > 0)
		pa(a, size_a, b, size_b);
}

//auxiliary functions for sorting numbers greater than 6

int ft_get_chunk_size(int total_number_a)
{
	if (total_number_a <= 100)
		return(20);			// para 700-900 movimientos
	else if (total_number_a <= 500)
		return(45);			// para 5500 movimientos
	else
		return(100);		// para stacks más grandes
}

int ft_find_max_index(int b[], int len_b)
{
	int max_value = b[0];
	int pos_max_index = 0;
	int i = 1;

	while (i < len_b)
	{
		if (b[i] > max_value)
		{
			max_value = b[i];
			pos_max_index = i;
		}
		i++;
	}
	return(pos_max_index);
}

void ft_push_chunk_to_b(int a[], int *len_a, int b[], int *len_b, int sorted[], int chunk_size, int total)
{
	int chunk;
	int min_chunk;
	int max_chunk;
	int i;
	int moves;

	chunk = 0;
	while (chunk * chunk_size < total)
	{
		min_chunk = chunk * chunk_size;
		max_chunk = (chunk + 1) * chunk_size - 1;
		if (max_chunk >= total)
			max_chunk = total - 1;

		i = 0;
		while (i < *len_a)
		{
			if (a[i] >= sorted[min_chunk] && a[i] <= sorted[max_chunk])
			{
				// Rotación mínima en a
				if (i <= *len_a / 2)
				{
					while (i-- > 0)
						ra(a, *len_a);
				}
				else
				{
					moves = *len_a - i;
					while (moves-- > 0)
						rra(a, *len_a);
				}

				pb(a, len_a, b, len_b);

				// Rotación estratégica en b: colocar los más pequeños abajo
				if (*len_b > 1 && b[0] < sorted[min_chunk + chunk_size / 2])
					rb(b, *len_b);

				i = 0;
			}
			else
				i++;
		}
		chunk++;
	}
}

void ft_push_back_to_a(int a[], int *len_a, int b[], int *len_b)
{
	int max_index;
	int moves;

	while (*len_b > 0)
	{
		max_index = ft_find_max_index(b, *len_b);

		if (max_index <= *len_b / 2)
			while (max_index-- > 0)
				rb(b, *len_b);
		else
		{
			moves = *len_b - max_index;
			while (moves-- > 0)
				rrb(b, *len_b);
		}

		pa(a, len_a, b, len_b);
	}
}

void ft_sort_big_number(int *a, int *len_a, int *b, int *len_b, int total)
{
	int *sorted;
	int i;
	int swapped;
	int tmp;
	int chunk_size;

	sorted = (int *)malloc(sizeof(int) * total);
	if (!sorted)
		return;

	i = 0;
	while (i < total)
	{
		sorted[i] = a[i];
		i++;
	}

	// Ordenación simple para crear chunks (bubble sort)
	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		i = 0;
		while (i < total - 1)
		{
			if (sorted[i] > sorted[i + 1])
			{
				tmp = sorted[i];
				sorted[i] = sorted[i + 1];
				sorted[i + 1] = tmp;
				swapped = 1;
			}
		i++;
		}
	}

	chunk_size = ft_get_chunk_size(total);

	ft_push_chunk_to_b(a, len_a, b, len_b, sorted, chunk_size, total);
	ft_push_back_to_a(a, len_a, b, len_b);

	free(sorted);
}



/* OTRA OPCION, NO PROBADA

int get_chunk_size(int total)
{
    if (total <= 100)
        return 18;            // óptimo para ~600-700 movimientos
    else if (total <= 500)
        return 30;            // mantiene 4500-5500 movimientos
    else
        return 50;            // escalado coherente
}

*/