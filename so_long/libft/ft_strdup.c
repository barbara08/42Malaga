/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmartin- <bmartin-@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 14:51:45 by bmartin-          #+#    #+#             */
/*   Updated: 2025/12/19 14:51:49 by bmartin-         ###   ########.fr       */
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
