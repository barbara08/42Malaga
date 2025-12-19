#include "so_long.h"

static int	ft_close_game(t_game *game)
{
	// Aquí llamarías a tu función de liberar todo (texturas, mapa, mlx)
	// ft_free_all(game->map_info, NULL);
	mlx_destroy_window(game->mlx, game->window);
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

int	main(int argc, char **argv)
{
	t_game		game;
	t_info_map	info_map;

	if (argc != 2)
		return (ft_print_error("Usage: ./so_long [map.ber]"));
	ft_init_game(&game, &info_map);
	if (!ft_load_map(argv[1], &info_map))
		return (1);
	game.mlx = mlx_init();
	if (!game.mlx)
		return (ft_free_all(&info_map, NULL), 1);
	ft_find_initial_player_pos(&game);
	ft_load_textures(&game);
	game.window = mlx_new_window(game.mlx, info_map.num_columns * 64, \
					info_map.num_rows * 64, "so_long");
	if (!game.window)
		return (ft_free_all(&info_map, NULL), 1);
	ft_draw_map(&game);
	ft_manage_window(&game);
	// El hook 17 es para la X de la ventana, lo redirigimos a nuestra salida limpia
	mlx_hook(game.window, 17, 0, ft_close_game, &game);
	mlx_loop(game.mlx);
	return (0);
}
