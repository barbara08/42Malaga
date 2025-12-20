/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmartin- <bmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 14:30:30 by bmartin-          #+#    #+#             */
/*   Updated: 2025/12/19 19:49:14 by bmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init_map(t_info_map *info_map)
{
	info_map->num_columns = 0;
	info_map->num_rows = 0;
	info_map->player = 0;
	info_map->exit = 0;
	info_map->collections = 0;
	info_map->player_start_x = 0;
	info_map->player_start_y = 0;
	info_map->exit_x = 0;
	info_map->exit_y = 0;
	info_map->map = NULL;
}

int	ft_readd_file(char *file_path, t_info_map *info_map)
{
	int		fd;
	char	*line;

	fd = open(file_path, O_RDONLY);
	if (fd == -1)
		return (ft_print_error("Opening file\n"));
	line = get_next_line(fd);
	while (line)
	{
		ft_cut_newline(line);
		if (info_map->num_rows == 0)
			info_map->num_columns = (int)ft_strlen(line);
		if (info_map->num_columns != (int)ft_strlen(line))
		{
			ft_print_error("Map is not rectangular\n");
			ft_free_all(info_map, line);
			close(fd);
			return (0);
		}
		if (!ft_validate_line(line, info_map))
		{
			ft_free_all(info_map, line);
			close(fd);
			return (0);
		}
		if (!ft_add_line(info_map, line))
		{
			close(fd);
			return (0);
		}
		free(line);
	}
	close(fd);
	return (1);
}

int	ft_load_map(char *file_path, t_info_map *info_map)
{
	ft_init_map(info_map);
	if (!ft_validate_file(file_path))
		return (ft_print_error("Invalid file extension\n"));
	if (!ft_readd_file(file_path, info_map))
		return (0);
	if (!ft_check_final(info_map))
		return (0);
	if (!ft_flood_fill(info_map))
	{
		ft_print_error("Map is not playable\n");
		return (ft_free_all(info_map, NULL));
	}
	return (1);
}
