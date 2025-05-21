/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmartin- <bmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 19:55:56 by bmartin-          #+#    #+#             */
/*   Updated: 2025/04/25 17:01:01 by bmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*dst;
	size_t			i;

	i = 0;
	dst = s;
	while (n > i)
	{
		dst[i] = c;
		i++;
	}
	s = (void *) dst;
	return (s);
}
