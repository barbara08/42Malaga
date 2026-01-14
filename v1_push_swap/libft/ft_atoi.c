/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmartin- <bmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 18:42:37 by bmartin-          #+#    #+#             */
/*   Updated: 2025/05/06 18:09:34 by bmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	result;
	int	negative;

	result = 0;
	negative = 1;
	while (*nptr == ' ' || *nptr == '\t' || *nptr == '\v'
		|| *nptr == '\n' || *nptr == '\r' || *nptr == '\f')
	{
		nptr++;
	}
	if (*nptr == '-')
	{
		negative = -1;
		nptr++;
	}
	else if (*nptr == '+')
	{
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		result = result * 10 + (*nptr - '0');
		nptr++;
	}
	return (result * negative);
}
