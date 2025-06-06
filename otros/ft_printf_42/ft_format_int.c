/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmartin- <bmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 13:01:19 by bmartin-          #+#    #+#             */
/*   Updated: 2025/06/06 14:57:25 by bmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	count_ptr(va_list args)
{
	void				*p;
	unsigned long		ptr;
	int					count;
	char				*converted;

	p = va_arg(args, void *);
	count = 0;
	if (p == NULL)
	{
		count += ft_putstr("(nil)");
	}
	else
	{
		ptr = (unsigned long)p;
		count += ft_putstr("0x");
		converted = ft_converse_base(ptr, "0123456789abcdef");
		if (converted)
		{
			count += ft_putstr(converted);
			free(converted); // <<< Aquí liberas la memoria
		}
	}
	return (count);
}

int	ft_format_int(const char *specifier, int *i, va_list args)
{
	int		count;
	char	*formatted_str;

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
		count += count_ptr(args);
	else
	{
		formatted_str = ft_format(specifier[*i], args); // malloc aquí dentro
		if (formatted_str)
		{
			count += ft_putstr(formatted_str);
			free(formatted_str); // <<< Aquí liberas la memoria
		}
	}
	return (count);
}
