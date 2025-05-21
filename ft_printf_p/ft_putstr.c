#include "printf.h"


int	ft_putstr(char *s)
{
	int len = 0;
	if (!s)
		s = "(null)";
	while (s[len])
		write(1, &s[len++], 1);
	return (len);
}