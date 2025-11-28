#include "push_swap.h"

void	ft_sort_three(int *stack_a, int size_a)
{
	int	first;
	int	second;
	int	third;

	if (ft_is_sorted(stack_a, size_a) || size_a != 3)
		return ;
	first = stack_a[0];
	second = stack_a[1];
	third = stack_a[2];
	if (first > second && first > third)
		ra(stack_a, size_a);
	else if (second > first && second > third)
		rra(stack_a, size_a);
	if (stack_a[0] > stack_a[1])
		sa(stack_a, size_a);
}

void	ft_sort_five(t_data *data)
{
	int	min_index;

	while (data->len_a > 3)
	{
		min_index = ft_get_min_index(data->a, data->len_a);
		if (min_index <= data->len_a / 2)
		{
			while (min_index-- > 0)
				ra(data->a, data->len_a);
		}
		else
		{
			while (min_index++ < data->len_a)
				rra(data->a, data->len_a);
		}
		pb(data->a, &data->len_a, data->b, &data->len_b);
	}
	ft_sort_three(data->a, data->len_a);
	while (data->len_b > 0)
		pa(data->a, &data->len_a, data->b, &data->len_b);
}

void	ft_sort_big_number(t_data *data)
{
	int	*sorted;
	int	chunk_size;

	sorted = ft_get_sorted_copy(data);
	if (!sorted)
		ft_print_error_and_free(data, 1);
	if (data->total <= 100)
		chunk_size = 20;
	else
		chunk_size = 45;
	ft_push_chunks_to_b(data, sorted, chunk_size);
	free(sorted);
	ft_push_back_to_a(data);
}
