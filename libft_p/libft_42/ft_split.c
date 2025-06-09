/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmartin- <bmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 18:00:10 by bmartin-          #+#    #+#             */
/*   Updated: 2025/05/13 18:57:25 by bmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_word(char const *s, char c)
{
	int	flag;
	int	save_words;
	int	i;

	flag = 1;
	save_words = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			flag = 1;
		if (s[i] != c && flag)
		{
			save_words++;
			flag = 0;
		}
		i++;
	}
	return (save_words);
}

static void	ft_free_all(char **list, int end_list)
{
	int	i;

	i = 0;
	while (i < end_list)
	{
		free(list[i]);
		i++;
	}
	free(list);
}

static char	**ft_fill_array(char **list, char const *s, int w_count, char c)
{
	int	i;
	int	w_len;

	i = 0;
	w_len = 0;
	while (i < w_count && *s)
	{
		while (*s == c)
			s++;
		w_len = 0;
		while (s[w_len] != c && s[w_len])
			w_len++;
		list[i] = ft_substr(s, 0, w_len);
		if (!list[i])
		{
			ft_free_all(list, i);
			return (NULL);
		}
		s = s + w_len + 1;
		i++;
	}
	list[i] = NULL;
	return (list);
}

char	**ft_split(char const *s, char c)
{
	int		w_count;
	char	**list;

	w_count = count_word(s, c);
	list = malloc((w_count + 1) * sizeof(char *));
	if (!list)
		return (NULL);
	list = ft_fill_array(list, s, w_count, c);
	return (list);
}
