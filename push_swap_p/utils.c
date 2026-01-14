#include "push_swap.h"

static int	ft_parse_number(const char *str, int sign, int *error)
{
	long	num;
	long	res;

	num = 0;
	while (*str >= '0' && *str <= '9')
	{
		num = num * 10 + (*str - '0');
		res = num * sign;
		if (res > INT_MAX || res < INT_MIN)
		{
			*error = 1;
			return (0);
		}
		str++;
	}
	if (*str != '\0')
	{
		*error = 1;
		return (0);
	}
	return ((int)(num * sign));
}

int	ft_atoi(const char *str, int *error)
{
	int	sign;

	*error = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	if (!(*str >= '0' && *str <= '9'))
	{
		*error = 1;
		return (0);
	}
	return (ft_parse_number(str, sign, error));
}

int ft_number_duplicate(int *stack, int size)
{
	int i = 0;
	while (i < size)
	{
		int j = i + 1;
		while (j < size)
		{
			if (stack[i] == stack[j])
				return (1);  // ¡Duplicado encontrado!
			j++;
		}
		i++;
	}
	return (0);  // No hay duplicados
}

int ft_is_sorted(int *stack, int size)
{
	int i = 0;
	while (i < size - 1)
	{
		if (stack[i] > stack[i + 1])
			return (0); // Encontró que no está ordenado
		i++;
	}
	return (1); // Está ordenado
}

void ft_print_error_and_free(int *a, int *b)
{
    write(2, "Error\n", 6);
    if (a) free(a);
    if (b) free(b);
}

// Contar números en una cadena separados por espacios (por parámetro)
int count_numbers_in_string(const char *str)
{
	int count;
	int in_number;
	int i;

	i = 0;
	in_number = 0;
	count = 0;

	while (str[i])
	{
		if (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
			in_number = 0;
		else
		{
			if (!in_number)
			{
				count++;
				in_number = 1;
			}
		}
		i++;
	}
	return (count);
}

int	extract_number(const char *str, int *i, int *value, int *error)
{
	char	num_str[50];
	int		j;

	j = 0;
	if (str[*i] == '-' || str[*i] == '+')
	{
		num_str[j++] = str[*i];
		(*i)++;
	}
	while (str[*i] && str[*i] >= '0' && str[*i] <= '9')
	{
		num_str[j++] = str[*i];
		(*i)++;
	}
	if (j == 0 || (j == 1 && (num_str[0] == '+' || num_str[0] == '-')))
	{
		*error = 1;
		return (0);
	}
	num_str[j] = '\0';
	*value = ft_atoi(num_str, error);
	return (!(*error));
}

int	parse_numbers_from_string(const char *str, int *arr, int *error)
{
	int	i;
	int	count;
	int	value;

	i = 0;
	count = 0;
	*error = 0;
	while (str[i])
	{
		while (str[i] && (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13)))
			i++;
		if (!str[i])
			break;
		if (!extract_number(str, &i, &value, error))
			return (count);
		arr[count++] = value;
		if (str[i] && str[i] != ' ' && !(str[i] >= 9 && str[i] <= 13))
		{
			*error = 1;
			return (count);
		}
	}
	return (count);
}
