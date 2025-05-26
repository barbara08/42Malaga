/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmartin- <bmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 13:02:20 by bmartin-          #+#    #+#             */
/*   Updated: 2025/05/26 19:36:28 by bmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	long	num;
	int		count;

	num = n;
	count = 0;
	if (n == 0 && num != 0)
	{
		write(1, "0", 1);
		return (1);
	}
	if (num < 0)
	{
		write(1, "-", 1);
		num = -num;
		count++;
	}
	if (num >= 10)
		count += ft_putnbr(num / 10);
	write(1, &((char){num % 10 + '0'}), 1);
	count++;
	return (count);
}

/* 
int main(void)
{
	//int number = -123456789;
	int number = 123456789;
	int count = ft_putnbr(number);
	printf("\nNumber of characters printed: %d\n", count);
	return (0);
}
*/

/*
SIN PROBAR
int main()
{
    int len;

    // Ejemplo 1: Número positivo
    len = ft_putnbr(1234);
    write(1, "\n", 1);  // Para agregar un salto de línea
    printf("Caracteres escritos: %d\n", len);  // Debería imprimir "1234" y la cantidad de caracteres escritos

    // Ejemplo 2: Número negativo
    len = ft_putnbr(-5678);
    write(1, "\n", 1);  // Para agregar un salto de línea
    printf("Caracteres escritos: %d\n", len);  // Debería imprimir "-5678" y la cantidad de caracteres escritos

    // Ejemplo 3: Número cero
    len = ft_putnbr(0);
    write(1, "\n", 1);  // Para agregar un salto de línea
    printf("Caracteres escritos: %d\n", len);  // Debería imprimir "0" y la cantidad de caracteres escritos

    return 0;
}
	 */
