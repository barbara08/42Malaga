/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmartin- <bmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 14:50:10 by bmartin-          #+#    #+#             */
/*   Updated: 2025/12/19 14:50:39 by bmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*destaux;
	unsigned const char	*srcaux;
	size_t				i;

	destaux = dest;
	srcaux = src;
	i = 0;
	if (destaux == NULL && srcaux == NULL)
		return (NULL);
	while (i < n)
	{
		destaux[i] = srcaux[i];
		i++;
	}
	dest = (void *) destaux;
	src = (void *) srcaux;
	return (dest);
}
