/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmartin- <bmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 14:44:54 by bmartin-          #+#    #+#             */
/*   Updated: 2025/12/19 19:57:15 by bmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*ft_load_img(t_game *game, char *path)
{
	void	*img_ptr;
	int		w;
	int		h;

	img_ptr = mlx_xpm_file_to_image(game->mlx, path, &w, &h);
	if (!img_ptr)
	{
		ft_print_error("Failed to load XPM file");
		ft_close_game(game);
	}
	if (w != 64 || h != 64)
	{
		ft_print_error("Invalid image size. Must be 64x64");
		mlx_destroy_image(game->mlx, img_ptr);
		ft_close_game(game);
	}
	return (img_ptr);
}

int	ft_load_textures(t_game *game)
{
	game->textures = malloc(sizeof(t_images));
	if (!game->textures)
	{
		ft_print_error("Malloc failed for textures");
		return (0);
	}
	game->textures->wall = NULL;
	game->textures->floor = NULL;
	game->textures->collect = NULL;
	game->textures->player = NULL;
	game->textures->exit = NULL;
	game->textures->img_size = 64;
	game->textures->wall = ft_load_img(game, "assets/wall_64.xpm");
	game->textures->floor = ft_load_img(game, "assets/floor_64.xpm");
	game->textures->collect = ft_load_img(game, "assets/collect_64.xpm");
	game->textures->player = ft_load_img(game, "assets/player_64.xpm");
	game->textures->exit = ft_load_img(game, "assets/exit_64.xpm");
	if (!game->textures->wall || !game->textures->floor
		|| !game->textures->collect || !game->textures->player
		|| !game->textures->exit)
		return (ft_print_error("Failed to load one or more textures"), 0);
	return (1);
}
