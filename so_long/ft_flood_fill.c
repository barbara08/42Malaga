/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flood_fill.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmartin- <bmartin-@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 14:29:36 by bmartin-          #+#    #+#             */
/*   Updated: 2025/12/19 14:29:41 by bmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**make_area(char **zone, t_point size)
{
	char	**area;
	int		r;
	int		c;

	area = malloc(sizeof(char *) * (size.y + 1));
	if (area == NULL)
		return (NULL);
	r = 0;
	while (r < size.y)
	{
		area[r] = malloc(sizeof(char) * (size.x + 1));
		if (area[r] == NULL)
			return (NULL);
		c = 0;
		while (c < size.x)
		{
			area[r][c] = zone[r][c];
			c++;
		}
		area[r][size.x] = '\0';
		r++;
	}
	area[r] = NULL;
	return (area);
}

void	ft_free_area(char **area, int num_rows)
{
	int	i;

	i = 0;
	if (!area)
		return ;
	while (i < num_rows)
	{
		free(area[i]);
		i++;
	}
	free(area);
}

void	ft_fill(char **tab, t_point size, int y, int x)
{
	if (x < 0 || x >= size.x || y < 0 || y >= size.y)
		return ;
	if (tab[y][x] == '1' || tab[y][x] == 'F')
		return ;
	tab[y][x] = 'F';
	ft_fill(tab, size, y, x + 1);
	ft_fill(tab, size, y + 1, x);
	ft_fill(tab, size, y, x - 1);
	ft_fill(tab, size, y - 1, x);
}

int	ft_is_map_playable(char **map_copy, t_point size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size.y)
	{
		j = 0;
		while (j < size.x)
		{
			if (map_copy[i][j] == 'C' || map_copy[i][j] == 'E')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_flood_fill(t_info_map *info_map)
{
	t_point	size;
	t_point	begin;
	char	**map_copy;
	int		validation_result;

	size.x = info_map->num_columns;
	size.y = info_map->num_rows;
	begin.x = info_map->player_start_x;
	begin.y = info_map->player_start_y;
	map_copy = make_area(info_map->map, size);
	if (!map_copy)
		return (0);
	ft_fill(map_copy, size, begin.y, begin.x);
	validation_result = ft_is_map_playable(map_copy, size);
	ft_free_area(map_copy, size.y);
	return (validation_result);
}
