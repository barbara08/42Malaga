/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_caracter.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmartin- <bmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 13:00:45 by bmartin-          #+#    #+#             */
/*   Updated: 2025/05/23 14:14:47 by bmartin-         ###   ########.fr       */
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
		free(str);
	}
	return (count);
}
