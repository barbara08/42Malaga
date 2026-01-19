/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converse_base.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmartin- <bmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 13:00:22 by bmartin-          #+#    #+#             */
/*   Updated: 2025/06/03 12:23:44 by bmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_converse_base(unsigned long n, char *base_str)
{
	int		base;
	int		len;
	char	*str;

	base = 0;
	while (base_str[base])
		base++;
	len = ft_count_digit(n, base);
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (len--)
	{
		str[len] = base_str[n % base];
		n /= base;
	}
	return (str);
}
/* 
int main(void)
{
	unsigned long n = 2512452145521;
	//char *base_str = "0123456789ABCDEF";
	//char *base_str = "01";
	//char *base_str = "0123456789";
	char *base_str = "01234567";
	char *result = ft_converse_base(n, base_str);
	
	if (result)
	{
		printf("Converted number: %s\n", result);
		free(result);
	}
	else
	{
		printf("Memory failed.\n");
	}
	
	return 0;
}
*/