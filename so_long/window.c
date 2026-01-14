/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmartin- <bmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 14:46:23 by bmartin-          #+#    #+#             */
/*   Updated: 2025/12/19 14:46:45 by bmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_manage_window(t_game *game)
{
	mlx_hook(game->window, 2, 1L << 0, ft_handle_keypress, game);
	mlx_hook(game->window, 17, 0, mlx_loop_end, game->mlx);
}
