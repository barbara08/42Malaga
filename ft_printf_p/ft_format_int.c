/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmartin- <bmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 13:01:19 by bmartin-          #+#    #+#             */
/*   Updated: 2025/06/03 12:08:52 by bmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	count_ptr(va_list args)
{
	void *p = va_arg(args, void *);
	unsigned long ptr;
	int count = 0;

	if (p == NULL)
	{
		count += ft_putstr("(nil)");
	}
	else
	{
		ptr = (unsigned long)p;
		count += ft_putstr("0x");
		count += ft_putstr(ft_converse_base(ptr, "0123456789abcdef"));
	}
	return (count);
}


int	ft_format_int(const char *specifier, int *i, va_list args)
{
	int				count;
	//unsigned long	ptr;

	count = 0;
	if (specifier[*i] == '%')
		count += ft_putchar('%');
	else if (specifier[*i] == 'd' || specifier[*i] == 'i')
		count += (ft_putnbr(va_arg(args, int)));
	else if (specifier[*i] == 's')
		count += ft_putstr(va_arg(args, char *));
    else if (specifier[*i] == 'c')
		count += ft_putchar((char)va_arg(args, int));
	else if (specifier[*i] == 'p')
	{
		count += count_ptr(args);
		/*void *p = va_arg(args, void *);
		if (p == NULL)
			count += ft_putstr("(nil)");
		else
		{
			ptr = (unsigned long)p;
			count += ft_putstr("0x");
			count += ft_count_caracter(ft_converse_base(ptr, "0123456789abcdef"));
		}*/
	}
	else
		count += ft_putstr(ft_format_char(specifier[*i], args));
	return (count);
}