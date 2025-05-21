#include "printf.h"

char	*ft_format(char specifier, va_list args)
{
	if (specifier == 'd' || specifier == 'i')
		return (ft_itoa(va_arg(args, int)));
	else if (specifier == 'u')
		return (ft_converse_base(va_arg(args, unsigned int), "0123456789"));
	else if (specifier == 'x')
		return (ft_converse_base(va_arg(args, unsigned int), "0123456789abcdef"));
	else if (specifier == 'X')
		return (ft_converse_base(va_arg(args, unsigned int), "0123456789ABCDEF"));
	return (NULL);
}