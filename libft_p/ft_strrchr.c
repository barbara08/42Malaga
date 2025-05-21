/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmartin- <bmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 17:00:08 by bmartin-          #+#    #+#             */
/*   Updated: 2025/05/01 16:56:13 by bmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		len;
	char	*aux;
	char	caracther_c;

	len = ft_strlen(s);
	caracther_c = (char)c;
	while (len >= 0)
	{
		if (s[len] == caracther_c)
		{
			aux = (char *) &s[len];
			return (aux);
		}
		len--;
	}
	if (caracther_c == '\0')
	{
		aux = (char *) &s[len];
		return (aux);
	}
	else
		return (NULL);
}
