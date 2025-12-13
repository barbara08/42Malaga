#include "so_long.h"

// Función auxiliar para cargar una imagen
void *ft_load_img(t_game *game, char *path)
{
    void *img_ptr;
    int w, h;

    img_ptr = mlx_xpm_file_to_image(game->mlx, path, &w, &h);
    if (!img_ptr)
    {
        //salida del archivo que no es correcto
        fprintf(stderr, "Error: No se pudo cargar el archivo XPM: %s\n", path);
        perror("Error loading img XPM");
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
    
    game->textures->wall = ft_load_img(game, "assets/wall.xpm");
    game->textures->floor = ft_load_img(game, "assets/floor.xpm");
    game->textures->collect = ft_load_img(game, "assets/collect.xpm");
    game->textures->player = ft_load_img(game, "assets/player.xpm");
    game->textures->exit = ft_load_img(game, "assets/exit.xpm");
    game->textures->img_size = 32; // Establece el tamaño de tu tile
}
