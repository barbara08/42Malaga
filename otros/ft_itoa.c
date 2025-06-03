/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmartin- <bmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 16:17:28 by bmartin-          #+#    #+#             */
/*   Updated: 2025/05/23 18:22:43 by bmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//NO USO ESTA FUNCION, LA HE REEMPLAZADO POR LA FUNCION FT_PUTNBR
// LA DEJO POR SI SIRVE, PERO SON MAS DE 25 LINEAS	
// HAY QUE QUITARLA DEL MAKEFILE Y FT_PRINTF.H

#include "ft_printf.h"

char	*ft_itoa(int n)
{
	int		tmp;
	int		len;
	int		digit;
	char	*str;

	tmp = n;
	len = (n <= 0);
	while (tmp && ++len)
		tmp /= 10;
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (n == 0)
		str[0] = '0';
	if (n < 0)
		str[0] = '-';
	while (n)
	{
		digit = n % 10;
		if (digit < 0)
			digit = -digit;
		str[--len] = '0' + digit;
		n /= 10;
	}
	return (str);
}
