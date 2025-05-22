/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmartin- <bmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 15:13:27 by bmartin-          #+#    #+#             */
/*   Updated: 2025/05/21 19:58:12 by bmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"


int	ft_printf(const char *format, ...)
{
	va_list args;
	int i;
	int count;

	i = 0;
	count = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			count += ft_format_int(format, &i, args);
			//count += ft_count_caracter(ft_format(format[i], args));
		}
		else
			count += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return count;
}


int main(void)
{
	ft_printf("%%c Imprime un solo carácter: %c\n", 'c');
	ft_printf("%%s Imprime una string (como se define por defecto en C): %s\n", "hola");
	ft_printf("%%p El puntero void * dado como argumento se imprime en formato hexadecimal: %p\n", 'c');
	ft_printf("%%p El puntero void * dado como argumento se imprime en formato hexadecimal %p\n", (void *)0x1234abcd);
	ft_printf("%%d Imprime un número decimal (base 10): %d\n", 42);
	ft_printf("%%i Imprime un entero en base 10: %i\n", 24);
	ft_printf("%%u Imprime un número decimal (base 10) sin signo: %u\n", 2244);
	ft_printf("%%x Imprime un número hexadecimal (base 16) en minúsculas: %x\n", 255);
	ft_printf("%%X Imprime un número hexadecimal (base 16) en mayúsculas: %X\n", 255);
	ft_printf("%%%% Para imprimir el símbolo del porcentaje: %%\n", '%');
	ft_printf("---------------------\n", "--------______-------------");
	ft_printf("Hola %% mundo\n");
	ft_printf("Número: %d\n", 42);
	ft_printf("Unsigned: %u\n", 123456);
	ft_printf("Hex: %x\n", 255);
	ft_printf("Hex mayus: %X\n", 255);
	ft_printf("Char: %c\n", 'A');
	ft_printf("String: %s\n", "Hola mundo");
	ft_printf("Pointer: %p\n", (void *)0x1234abcd);

	return(0);
}