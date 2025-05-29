/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_digit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmartin- <bmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 13:00:56 by bmartin-          #+#    #+#             */
/*   Updated: 2025/05/26 17:44:35 by bmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_count_digit(unsigned long n, int base)
{
	int	len;

	len = 1;
	while (n >= (unsigned)base)
	{
		n /= base;
		len++;
	}
	return (len);
}
/* 
int main(void)
{
	unsigned long number = 254123;
	//int base = 16;
	//int base = 10;
	//int base = 8;
	int base = 2;
	int digit_count = ft_count_digit(number, base);
	
	printf("Number of digits in %lu in base %d: %d\n", number, base, digit_count);
	return (0);
}
*/