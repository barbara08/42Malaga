/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmartin- <bmartin-@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 14:28:57 by bmartin-          #+#    #+#             */
/*   Updated: 2025/12/19 14:29:00 by bmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_draw_tile(t_game *game, int row, int col)
{
	int	x;
	int	y;

	x = col * game->textures->img_size;
	y = row * game->textures->img_size;
	mlx_put_image_to_window(game->mlx, game->window, game->textures->floor,
		x, y);
	if (game->map_info->map[row][col] == 'E')
		mlx_put_image_to_window(game->mlx, game->window, game->textures->exit,
			x, y);
	if (game->map_info->map[row][col] == '1')
		mlx_put_image_to_window(game->mlx, game->window, game->textures->wall,
			x, y);
	else if (game->map_info->map[row][col] == 'C')
		mlx_put_image_to_window(game->mlx, game->window,
			game->textures->collect, x, y);
	if (row == game->player_y && col == game->player_x)
		mlx_put_image_to_window(game->mlx, game->window, game->textures->player,
			x, y);
}

void	ft_draw_map(t_game *game)
{
	int	row;
	int	col;

	row = 0;
	while (row < game->map_info->num_rows)
	{
		col = 0;
		while (col < game->map_info->num_columns)
		{
			ft_draw_tile(game, row, col);
			col++;
		}
		row++;
	}
}
