/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmartin- <bmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 14:38:40 by bmartin-          #+#    #+#             */
/*   Updated: 2025/12/19 17:14:40 by bmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <fcntl.h> 
# include <stdio.h>
# include <string.h>
# include "minilibx-linux/mlx.h"
# include "./gnl/get_next_line.h"
# include "./libft/libft.h"
# include "structs.h"

//window.c
void	ft_manage_window(t_game *game);

//aux.c
int		ft_print_error(char *message);
int		ft_free_all(t_info_map *info, char *line);
int		ft_add_line(t_info_map *info, char *line);
int		ft_check_final(t_info_map *info_map);

//validate_map.c
int		ft_validate_file(char *file_path);
int		ft_validate_line(char *line, t_info_map *info_map);
int		ft_validate_characters(char *line, t_info_map *info_map, int pos);
void	ft_cut_newline(char *line);
int		ft_is_only_one(char *line);

//map.c
void	ft_init_map(t_info_map *info_map);
int		ft_readd_file(char *file_path, t_info_map *info_map);
int		ft_load_map(char *file_path, t_info_map *info_map);

int		ft_close_game(t_game *game);
int		ft_flood_fill(t_info_map *info_map);

//draw_map.c
void	ft_draw_tile(t_game *game, int row, int col);
void	ft_draw_map(t_game *game);

//textures.c
void	*ft_load_img(t_game *game, char *path);
int		ft_load_textures(t_game *game);

//movements.c
void	ft_find_initial_player_pos(t_game *game);
int		ft_handle_tile_events(t_game *game, int new_x, int new_y);
void	ft_move_player(t_game *game, int dx, int dy);
int		ft_handle_keypress(int keycode, t_game *game);

#endif
