#include "so_long.h"


//TODAS LAS FUNCIONES DE MAP.C ARREGLADO POR LA NORMA
//FALTA SEPARAR LAS FUNCIONES, LAS TENGO ANOTADAS EN PAPEL
//FALTA ANOTAR EN MAKEFILE Y EN EL .h LAS NUEVAS FUNCIONES 
int	ft_validate_file(char *file_path)
{
	char *extension;
	int len_extension;
	int len_file_path;
	int i;

	if(file_path == NULL)
		return(0);
	extension = ".ber";
	len_extension = ft_strlen(extension);
	len_file_path = ft_strlen(file_path);
	if (len_file_path <= len_extension)
		return(0);
	i = 0;
	while(i < len_extension)
	{
		if (file_path[len_file_path - len_extension + i] != extension[i])
			return(0);
		i++;
	}
	return(1);
}

int	ft_print_error(char *message)
{
	write(2, "Error -----\n", 12);
	if (message)
	{
		write(2, message, ft_strlen(message));
		write(2, "\n", 1);
	}
	return (0);
}
//Lo dejo por si acaso, pero es la funcion anterior
int	ft_pprint_error(char *message)
{
	perror(message);
		return (0);
}

int ft_validate_characters(char *line, t_info_map *info_map, int pos)
{
	if (line[pos] != '1' && line[pos] != 'P' 
			&& line[pos] != 'E' && line[pos] != 'C' && line[pos] != '0')
			return(0);
		if (line[pos] =='P')
		{
			if (info_map->player == 1)
				return (ft_print_error("Error more than 1 Player\n"));
			info_map->player = 1;
			info_map->player_start_x = pos;
			info_map->player_start_y = info_map->num_rows;
		}
		if(line[pos] == 'E')
		{
			if(info_map->exit == 1)
				return(ft_print_error("Error more than 1 Exit\n"));
			info_map->exit = 1;
			info_map->exit_x = pos;
			info_map->exit_y = info_map->num_rows;
		}
		if(line[pos] == 'C')
			info_map->collections++;
	return(1);
}

int	ft_validate_line(char *line, t_info_map *info_map)
{
	int	pos;
	int	last;

	last = info_map->num_columns - 1;
	if (line[0] != '1' || line[last] != '1')
		return (0);
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
	int len;

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

	i = 0;
	while(line[i])
	{
		if(line[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

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

int	ft_free_all(t_info_map *info, char *line)
{
	int	i;

	if (info && info->map)
	{
		i = 0;
		while (i < info->num_rows)
		{
			free(info->map[i]);
			i++;
		}
		free(info->map);
		info->map = NULL;
	}
	if (line)
		free(line);
	return (0);
}

int	ft_add_line(t_info_map *info, char *line)
{
	char	**temp_map;

	temp_map = malloc(sizeof(char *) * (info->num_rows + 1));
	if (!temp_map)
		return (ft_print_error("Error malloc map"), ft_free_all(info, line));
	if (info->num_rows > 0)
	{
		ft_memcpy(temp_map, info->map, sizeof(char *) * info->num_rows);
		free(info->map);
	}
	info->map = temp_map;
	info->map[info->num_rows] = ft_strdup(line);
	if (!info->map[info->num_rows])
		return (ft_print_error("Error strdup"), ft_free_all(info, line));
	info->num_rows++;
	return (1);
}

int	ft_check_final(t_info_map *info_map)
{
	if (info_map->num_rows < 3)
		return (ft_print_error("Error: Map too small\n"));
	if (info_map->player != 1 || info_map->exit != 1 || info_map->collections < 1)
		return (ft_print_error("Error: Invalid number of P, E or C\n"));
	if (!ft_is_only_one(info_map->map[info_map->num_rows - 1]))
		return (ft_print_error("Error: Last wall not closed\n"));
	return (1);
}

int	ft_readd_file(char *file_path, t_info_map *info_map)
{
	int		fd;
	char	*line;

	fd = open(file_path, O_RDONLY);
	if (fd == -1)
		return (ft_print_error("Error opening file\n"));
	line = get_next_line(fd);
	while (line)
	{
		ft_cut_newline(line);
		if (info_map->num_rows == 0 && !ft_is_only_one(line))
			return (ft_free_all(info_map, line));
		if (info_map->num_rows == 0)
			info_map->num_columns = ft_strlen(line);
		if (info_map->num_columns != (int)ft_strlen(line))
			return (ft_print_error("Map Error\n"), ft_free_all(info_map, line));
		if (!ft_validate_line(line, info_map) || !ft_add_line(info_map, line))
			return (ft_free_all(info_map, line));
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	if (!ft_check_final(info_map))
		return (ft_free_all(info_map, NULL));
	return (1);
}

int	ft_load_map(char *file_path, t_info_map *info_map)
{
	ft_init_map(info_map);
	if (!ft_validate_file(file_path))
		return (ft_print_error("Error: Invalid file extension\n"));
	if (!ft_readd_file(file_path, info_map))
		return (0); // ft_readd_file ya llama a ft_free_all internamente
	if (!ft_flood_fill(info_map))
	{
		ft_print_error("Error: Map is not playable\n");
		return (ft_free_all(info_map, NULL));
	}
	return (1);
}
