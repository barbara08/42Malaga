/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_digit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmartin- <bmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 13:00:56 by bmartin-          #+#    #+#             */
/*   Updated: 2025/05/26 19:34:47 by bmartin-         ###   ########.fr       */
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
	unsigned long n = 6524712543;
	//int base = 16;
	//int base = 10;
	//int base = 8; 
	int base = 2;
	int result = ft_count_digit(n, base);
	
	printf("Number of digits in base %d: %d\n", base, result);
	
	return 0;
}
*/