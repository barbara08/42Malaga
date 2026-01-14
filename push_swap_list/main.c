#include "push_swap.h"

static void	init_data(t_data *data, int argc, char **argv)
{
	if (argc == 2)
		data->total = count_numbers_in_string(argv[1]);
	else
		data->total = argc - 1;
	if (data->total == 0)
		exit(0);
	data->len_a = data->total;
	data->len_b = 0;
	data->a = malloc(sizeof(int) * data->total);
	data->b = malloc(sizeof(int) * data->total);
	if (!data->a || !data->b)
		ft_print_error_and_free(data, 1);
}

static void	select_sort(t_data *data)
{
	if (data->total == 2)
	{
		if (data->a[0] > data->a[1])
			sa(data->a, data->len_a);
	}
	else if (data->total == 3)
		ft_sort_three(data->a, data->len_a);
	else if (data->total <= 5)
		ft_sort_five(data);
	else
		ft_sort_big_number(data);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc < 2)
		return (0);
	init_data(&data, argc, argv);
	if (parse_args(argc, argv, &data))
		ft_print_error_and_free(&data, 1);
	if (ft_number_duplicate(data.a, data.total))
		ft_print_error_and_free(&data, 1);
	if (!ft_is_sorted(data.a, data.total))
		select_sort(&data);
	ft_free_data(&data);
	return (0);
}
