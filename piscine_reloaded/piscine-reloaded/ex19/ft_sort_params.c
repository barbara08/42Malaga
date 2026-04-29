/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmartin- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 18:43:04 by bmartin-          #+#    #+#             */
/*   Updated: 2025/04/15 19:46:07 by bmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char putchar);

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		i++;
	}
	return (s1[i] - s2[i]);
}

int	main(int argc, char *argv[])
{
	int	i;
	int	str;
	int	result;
	char	*pos;
	int	x;
	int	imp;

	i = 1;
	while (i < argc)
	{
		str = i + 1;
		while (str < argc)
		{
			result = ft_strcmp(argv[i], argv[str]);
			if (result > 0)
			{
				pos = argv[i];
				argv[i] = argv[str];
				argv[str] = pos;
			}
			str++;
		}
		i++;
	}
	x = 1;
	imp = 0;
	while (x < argc)
	{
		while (argv[x][imp] != '\0')
		{
			ft_putchar(argv[x][imp]);
			imp++;
		}
		imp = 0;
		ft_putchar('\n');
		x++;
	}
	return (0);
}
