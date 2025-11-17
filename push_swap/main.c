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

	if (argc < 2)
	{
		write(1, "You need arguments", 19);
		return(0);
	}

	total = argc - 1;
	a = (int *)malloc(sizeof(int) * total);
	b = (int *)malloc(sizeof(int) * total);
	if (!a || !b)
		return(1);

	i = 0;
	error = 0;
	while (i < total)
	{
		a[i] = ft_atoi_validate(argv[i + 1], &error);
		if (error)
		{
			ft_print_error_and_free(a, b);
			return(1);
		}
		i++;
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
