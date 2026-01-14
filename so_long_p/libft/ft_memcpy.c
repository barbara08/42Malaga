/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmartin- <bmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 13:48:05 by bmartin-          #+#    #+#             */
/*   Updated: 2025/04/29 20:06:25 by bmartin-         ###   ########.fr       */
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
	{
		return (NULL);
	}
	while (i < n)
	{
		destaux[i] = srcaux[i];
		i++;
	}
	dest = (void *) destaux;
	src = (void *) srcaux;
	return (dest);
}
