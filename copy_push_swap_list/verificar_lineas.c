#include "push_swap.h"

//Estoy en la duda de las lineas de codigo

int	ft_fill_stack_from_str(const char *str, t_data *data)
{
	int		i;
	char	*ptr;
	long	num;
	char	*temp_ptr; // Usamos esto para la nueva ft_atoi

	i = 0;
	ptr = (char *)str;
	while (i < data->total)
	{
		num = ft_atoi(ptr, &temp_ptr); 
		if (num > INT_MAX || num < INT_MIN || num == 2147483648L)
			return (1);
		data->a[i] = (int)num;
        ptr = temp_ptr;
		while (*ptr == ' ' || (*ptr >= 9 && *ptr <= 13))
			ptr++;
		i++;
	}
    if (*ptr != '\0')
		return (1);
	return (0);
}

//Estoy en la duda de las lineas de codigo 
int	ft_parse_args(int argc, char **argv, t_data *data)
{
	int		i;
	char	*endptr;
	long	tmp_value;

	if (argc == 2)
		if (ft_fill_stack_from_str(argv[1], data))
			return (1);
	else // argc > 2
	{
		i = 0;
		while (i < data->total)
		{
			tmp_value = ft_atoi(argv[i + 1], &endptr); 
			if (tmp_value > INT_MAX || tmp_value < INT_MIN || tmp_value == 2147483648L)
				return (1);
            if (*endptr != '\0')
                return (1);
			data->a[i] = (int)tmp_value;
			i++;
		}
	}
	return (0);
}


//ORIGINAL

int	ft_parse_args(int argc, char **argv, t_data *data)
{
	int		i;
	char	*endptr;
	long	tmp_value;

	if (argc == 2)
	{
		// Si ft_fill_stack_from_str falla (por formato o overflow), retorna 1
		if (ft_fill_stack_from_str(argv[1], data))
			return (1);
	}
	else // argc > 2
	{
		i = 0;
		while (i < data->total)
		{
            //char *endptr;   estaba aquí pero lo he subido arriba a ver si funciona
            
			// Llama a la nueva ft_atoi, pasando la dirección de endptr
			tmp_value = ft_atoi(argv[i + 1], &endptr); 

			// Comprobación 1 & 2
			if (tmp_value > INT_MAX || tmp_value < INT_MIN || tmp_value == 2147483648L)
				return (1);
            
            // Comprobación 3: La cadena del argumento no debe tener basura al final
            // (Es decir, endptr debe apuntar al terminador \0)
            if (*endptr != '\0')
                return (1);
                
			data->a[i] = (int)tmp_value;
			i++;
		}
	}
	return (0);
}


