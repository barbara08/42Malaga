/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmartin- <bmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 14:38:06 by bmartin-          #+#    #+#             */
/*   Updated: 2025/12/19 19:54:03 by bmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#define KEY_ESC		65307
#define KEY_W		119
#define KEY_A		97
#define KEY_S		115
#define KEY_D		100
#define KEY_Z		122
#define KEY_Q		113
#define KEY_UP		65362
#define KEY_LEFT	65361
#define KEY_DOWN	65364
#define KEY_RIGHT	65363

void	ft_find_initial_player_pos(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->map_info->num_rows)
	{
		x = 0;
		while (x < game->map_info->num_columns)
		{
			if (game->map_info->map[y][x] == 'P')
			{
				game->player_y = y;
				game->player_x = x;
				game->map_info->player_start_y = y;
				game->map_info->player_start_x = x;
				game->moves = 0;
				return ;
			}
			x++;
		}
		y++;
	}
}

int	ft_handle_tile_events(t_game *game, int new_x, int new_y)
{
	char	tile;

	tile = game->map_info->map[new_y][new_x];
	if (tile == 'E')
	{
		if (game->map_info->collections == 0)
		{
			write(1, "¡Congratulations!\n", 19);
			ft_close_game(game);
		}
	}
	if (tile == 'C')
		game->map_info->collections--;
	return (0);
}

void	ft_move_player(t_game *game, int dx, int dy)
{
	int	new_x;
	int	new_y;

	new_x = game->player_x + dx;
	new_y = game->player_y + dy;
	if (new_x < 0 || new_x >= game->map_info->num_columns
		|| new_y < 0 || new_y >= game->map_info->num_rows
		|| game->map_info->map[new_y][new_x] == '1')
		return ;
	if (ft_handle_tile_events(game, new_x, new_y))
		return ;
	if (game->player_x == game->map_info->exit_x
		&& game->player_y == game->map_info->exit_y)
		game->map_info->map[game->player_y][game->player_x] = 'E';
	else
		game->map_info->map[game->player_y][game->player_x] = '0';
	game->player_x = new_x;
	game->player_y = new_y;
	if (game->map_info->map[new_y][new_x] != 'E')
		game->map_info->map[new_y][new_x] = 'P';
	ft_putnbr_fd(++game->moves, 1);
	write(1, " movements\n", 11);
	ft_draw_map(game);
}

int	ft_handle_keypress(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		ft_close_game(game);
	else if (keycode == KEY_W || keycode == KEY_Z || keycode == KEY_UP)
		ft_move_player(game, 0, -1);
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		ft_move_player(game, 0, 1);
	else if (keycode == KEY_A || keycode == KEY_Q || keycode == KEY_LEFT)
		ft_move_player(game, -1, 0);
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		ft_move_player(game, 1, 0);
	return (0);
}
