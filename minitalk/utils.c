#include "minitalk.h"

int     ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void    ft_putstr(char *str)
{
	if (*str != '\0')
	{
		while (*str != '\0')
		{
			write(1, str, 1);
			str++;
		}
	}
}

void    ft_putnbr(int num)
{
	char	c;

	if (num == -2147483648)
		write(1, "-2147483648", 11);
	else
	{
		if (num < 0)
		{
			write(1, "-", 1);
			num = -num;
			ft_putnbr(num);
		}
		else if (num < 10)
		{
			c = num + '0';
			write(1, &c, 1);
		}
		else
		{
			ft_putnbr(num / 10);
			c = (num % 10) + '0';
			write(1, &c, 1);
		}
	}
}

int     ft_atoi(const char *str)
{
	int	result;
	int	negative;

	result = 0;
	negative = 1;
	while (*str == ' ' || *str == '\t' || *str == '\v'
		|| *str == '\n' || *str == '\r' || *str == '\f')
	{
		str++;
	}
	if (*str == '-')
	{
		negative = -1;
		str++;
	}
	else if (*str == '+')
	{
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result * negative);
}



