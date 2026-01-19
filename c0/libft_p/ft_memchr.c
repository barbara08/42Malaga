/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmartin- <bmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 19:04:55 by bmartin-          #+#    #+#             */
/*   Updated: 2025/05/01 17:00:15 by bmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ss;
	unsigned char	cc;
	size_t			i;

	ss = (unsigned char *)s;
	cc = (char)c;
	i = 0;
	if (n == '\0')
		return (NULL);
	while (ss[i] != cc && i < n - 1)
	{
		i++;
	}
	if (cc == ss[i])
	{
		return ((void *) ss + i);
	}
	else
		return (NULL);
}
