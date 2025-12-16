#include "so_long.h"


//void ft_destroy_game(t_game *game); // Prototipo para limpieza

int main(int argc, char **argv)
{
    t_game game;
    t_info_map info_map;
    
    if(argc != 2)
    {
        write(1, "Error you need a File\n", 22); //Solo poner Error\n
        return(0);
    }
    
    // Inicializar estructuras
    ft_init_map(&info_map);
    game.map_info = &info_map;
    game.textures = NULL;

    // 1. Validar y cargar mapa
    int map_ok;
    
    map_ok = ft_load_map(argv[1], &info_map); // Pasa la estructura info_map
    if (!map_ok)
    {
        write(1, "Error map no valid\n", 19);
        // Aquí debería limpiar la memoria del mapa antes de salir.
        // ft_free_map(&info_map); 
        return (0);
    }

    // 2. Inicializar MLX
    game.mlx = mlx_init();
    if (!game.mlx) 
        return (1); // Error de inicialización
    
        // 2b. Inicializar la posición del jugador
    ft_find_initial_player_pos(&game);

    // 3. Cargar Texturas
    ft_load_textures(&game);

    // 4. Crear ventana
    // Calcula el tamaño de la ventana basado en las dimensiones del mapa y el tamaño de la imagen (ej: 64)
    int width;
    int height;

    width = game.map_info->num_columns * 64;
    height = game.map_info->num_rows * 64;
    printf("resolution width %d x height %d\n", width, height);
    
    game.window = mlx_new_window(game.mlx, width, height, "So Long");
    if (!game.window) 
    { 
        // Limpiar mlx y salir
        //ft_destroy_game(&game);
        return (1); 
    }

    // 5. Manejo de la ventana (hooks)
    ft_manage_window(&game); 

    // 6. Dibujar el mapa
    ft_draw_map(&game);

    // 7. Bucle principal
    mlx_loop(game.mlx);

    // 8. Limpieza al salir
    //ft_destroy_game(&game);
    return (0);
}




/* ORIGINAL OK
int main(int argc, char **argv)
{
    void *mlx;
    void *window;

   if(argc != 2)
   {
    printf("Falta el file");
    return(0);
   }

    mlx = mlx_init();
    window = mlx_new_window(mlx, 800, 600, "So Long");
    manage_window(window, mlx);
    
    int map = load_map(argv[1]);
    printf("map %d", map);

    ft_draw_map();

    mlx_loop(mlx);
    return 0;
}
    */