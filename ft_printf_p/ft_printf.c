/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmartin- <bmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 15:13:27 by bmartin-          #+#    #+#             */
/*   Updated: 2025/05/26 19:31:49 by bmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			count += ft_format_int(format, &i, args);
		}
		else
			count += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (count);
}

int main(void)
{
	char *name = "Barbara";
	int age = 42;
	void *ptr = (void *)0x12345678;

	ft_printf("Im %s, my age is %d and my pointer is %p.\n", name, age, ptr);
	ft_printf("%%u => %u, %%x => %x, %%X => %X \n", 4294967295, 4125, 4125);
	ft_printf("Este es: %% \n");

	return (0);
}