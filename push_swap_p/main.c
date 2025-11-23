#include "push_swap.h"

int main(int argc, char **argv)
{
	int total;
	int *a;
	int *b;
	int i;
	int error;
	int len_a;
	int len_b;

	if (argc == 1)
	{
		return(0);
	}

	// Si hay un argumento único con espacios, parsearlo; si no, usar argumentos separados
	if (argc == 2)
	{
		total = count_numbers_in_string(argv[1]);
		if (total == 0)
			return(0);
	}
	else
	{
		total = argc - 1;
	}

	a = (int *)malloc(sizeof(int) * total);
	b = (int *)malloc(sizeof(int) * total);
	if (!a || !b)
	{
		free(a);
		free(b);
		return(1);
	}

	// Inicializar b para evitar basura
	i = 0;
	while (i < total)
	{
		b[i] = 0;
		i++;
	}

	error = 0;
	if (argc == 2)
	{
		// Parsear desde una cadena única
		int parsed_count = parse_numbers_from_string(argv[1], a, &error);
		if (error || parsed_count != total)
		{
			ft_print_error_and_free(a, b);
			return(1);
		}
	}
	else
	{
		// Parsear desde argumentos separados
		i = 0;
		while (i < total)
		{
			a[i] = ft_atoi(argv[i + 1], &error);
			if (error)
			{
				ft_print_error_and_free(a, b);
				return(1);
			}
			i++;
		}
	}

	if (ft_number_duplicate(a, total))
	{
		ft_print_error_and_free(a, b);
		return(1);
	}

	len_a = total;
	len_b = 0;

	if (!ft_is_sorted(a, len_a))
	{
		if (len_a == 2)
		{
			if (a[0] > a[1])
				sa(a, len_a);
		}
		else if (len_a == 3)
			ft_sort_three(a, len_a);
		else if (len_a <= 5)
			ft_sort_five(a, &len_a, b, &len_b);
		else
			ft_sort_big_number(a, &len_a, b, &len_b, total);
	}

	free(a);
	free(b);
	return(0);
}
