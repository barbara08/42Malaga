#include "printf.h"

int	ft_count_digit(unsigned long n, int base)
{
	int len;

	len = 1;
	while (n >= (unsigned)base)
	{
		n /= base;
		len++;
	}
	return (len);
}