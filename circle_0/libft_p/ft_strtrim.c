/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmartin- <bmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 19:22:39 by bmartin-          #+#    #+#             */
/*   Updated: 2025/05/11 17:44:40 by bmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char *s1, const char *set)
{
	int		start;
	int		end;
	int		len;
	char	*result;

	start = 0;
	end = ft_strlen(s1);
	while (s1[start] && ft_strchr(set, s1[start]) != NULL)
		start++;
	while (end > 0 && ft_strrchr(set, s1[end]) != NULL)
		end--;
	len = end - start;
	result = ft_substr(s1, start, len + 1);
	if (result == NULL)
		return (NULL);
	return (result);
}
