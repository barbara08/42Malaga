/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmartin- <bmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 14:45:27 by bmartin-          #+#    #+#             */
/*   Updated: 2025/12/19 19:18:54 by bmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_validate_file(char *file_path)
{
	char	*extension;
	int		len_extension;
	int		len_file_path;
	int		i;

	if (file_path == NULL)
		return (0);
	extension = ".ber";
	len_extension = ft_strlen(extension);
	len_file_path = ft_strlen(file_path);
	if (len_file_path <= len_extension)
		return (0);
	i = 0;
	while (i < len_extension)
	{
		if (file_path[len_file_path - len_extension + i] != extension[i])
			return (0);
		i++;
	}
	return (1);
}

int ft_validate_characters(char *line, t_info_map *info_map, int pos)
{
	// 1. Si el carácter no es uno de los permitidos, error inmediato
	if (line[pos] != '1' && line[pos] != '0' && line[pos] != 'P'
		&& line[pos] != 'E' && line[pos] != 'C')
	{
		ft_print_error("Invalid character in map\n");
		return (0);
	}
	// 2. Validación y guardado del Jugador
	if (line[pos] == 'P')
	{
		if (info_map->player >= 1)
			return (ft_print_error("More than 1 Player\n"));
		info_map->player++;
		info_map->player_start_x = pos;
		info_map->player_start_y = info_map->num_rows;
	}
	// 3. Validación y guardado de la Salida
	else if (line[pos] == 'E')
	{
		if (info_map->exit >= 1)
			return (ft_print_error("More than 1 Exit\n"));
		info_map->exit++;
		info_map->exit_x = pos;
		info_map->exit_y = info_map->num_rows;
	}
	// 4. Conteo de coleccionables
	else if (line[pos] == 'C')
		info_map->collections++;
	return (1);
}

int	ft_validate_line(char *line, t_info_map *info_map)
{
	int	pos;
	int	last;

	last = info_map->num_columns - 1;
	if (line[0] != '1' || line[last] != '1')
	{
		ft_print_error("Map not closed by walls");
		return (0);
	}
	pos = 1;
	while (pos < last)
	{
		if (!ft_validate_characters(line, info_map, pos))
			return (0);
		pos++;
	}
	return (1);
}

void	ft_cut_newline(char *line)
{
	int	len;

	if (!line)
		return ;
	len = 0;
	while (line[len])
		len++;
	if (len > 0 && line[len - 1] == '\n')
		line[len - 1] = '\0';
}

int	ft_is_only_one(char *line)
{
	int	i;

	if (!line || line[0] == '\0')
		return (0);
	i = 0;
	while (line[i])
	{
		if (line[i] != '1')
			return (0);
		i++;
	}
	return (1);
}


/*original 


int	ft_validate_characters(char *line, t_info_map *info_map, int pos)
{
	if (line[pos] != '1' && line[pos] != 'P'
		&& line[pos] != 'E' && line[pos] != 'C' && line[pos] != '0')
		return (0);
	if (line[pos] == 'P')
	{
		if (info_map->player == 1)
			return (ft_print_error("more than 1 Player\n"));
		info_map->player = 1;
		info_map->player_start_x = pos;
		info_map->player_start_y = info_map->num_rows;
	}
	if (line[pos] == 'E')
	{
		if (info_map->exit == 1)
			return (ft_print_error("more than 1 Exit\n"));
		info_map->exit = 1;
		info_map->exit_x = pos;
		info_map->exit_y = info_map->num_rows;
	}
	if (line[pos] == 'C')
		info_map->collections++;
	return (1);
}

*/