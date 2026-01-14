#include "push_swap.h"

void	ft_free_data(t_data *data)
{
	if (data->a)
		free(data->a);
	if (data->b)
		free(data->b);
}

void	ft_print_error_and_free(t_data *data, int error_only)
{
	if (error_only)
		write(2, "Error\n", 6);
	if (data)
		ft_free_data(data);
	exit(1);
}

