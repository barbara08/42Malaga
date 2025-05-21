/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmartin- <bmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 15:13:27 by bmartin-          #+#    #+#             */
/*   Updated: 2025/05/21 12:34:06 by bmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../libft/libft.h"
#include <stdio.h>

static int	ft_count_digit(unsigned long n, int base)
{
	int	count;
	
	count = 1;
	// Mientras el número sea mayor o igual que la base, dividimos por la base.
	while (n >= (unsigned)base)
	{
		n = n / base;
		count++;
	}
	return (count);
}
static char	*ft_converse_base(unsigned long n, char *base_str)
{
	int base;
	int len;
	char *str;

	base = 0;
	len = 0;
	while (base_str[base])
		base++;
	len = ft_count_digit(n, base);
	str = malloc((len + 1) * (sizeof(char)));
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (len--)
	{
		str[len] = base_str[n % base];
		n = n / base;
	}
	return (str);
}
int ft_count_caracter(char *str)
{
	int count;

	count = 0;
	if (str)
	{
		count += ft_putstr(str);
		free(str);
	}
	return(count);
}

static char *ft_format(char str, va_list args)
{
	if (str == 'd' || str == 'i')
		return ft_itoa(va_arg(args, int));
	else if (str == 'u')
		return ft_converse_base(va_arg(args, unsigned int), "0123456789");
	else if (str == 'x')
		return ft_converse_base(va_arg(args, unsigned int), "0123456789abcdef");
	else if (str == 'X')
		return ft_converse_base(va_arg(args, unsigned int), "0123456789ABCDEF");
	/*else if (str == 'p')
	{ 
		ft_putstr("0x");
		return ft_converse_base((unsigned long)va_arg(args, void *), "0123456789abcdef");
	}*/
	return (NULL);
}

int ft_printf(const char *format, ...)
{
    va_list args;
    int i = 0;
    int count = 0;
    char *str;

    va_start(args, format);
    while (format[i]) 
    {
        if (format[i] == '%') 
        {
            i++;
            
			if (format[i] == '%')
				count += ft_putchar('%');
			else if (format[i] == 'c')
			{
                char c = (char)va_arg(args, int);
                count += ft_putchar(c);
            }
			else if (format[i] == 's')
			{
				str = va_arg(args, char *);
				count += ft_putstr(str);
			} 
			else if (format[i] == 'p')
			{
				count += ft_putstr("0x");
				str = ft_converse_base((unsigned long)va_arg(args, void *), "0123456789abcdef");
				count += ft_count_caracter(str);
			}
			else
			{
				str = ft_format(format[i], args);  // Obtener la cadena de acuerdo con el especificador
				ft_count_caracter(str);
			}
        }
        else
            count += ft_putchar(format[i]);  // Imprimir caracteres normales
        i++;
    }
    va_end(args);
    return (count);
}



int main ()
{
	int n = 255;
	//int basediez = 10;
	//int basehexa = 16;
	int basebinary = 2;
		
	int ftcountdigit = ft_count_digit(n, basebinary);
	printf("ftcountdigit: %d\n", ftcountdigit);
	
	char *base_str_diez = "0123456789";
	char *base_str_hexa = "0123456789ABCDEF";
	char *base_str_binary = "01";
	char *ftconversebasediez = ft_converse_base(n, base_str_diez);
	char *ftconversebasehexa = ft_converse_base(n, base_str_hexa);
	char *ftconversebasebinary = ft_converse_base(n, base_str_binary);
	printf("ftconversebasediez: %s\n", ftconversebasediez);
	printf("ftconversebasehexa: %s\n", ftconversebasehexa);
	printf("ftconversebasebinary: %s\n", ftconversebasebinary);

	ft_printf("Imprime un solo carácter: %c\n", 'A');
	ft_printf("Imprime una string: %s\n", "hola");
	ft_printf("El puntero void * dado como argumento se imprime en formato hexadecimal: %p\n", 'd');
	ft_printf("Imprime un número decimal (base 10): %d\n", 42);
	ft_printf("Imprime un entero en base 10: %i\n", 24);
	ft_printf("Imprime un número decimal (base 10) sin signo: %u\n", 2244);
	ft_printf("Imprime un número hexadecimal (base 16) en minúsculas: %x\n", 12);
	ft_printf("Imprime un número hexadecimal (base 16) en mayúsculas: %X\n", 21);
	ft_printf("para imprimir el símbolo del porcentaje: %%\n", '%');

	return(0);
}