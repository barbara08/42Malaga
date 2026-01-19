/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmartin- <bmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 13:34:54 by bmartin-          #+#    #+#             */
/*   Updated: 2025/05/07 16:45:38 by bmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*copys;
	int		i;

	copys = (char *)malloc(ft_strlen(s) + 1 * sizeof(char));
	i = 0;
	if (copys == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		copys[i] = s[i];
		i++;
	}
	copys[i] = '\0';
	return (copys);
}
