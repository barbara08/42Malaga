/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmartin- <bmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 20:07:23 by bmartin-          #+#    #+#             */
/*   Updated: 2025/05/07 18:24:42 by bmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*reserve_memory;
	size_t			i;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	reserve_memory = (unsigned char *)malloc(nmemb * size);
	if (reserve_memory == NULL)
		return (NULL);
	i = 0;
	while (i < nmemb * size)
	{
		reserve_memory[i] = 0;
		i++;
	}
	return ((void *)reserve_memory);
}
