#include "so_long.h"

// Función auxiliar para cargar una imagen
void *ft_load_img(t_game *game, char *path)
{
	void *img_ptr;
	int w = 64;
	int h = 64;

	img_ptr = mlx_xpm_file_to_image(game->mlx, path, &w, &h);
	if (!img_ptr)
	{
		//salida del archivo que no es correcto, quitar esta linea, no lo pide
		fprintf(stderr, "Error: No se pudo cargar el archivo XPM: %s\n", path);
		//write(1, "Error loading img XPM\n", 22);
		ft_print_error("Error loading ......");
		//perror("Error loading img XPM");
		exit(1);
		// Añadir lógica para limpiar y salir
	}
	// Falta, asegurarnos de que todas las imágenes tengan el mismo tamaño.
	// if (w != h || w != 64) { ... }
	return (img_ptr);
}

// Función principal para cargar todas las texturas
void ft_load_textures(t_game *game)
{
    game->textures = (t_images *)malloc(sizeof(t_images));
    if (!game->textures)
        perror("Error de malloc para texturas");
    
    game->textures->wall = ft_load_img(game, "assets/wall_64.xpm");
    game->textures->floor = ft_load_img(game, "assets/floor_64.xpm");
    game->textures->collect = ft_load_img(game, "assets/collect_64.xpm");
    game->textures->player = ft_load_img(game, "assets/player_64.xpm");
    game->textures->exit = ft_load_img(game, "assets/exit_64.xpm");
    game->textures->img_size = 64; // El tamaño de tile
}
