#include "so_long.h"

void ft_manage_window(t_game *game)
{
    // Evento de tecla presionada (ESC para salir)
    mlx_hook(game->window, 2, 1L << 0, ft_handle_keypress, game); 
    // Evento de "cerrar ventana" (clic en la X)
    mlx_hook(game->window, 17, 0, mlx_loop_end, game->mlx);
}



/*Antiguo código sin struct

La función ft_close_window ya no se usa ya que lo ha añadiddefinido en movements.c
static int ft_close_window(int keycode, void *param)
{
    if (keycode == 65307) // Si presionas ESC
    {
        mlx_loop_end(param);  // Finaliza el bucle de eventos
        return 0;
    }
    return 0;
}

void ft_manage_window(void *window, void *mlx)
{
    // Manejar el evento de "cerrar ventana" (clic en la "X" o ESC)
    mlx_hook(window, 2, 1L << 0, close_window, mlx); // Evento de tecla presionada (ESC para salir)
    mlx_hook(window, 17, 0, mlx_loop_end, mlx); // Evento de "cerrar ventana" (clic en la X)
}

*/