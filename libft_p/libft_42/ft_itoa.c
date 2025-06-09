/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmartin- <bmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 12:29:54 by bmartin-          #+#    #+#             */
/*   Updated: 2025/05/12 16:26:48 by bmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digit(long int n)
{
	int	count_len_n;

	count_len_n = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = -n;
		count_len_n++;
	}
	while (n > 0)
	{
		n = n / 10;
		count_len_n++;
	}
	return (count_len_n);
}

char	*ft_itoa(int n)
{
	char		*str;
	int			co_dig;
	long int	number;

	number = n;
	co_dig = count_digit(number);
	if (number == 0)
		return (ft_strdup("0"));
	if (number < 0)
		number = -number;
	str = (char *)ft_calloc((co_dig + 1), sizeof(char));
	if (str == NULL)
		return (NULL);
	str[0] = '-';
	while (number > 0)
	{
		str[co_dig - 1] = '0' + (number % 10);
		number = number / 10;
		co_dig--;
	}
	return (str);
}
