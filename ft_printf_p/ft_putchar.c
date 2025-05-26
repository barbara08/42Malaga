/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmartin- <bmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 13:02:11 by bmartin-          #+#    #+#             */
/*   Updated: 2025/05/26 19:35:50 by bmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

/* 
int main(void)
{
	char c = 'A';
	int count = ft_putchar(c);
	printf("\nCharacter '%c' printed, count: %d\n", c, count);
	return 0;
}
*/