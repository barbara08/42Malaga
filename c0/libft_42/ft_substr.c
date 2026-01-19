/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmartin- <bmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 12:50:53 by bmartin-          #+#    #+#             */
/*   Updated: 2025/05/09 14:40:58 by bmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*reserve_substr;
	size_t			i;

	i = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	reserve_substr = (char *)malloc((len + 1) * sizeof(char));
	if (!reserve_substr)
		return (NULL);
	while (i < len)
	{
		reserve_substr[i] = s[start + i];
		i++;
	}
	reserve_substr[i] = '\0';
	return (reserve_substr);
}
