/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmartin- <bmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 14:41:46 by bmartin-          #+#    #+#             */
/*   Updated: 2025/12/19 14:44:36 by bmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_info_map
{
	int		num_columns;
	int		num_rows;
	char	**map;
	int		player;
	int		exit;
	int		collections;
	//Starting position of player 'P'
	int		player_start_x;
	int		player_start_y;
	// For 'E'
	int		exit_x;
	int		exit_y;
}	t_info_map;

typedef struct s_images
{
	void	*wall;		// Wall '1'
	void	*floor;		// Space Empty '0'
	void	*collect;	// Collections 'C'
	void	*player;	// Player 'P'
	void	*exit;		// Exit 'E'
	int		img_size;	// Imagen Size (ex: 64)
}	t_images;

typedef struct s_game
{
	void		*mlx;			// Ptr mlx
	void		*window;		// Ptr Window
	t_info_map	*map_info;		// Info map (num_rows, num_columns, map)
	t_images	*textures;		// Textures load
	// Player position
	int			player_x;		// Column (dx)
	int			player_y;		// Row (dy)
	int			moves;			// Movement counter
}	t_game;

// For function ft_flood_fill
typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

#endif
