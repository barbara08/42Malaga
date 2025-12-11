#include "so_long.h"


// Función auxiliar para seleccionar y dibujar el tile
static void ft_draw_tile(t_game *game, int row, int col)
{
    char tile;
    void *img_ptr;
    int x;
    int y;

    tile = game->map_info->map[row][col];
    x = col * game->textures->img_size;
    y = row * game->textures->img_size;

    if (tile == '1')
        img_ptr = game->textures->wall;
    else if (tile == '0')
        img_ptr = game->textures->floor;
    else if (tile == 'C')
        img_ptr = game->textures->collect;
    else if (tile == 'P')
        img_ptr = game->textures->player;
    else if (tile == 'E')
        img_ptr = game->textures->exit;
    else
        return; // Caracter no reconocido (debería ser validado antes)

    // Dibujar la imagen
    mlx_put_image_to_window(game->mlx, game->window, img_ptr, x, y);
}

// Función principal para dibujar todo el mapa
void ft_draw_map(t_game *game)
{
    int row;
    int col;

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