/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmartin- <bmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 14:27:13 by bmartin-          #+#    #+#             */
/*   Updated: 2025/12/19 19:45:15 by bmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_print_error(char *message)
{
	write(2, "Error ", 6);
	if (message)
	{
		write(2, message, ft_strlen(message));
		if (message[ft_strlen(message) - 1] != '\n')
			write(2, "\n", 1);
	}
	return (0);
}

int	ft_free_all(t_info_map *info, char *line)
{
	int	i;

	if (line)
	{
		free(line);
		line = NULL;
	}
	if (info && info->map)
	{
		i = 0;
		while (i < info->num_rows)
		{
			if (info->map[i])
				free(info->map[i]);
			i++;
		}
		free(info->map);
		info->map = NULL;
		info->num_rows = 0;
	}
	return (0);
}

int	ft_add_line(t_info_map *info, char *line)
{
	char	**temp_map;

	if (line[0] != '1' || line[info->num_columns - 1] != '1')
	{
		ft_print_error("Map not closed by walls\n");
		return (ft_free_all(info, line));
	}
	temp_map = malloc(sizeof(char *) * (info->num_rows + 1));
	if (!temp_map)
		return (ft_free_all(info, line));
	if (info->num_rows > 0)
	{
		ft_memcpy(temp_map, info->map, sizeof(char *) * info->num_rows);
		free(info->map);
	}
	info->map = temp_map;
	info->map[info->num_rows] = ft_strdup(line);
	if (!info->map[info->num_rows])
		return (ft_free_all(info, line));
	info->num_rows++;
	return (1);
}

int	ft_check_final(t_info_map *info_map)
{
	if (info_map->num_rows < 3)
	{
		ft_print_error("Map too small\n");
		return (ft_free_all(info_map, NULL));
	}
	if (info_map->player != 1 || info_map->exit != 1
		|| info_map->collections < 1)
	{
		ft_print_error("Missing components (P, E or C)\n");
		return (ft_free_all(info_map, NULL));
	}
	if (!ft_is_only_one(info_map->map[info_map->num_rows - 1]))
	{
		ft_print_error("Map not closed by walls\n");
		return (ft_free_all(info_map, NULL));
	}
	return (1);
}
