#include "philo.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_print_error(const char *msg)
{
	write(2, "Error: ", 7);
	write(2, msg, ft_strlen(msg));
	write(2, "\n", 1);
	return (1);
}

int	ft_is_number(char *str)
{
	int	i;

	i = 0;
	if (!str || str[0] == '\0')
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	ft_atoi_positive(char *str)
{
	long	result;
	int		i;

	result = 0;
	i = 0;
	if (!ft_is_number(str))
		return (-1);
	while (str[i])
	{
		result = result * 10 + (str[i] - '0');
		if (result > 2147483647)
			return (-1);
		i++;
	}
	if (result <= 0)
		return (-1);
	return ((int)result);
}

int	ft_parse_args(int argc, char **argv, t_rules *rules)
{
	if (argc != 5 && argc != 6)
		return (ft_print_error("wrong number of arguments"));
	rules->nb_philos = ft_atoi_positive(argv[1]);
	rules->time_to_die = ft_atoi_positive(argv[2]);
	rules->time_to_eat = ft_atoi_positive(argv[3]);
	rules->time_to_sleep = ft_atoi_positive(argv[4]);
	rules->must_eat = -1;
	if (rules->nb_philos < 1 || rules->time_to_die < 0
		|| rules->time_to_eat < 0 || rules->time_to_sleep < 0)
		return (ft_print_error("invalid arguments"));
	if (argc == 6)
	{
		rules->must_eat = ft_atoi_positive(argv[5]);
		if (rules->must_eat < 1)
			return (ft_print_error("invalid must_eat"));
	}
	return (0);
}
