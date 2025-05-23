/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmartin- <bmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 13:01:10 by bmartin-          #+#    #+#             */
/*   Updated: 2025/05/23 16:55:18 by bmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_format(char specifier, va_list args)
{
	char	*base_ten;
	char	*base_may;
	char	*base_min;

	base_ten = "0123456789";
	base_may = "0123456789ABCDEF";
	base_min = "0123456789abcdef";
	if (specifier == 'u')
		return (ft_converse_base(va_arg(args, unsigned int), base_ten));
	else if (specifier == 'x')
		return (ft_converse_base(va_arg(args, unsigned int), base_min));
	else if (specifier == 'X')
		return (ft_converse_base(va_arg(args, unsigned int), base_may));
	return (NULL);
}
