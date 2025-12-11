/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmartin- <bmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 16:53:43 by bmartin-          #+#    #+#             */
/*   Updated: 2025/04/25 17:02:48 by bmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlenn(const char *s)
{
	size_t	i;
	size_t j;
	i = 0;
    j=0;
	while (s[i] != '\0')
	{
        if (s[i] != '\n')
		    j++;
		i++;
	}
	return (j);
}

//Original
/* 
size_t	ft_strlenn(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}
*/