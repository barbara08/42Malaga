#include "printf.h"

int	ft_count_caracter(char *str)
{
	int	count;

	count = 0;
	if (str)
	{
		count += ft_putstr(str);
		free(str);
	}
	return count;
}