/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmartin- <bmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 15:44:16 by bmartin-          #+#    #+#             */
/*   Updated: 2025/05/13 16:52:02 by bmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (*little == '\0')
		return ((char *)big);
	i = 0;
	while (big[i] && i < len)
	{
		j = 0;
		while ((big[i + j] == little[j]) && little[j] && ((i + j) < len))
		{
			j++;
		}
		if (little[j] == '\0')
			return ((char *)&big[i]);
		i++;
	}
	return (NULL);
}
