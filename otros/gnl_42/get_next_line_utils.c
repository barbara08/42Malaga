/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmartin- <bmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 12:50:22 by bmartin-          #+#    #+#             */
/*   Updated: 2025/06/03 14:13:51 by bmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	src_len;
	size_t	i;

	if (!src || !dst)
		return (0);
	src_len = ft_strlen(src);
	i = 0;
	if (size == 0)
		return (src_len);
	while (src[i] != '\0' && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	if (!src)
		return (0);
	if (!dst && size == 0)
		return (ft_strlen(src));
	if (!dst)
		return (0);
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (size <= dst_len)
		return (src_len + size);
	i = 0;
	while (src[i] != '\0' && (dst_len + i) < size - 1)
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*reserve_join;

	if (!s1)
		s1 = "";
	if (!s2)
		s2 = "";
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	reserve_join = malloc((s1_len + s2_len + 1) * sizeof(char));
	if (!reserve_join)
		return (NULL);
	ft_strlcpy(reserve_join, s1, s1_len + s2_len + 1);
	ft_strlcat(reserve_join, s2, s1_len + s2_len + 1);
	return (reserve_join);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*aux;
	char	char_c;

	i = 0;
	char_c = (char)c;
	if (!s)
		return (NULL);
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
