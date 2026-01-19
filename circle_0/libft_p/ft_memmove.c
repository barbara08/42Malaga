/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmartin- <bmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 12:14:59 by bmartin-          #+#    #+#             */
/*   Updated: 2025/05/05 17:25:44 by bmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*ddest;
	const unsigned char	*ssrc;
	size_t				i;

	ddest = (unsigned char *)dest;
	ssrc = (unsigned char *)src;
	if (!ssrc && !ddest)
		return (NULL);
	i = n;
	if (ssrc < ddest)
	{
		while (i > 0)
		{
			i--;
			ddest[i] = ssrc[i];
		}
	}
	else
		ft_memcpy(ddest, ssrc, i);
	return ((void *)dest);
}
