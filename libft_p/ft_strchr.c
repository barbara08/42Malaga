/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmartin- <bmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 20:20:32 by bmartin-          #+#    #+#             */
/*   Updated: 2025/05/01 16:49:42 by bmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*aux;
	char	char_c;

	i = 0;
	char_c = (char)c;
	while (s[i] != '\0')
	{
		if (s[i] == char_c)
		{
			aux = (char *) &s[i];
			return (aux);
		}
		i++;
	}
	if (char_c == '\0')
	{
		aux = (char *) &s[i];
		return (aux);
	}
	else
		return (NULL);
}
