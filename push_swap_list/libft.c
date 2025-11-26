#include "push_swap.h"

long ft_converted_digit(const char *str, const char **endptr)
{
    long num;
    const char *start;

    num = 0;
    start = str;
    while (*str >= '0' && *str <= '9')
    {
        num = num * 10 + (*str - '0');
        if (num > (long)INT_MAX + 1L)
            return 2147483648L; // error de overflow
        str++;
    }

    if (str == start)
        return 2147483648L; // no hay dígitos

    if (endptr)
        *endptr = str;

    return (num);
}

long ft_atol(const char *str, char **endptr)
{
    long num;
    int sign;

    sign = 1;
    if (endptr)
        *endptr = (char *)str;

    while (*str == ' ' || (*str >= 9 && *str <= 13))
        str++;

    if (*str == '-' || *str == '+')
    {
        if (*str == '-')
            sign = -1;
        str++;
    }

    num = ft_converted_digit(str, (const char **)endptr);

    return num * sign;
}

int	ft_number_duplicate(int *stack, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (stack[i] == stack[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_is_sorted(int *stack, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (stack[i] > stack[i + 1])
			return (0);
		i++;
	}
	return (1);
}
