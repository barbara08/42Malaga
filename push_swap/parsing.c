#include "push_swap.h"

int	ft_count_numbers_in_string(const char *str)
{
	int	i;
	int	in_number;
	int	count_numbers;

	i = 0;
	in_number = 0;
	count_numbers = 0;
	while (str[i])
	{
		if (str[i] != ' ' && !(str[i] >= 9 && str[i] <= 13))
		{
			if (!in_number)
			{
				count_numbers++;
				in_number = 1;
			}
		}
		else
			in_number = 0;
		i++;
	}
	return (count_numbers);
}

int	ft_fill_stack_from_str(const char *str, t_data *data)
{
	int		i;
	char	*ptr;
	long	num;
	char	*temp_ptr;

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

int	ft_parse_args(int argc, char **argv, t_data *data)
{
	int		i;
	char	*endptr;
	long	tmp_value;

	if (argc == 2)
	{
		if (ft_fill_stack_from_str(argv[1], data))
			return (1);
	}
	else
	{
		i = 0;
		while (i < data->total)
		{
			tmp_value = ft_atoi(argv[i + 1], &endptr);
			if (tmp_value > INT_MAX
				|| tmp_value < INT_MIN || tmp_value == 2147483648L)
				return (1);
			if (*endptr != '\0')
				return (1);
			data->a[i] = (int)tmp_value;
			i++;
		}
	}
	return (0);
}
