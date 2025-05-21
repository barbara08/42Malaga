
#include "printf.h"


int	ft_format_int(const char *specifier, int *i, va_list args)
{
    //char	*str;
    int		count;

	count = 0;
	if (specifier[*i] == '%')
		count += ft_putchar('%');
	else if (specifier[*i] == 's')
		count += ft_putstr(va_arg(args, char *));
    else if (specifier[*i] == 'c')
		count += ft_putchar((char)va_arg(args, int));
	else if (specifier[*i] == 'p')
	{
		unsigned long ptr = (unsigned long)va_arg(args, void *);
		count += ft_putstr("0x");
		//str = ft_converse_base(ptr, "0123456789abcdef");
		count += ft_count_caracter(ft_converse_base(ptr, "0123456789abcdef"));
	}
	else
	{
		//str = ft_format(specifier[*i], args);
		count += ft_count_caracter(ft_format(specifier[*i], args));
	}
	return (count);
}