//LINEAS JUSTAS (también en pb)
void pa(int a[], int *len_a, int b[], int *len_b)
{
    int i;

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

//-------
/*
 * Busca el elemento más cercano dentro del rango [start_val, end_val].
 * Utiliza un enfoque de dos punteros: 'top' que avanza desde 0 y 'bottom' que retrocede desde el final.
 * Devuelve el índice del elemento más eficiente de traer a la cima.
 */
/*
int	ft_get_best_index_in_chunk(int *a, int len_a, int start_val, int end_val)
{
	int	top;
	int	bottom;

	top = 0;
	bottom = len_a - 1;

	while (top <= bottom)
	{
		// Comprueba el elemento superior (distancia = top)
		if (a[top] >= start_val && a[top] <= end_val)
			return (top); // Es el candidato más rápido desde arriba

		// Comprueba el elemento inferior (distancia = len_a - 1 - bottom)
		if (a[bottom] >= start_val && a[bottom] <= end_val)
			return (bottom); // Es el candidato más rápido desde abajo

		top++;
		bottom--;
	}
	return (-1); // No debería ocurrir si el chunk existe
}
/*
static void ft_print_stack(char *name, int stack[], int len)
{
	int i = 0;
	printf("%s: ", name);
	while (i < len) {
		printf("%d ", stack[i]);
		i++;
	}
	printf("\n");
}

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

int *ft_get_sorted_copy(t_data *data)
{
    int *copy;
    int i;

    copy = malloc(sizeof(int) * data->len_a);
    if (!copy)
        return (NULL);
    i = -1;
    while (++i < data->len_a)
        copy[i] = data->a[i];
    ft_bubble_sort(copy, data->len_a);
    return (copy);
}
/*
void ft_move_to_b(t_data *data, int idx, int mid_val)
{
    if (idx <= data->len_a / 2)
        while (idx-- > 0)
            ra(data->a, data->len_a);
    else
        while (idx++ < data->len_a)
            rra(data->a, data->len_a);

    pb(data->a, &data->len_a, data->b, &data->len_b);

    // rotación inteligente de B
    if (data->len_b > 1 && data->b[0] < mid_val)
        rb(data->b, data->len_b);
}
*/
/*
void ft_move_to_b(t_data *data, int idx, int mid_val)
{
    // Decide si usar rotación normal (ra/rr) o inversa (rra/rrr)
    if (idx <= data->len_a / 2)
    {
        // Usar ra o rr
        while (idx-- > 0)
        {
            // Intentar usar rr si es beneficioso para B, si no, ra
            // Esta es la parte difícil de automatizar sin una función de coste completa.
            // Para una mejora simple, nos ceñimos a lo básico por ahora:
            ra(data->a, data->len_a);
        }
    }
    else
    {
        // Usar rra o rrr
        int moves = data->len_a - idx;
        while (moves-- > 0)
        {
            rra(data->a, data->len_a);
        }
    }

    pb(data->a, &data->len_a, data->b, &data->len_b);

    // Tu lógica de rotación inteligente de B sigue siendo buena aquí:
    if (data->len_b > 1 && data->b[0] < mid_val)
        rb(data->b, data->len_b);
}

void ft_push_chunks_to_b(t_data *data, int *sorted, int chunk)
{
    int start;
    int end;
    int mid;
    int i;

    start = 0;
    while (start < data->total)
    {
        end = start + chunk - 1;
        if (end >= data->total)
            end = data->total - 1;
        mid = (start + end) / 2;

        i = 0;
        while (i < data->len_a)
        {
            if (data->a[i] >= sorted[start] && data->a[i] <= sorted[end])
            {
                ft_move_to_b(data, i, sorted[mid]);
                i = 0;
                continue;
            }
            i++;
        }
        start += chunk;
    }
	ft_print_stack("B ", data->b, data->len_b);
}
*/
/*/
void ft_push_chunks_to_b(t_data *data, int *sorted, int chunk)
{
    int start;
    int end;
    int mid;
    int index_to_move; // Usaremos esto en lugar de 'i'

    start = 0;
    while (start < data->total)
    {
        end = start + chunk - 1;
        if (end >= data->total)
            end = data->total - 1;
        mid = (start + end) / 2;

        // Mientras queden elementos de este chunk en A
        while (1) 
        {
            // Encuentra el elemento del chunk más cercano a la cima
            index_to_move = ft_get_best_index_in_chunk(
                data->a, data->len_a, sorted[start], sorted[end]
            );

            // Si devuelve -1 o si el índice es inválido (no se encuentra nada), 
            // significa que hemos movido todo el chunk. Salimos del while(1).
            if (index_to_move == -1)
                break; 

            // Mueve el elemento encontrado (que ya es el óptimo) a B
            ft_move_to_b(data, index_to_move, sorted[mid]);
            
            // NOTA: ft_move_to_b realiza el 'pb' y las rotaciones necesarias.
            // Después del 'pb', el stack 'a' cambia, por lo que el siguiente
            // 'while(1)' volverá a buscar el mejor índice restante.
        }
        start += chunk;
    }
	// ft_print_stack("B ", data->b, data->len_b); // Línea de depuración, puedes quitarla
}
*/
