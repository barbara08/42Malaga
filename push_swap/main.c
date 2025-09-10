#include "push_swap.h"

void print_error_and_free(int *a, int *b)
{
	write(2, "Error\n", 6);
	free(a);
	free(b);
}

int main(int argc, char **argv)
{
	if (argc < 2)
		return (0);

	int size_a = argc - 1;
	int size_b = 0;

	int *stack_a = (int *)malloc(sizeof(int) * size_a);
	if (!stack_a)
		return (1);

	int *stack_b = (int *)malloc(sizeof(int) * size_a);
	if (!stack_b)
	{
		free(stack_a);
		return (1);
	}

	int error = 0;
	int i = 0;
	while (i < size_a)
	{
		stack_a[i] = ft_atoi_validate(argv[i + 1], &error);
		if (error)
		{
			print_error_and_free(stack_a, stack_b);
			return (1);
		}
		i++;
	}

	i = 0;
	while (i < size_a)
	{
		int j = i + 1;
		while (j < size_a)
		{
			if (stack_a[i] == stack_a[j])
			{
				print_error_and_free(stack_a, stack_b);
				return (1);
			}
			j++;
		}
		i++;
	}

	i = 0;
	int sorted = 1;
	while (i < size_a - 1)
	{
	if (stack_a[i] > stack_a[i + 1])
        {
            sorted = 0;
            break;
        }
        i++;
    }
    if (sorted)
    {
        free(stack_a);
        free(stack_b);
        return (0);
    }

    if (size_a <= 3)
        ft_sort_three(stack_a, size_a);
    else if (size_a <= 5)
        ft_sort_five(stack_a, &size_a, stack_b, &size_b);
    else
    {
        ft_index_stack(stack_a, size_a);
        ft_sort_big(stack_a, &size_a, stack_b, &size_b);
    }

    free(stack_a);
    free(stack_b);
    return (0);
}
