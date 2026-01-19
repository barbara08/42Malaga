/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_caracter.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmartin- <bmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 13:00:45 by bmartin-          #+#    #+#             */
/*   Updated: 2025/05/26 19:33:15 by bmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_count_caracter(char *str)
{
	int	count;

	count = 0;
	if (str)
	{
		count += ft_putstr(str);
		//free(str);
	}
	return (count);
}

/* 
int main(void)
{
	char *str = "Querido Reyes Magos\n";
	int count = ft_count_caracter(str);
	printf("Number of characters printed: %d\n", count);
	return (0);
}
*/