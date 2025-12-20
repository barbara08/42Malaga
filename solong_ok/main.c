/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmartin- <bmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 14:30:01 by bmartin-          #+#    #+#             */
/*   Updated: 2025/12/19 17:19:03 by bmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_close_game(t_game *game)
{
	if (!game)
		exit(0);
	// 1. Liberar imágenes (Solo si la estructura de texturas existe)
	if (game->mlx && game->textures)
	{
		if (game->textures->wall)
			mlx_destroy_image(game->mlx, game->textures->wall);
		if (game->textures->player)
			mlx_destroy_image(game->mlx, game->textures->player);
		if (game->textures->collect)
			mlx_destroy_image(game->mlx, game->textures->collect);
		if (game->textures->exit)
			mlx_destroy_image(game->mlx, game->textures->exit);
		if (game->textures->floor)
			mlx_destroy_image(game->mlx, game->textures->floor);
		free(game->textures);
		game->textures = NULL;
	}
	// 2. Destruir ventana y MLX
	if (game->mlx)
	{
		if (game->window)
			mlx_destroy_window(game->mlx, game->window);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		game->mlx = NULL;
	}
	// 3. Liberar el mapa
	if (game->map_info)
		ft_free_all(game->map_info, NULL);
	exit(0);
	return (0);
}


static void	ft_init_game(t_game *game, t_info_map *info_map)
{
	ft_init_map(info_map);
	game->map_info = info_map;
	game->textures = NULL;
	game->mlx = NULL;
	game->window = NULL;
	game->moves = 0;
}
int main(int argc, char **argv)
{
    t_game      game;
    t_info_map  info_map;

    if (argc != 2)
        return (ft_print_error("Use => ./so_long [*.ber]"));
    
    ft_init_game(&game, &info_map);
    
    // 1. Cargar mapa: si falla, ft_load_map ya limpia dentro.
    if (!ft_load_map(argv[1], &info_map))
        return (1); 

    // 2. Inicializar MLX
    game.mlx = mlx_init();
    if (!game.mlx)
        return (ft_free_all(&info_map, NULL), 1);

    // 3. Buscar posición y cargar texturas
    ft_find_initial_player_pos(&game);
    if (!ft_load_textures(&game)) // <--- Si falla (devuelve 0)
        ft_close_game(&game);    // <--- Limpia mapa y MLX

    // 4. Crear Ventana
    game.window = mlx_new_window(game.mlx, info_map.num_columns * 64,
            info_map.num_rows * 64, "so_long");
    if (!game.window)
        ft_close_game(&game);

    ft_draw_map(&game);
    ft_manage_window(&game);
    
    // 5. Hooks y Loop
    mlx_hook(game.window, 17, 0, ft_close_game, &game);
    mlx_loop(game.mlx);
    return (0);
}


/*original
int	main(int argc, char **argv)
{
	t_game		game;
	t_info_map	info_map;

	if (argc != 2)
		return (ft_print_error("Use => ./so_long [*.ber]"));
	ft_init_game(&game, &info_map);
	if (!ft_load_map(argv[1], &info_map))
		return (1);
	game.mlx = mlx_init();
	if (!game.mlx)
		return (ft_free_all(&info_map, NULL), 1);
	ft_find_initial_player_pos(&game);
	ft_load_textures(&game);
	game.window = mlx_new_window(game.mlx, info_map.num_columns * 64,
			info_map.num_rows * 64, "so_long");
	if (!game.window)
		return (ft_free_all(&info_map, NULL), 1);
	ft_draw_map(&game);
	ft_manage_window(&game);
	mlx_hook(game.window, 17, 0, ft_close_game, &game);
	mlx_loop(game.mlx);
	return (0);
}*/
