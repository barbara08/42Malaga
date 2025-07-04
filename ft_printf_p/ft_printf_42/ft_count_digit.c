/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_digit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmartin- <bmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 12:00:40 by bmartin-          #+#    #+#             */
/*   Updated: 2025/06/09 12:11:51 by bmartin-         ###   ########.fr       */
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
