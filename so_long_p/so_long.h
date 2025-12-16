#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <fcntl.h> 
# include <stdio.h>
# include <string.h>


//Para Mac
//#include "minilibx_opengl_20191021/mlx.h"

//Para Linux
#include "minilibx-linux/mlx.h"

#include "./gnl/get_next_line.h"
#include "./libft/libft.h"

 typedef struct s_info_map{
    int num_columns;
    int num_rows;
    char **map;
    int player;
    int exit;
    int collections;
    //Para el Player
    int player_start_x; 
    int player_start_y;
 } t_info_map;

typedef struct s_images {
    void *wall;      // Wall '1'
    void *floor;     // Space Empty '0'
    void *collect;   // Collections 'C'
    void *player;    // Player 'P'
    void *exit;      // Exit 'E'
    int img_size;    // Imagen Size (ej: 64)
} t_images;

typedef struct s_game {
    void *mlx;       // Ptr mlx
    void *window;       // Ptr Window
    t_info_map *map_info; // Info map (num_rows, num_columns, map)
    t_images *textures; // Textures load
    // --- Posición del jugador ---
    int player_x; // Columna (dx)
    int player_y; // Fila (dy)
    int moves;    // Contador de movimientos
} t_game;


//window.c
void ft_manage_window(t_game *game);

//map.c
int ft_validate_file(char *file_path);
int ft_validate_line(char *line, t_info_map *info_map);
void ft_cut_newline(char *line);
int ft_readd_file(char *file_path, t_info_map *info_map);
int ft_is_only_one(char *line);
void ft_init_map(t_info_map *info_map);
int ft_load_map(char *file_path, t_info_map *info_map);
int ft_flood_fill(t_info_map *info_map);

//draw_map.c
void ft_draw_tile(t_game *game, int row, int col);
void ft_draw_map();

//textures.c
void *ft_load_img(t_game *game, char *path);
void ft_load_textures(t_game *game);

//movements.c
void ft_find_initial_player_pos(t_game *game);
void ft_move_player(t_game *game, int dx, int dy);
int ft_handle_keypress(int keycode, t_game *game);

#endif