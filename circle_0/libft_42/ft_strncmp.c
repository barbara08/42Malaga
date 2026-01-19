/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmartin- <bmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 17:59:16 by bmartin-          #+#    #+#             */
/*   Updated: 2025/05/01 17:06:28 by bmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	size_t			result;
	unsigned char	*ss1;
	unsigned char	*ss2;

	ss1 = (unsigned char *)s1;
	ss2 = (unsigned char *)s2;
	i = 0;
	result = 0;
	while ((ss1[i] != '\0' || ss2[i] != '\0') && (i < n))
	{
		if (ss1[i] != ss2[i])
		{
			result = ss1[i] - ss2[i];
			return (result);
		}
		i++;
	}
	return (result);
}
