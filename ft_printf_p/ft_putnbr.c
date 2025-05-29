/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmartin- <bmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 13:02:20 by bmartin-          #+#    #+#             */
/*   Updated: 2025/05/26 18:31:09 by bmartin-         ###   ########.fr       */
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