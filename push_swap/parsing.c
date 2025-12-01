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

int ft_fill_stack_from_str(const char *str, t_data *data)
{
    int     i = 0;
    char    *ptr = (char *)str;
    char    *endptr;
    long    num;

    while (*ptr == ' ' || (*ptr >= 9 && *ptr <= 13))
        ptr++;
    if (*ptr == '\0')
        return (1); // string vacía o solo espacios
    while (i < data->total)
    {
        num = ft_atoi(ptr, &endptr);
        if (num > INT_MAX || num < INT_MIN || num == 2147483648L)
            return (1);
        data->a[i++] = (int)num;
        ptr = endptr;
    }
    if (*ptr != '\0')
        return (1);
    return (0);
}


int	ft_parse_args(int argc, char **argv, t_data *data)
{
    int     i;
    long    tmp;
    char    *endptr;

    if (argc == 2)
    {
        data->total = ft_count_numbers_in_string(argv[1]);
        if (data->total == 0)
            return (1);

        return (ft_fill_stack_from_str(argv[1], data));
    }
    i = 0;
    while (i < data->total)
    {
        tmp = ft_atoi(argv[i + 1], &endptr);
        if (tmp > INT_MAX || tmp < INT_MIN || tmp == 2147483648L)
            return (1);
        if (*endptr != '\0')
            return (1);
        data->a[i] = (int)tmp;
        i++;
    }
    return (0);
}


