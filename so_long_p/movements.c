#include "so_long.h"

// Los Keycodes de Linux para las flechas y WASD ZQSD
#define KEY_ESC     65307
#define KEY_W       119
#define KEY_A       97
#define KEY_S       115
#define KEY_D       100
#define KEY_Z       122
#define KEY_Q       113
#define KEY_UP      65362
#define KEY_LEFT    65361
#define KEY_DOWN    65364
#define KEY_RIGHT   65363



// Función auxiliar para buscar y guardar la posición inicial del jugador
// (Debe llamarse después de cargar el mapa en main.c)
void ft_find_initial_player_pos(t_game *game)
{
    int y = 0;
    int x;

    // Recorrer filas
    while (y < game->map_info->num_rows)
    {
        x = 0;
        // Recorrer columnas
        while (x < game->map_info->num_columns)
        {
            if (game->map_info->map[y][x] == 'P')
            {
                game->player_y = y;
                game->player_x = x;
                game->moves = 0;
                return ; // Jugador encontrado, salimos.
            }
            x++;
        }
        y++;
    }
}

// Función principal para gestionar un movimiento
void ft_move_player(t_game *game, int dx, int dy)
{
    int new_x;
    int new_y;
    char target_tile;

    new_x = game->player_x + dx;
    new_y = game->player_y + dy;

    // 1. Verificar límites del mapa (aunque el borde es '1', es una buena práctica)
    if (new_x < 0 || new_x >= game->map_info->num_columns ||
        new_y < 0 || new_y >= game->map_info->num_rows)
        return ;

    target_tile = game->map_info->map[new_y][new_x];

    // 2. Comprobar si es un muro
    if (target_tile == '1')
        return ; // No se puede mover a un muro
    
    // 3. Comprobar si es la salida
    if (target_tile == 'E')
    {
        if (game->map_info->collections == 0)
        {
            // ¡Ganaste!
            // 1. Escribir la primera parte del mensaje
            write(1, "¡Congratulations! You have won in", 34);
            write(1, " ", 1);
        
            // 2. Escribir el número de movimientos (game->moves + 1)
            ft_putnbr_fd(game->moves + 1, 1); 
        
            // 3. Escribir la parte final del mensaje (incluyendo el salto de línea '\n')
            write(1, " movements.\n", 12);

            //printf("¡Felicidades! Has ganado en %d movimientos.\n", game->moves + 1);
            mlx_loop_end(game->mlx); // Terminar el juego
        }
        return ; // No se puede salir si quedan coleccionables
    }

    // 4. Si llegamos aquí, el movimiento es válido (a '0' o 'C')

    // a) Limpiar la posición actual: Convertir 'P' a '0'
    game->map_info->map[game->player_y][game->player_x] = '0';

    // b) Actualizar coleccionables
    if (target_tile == 'C')
    {
        game->map_info->collections--;
        write(1, "Remaining collectibles: ", 24);
        ft_putnbr_fd(game->map_info->collections, 1);
        write(1, "\n", 1);
        //printf("Coleccionables restantes: %d\n", game->map_info->collections);
    }

    // c) Mover el jugador a la nueva posición
    game->player_y = new_y;
    game->player_x = new_x;
    game->map_info->map[new_y][new_x] = 'P';

    // d) Incrementar y mostrar movimientos
    game->moves++;
    write(1, "Movements: ", 11);
    ft_putnbr_fd(game->moves, 1);
    write(1, "\n", 1);
    //printf("Movimientos: %d\n", game->moves);

    // e) Redibujar el mapa (Refrescar la ventana)
    ft_draw_map(game);
}


// Función que maneja todas las pulsaciones
int ft_handle_keypress(int keycode, t_game *game)
{
    if (keycode == KEY_ESC)
        mlx_loop_end(game->mlx); // Lógica de salida que ya tienes
    else if (keycode == KEY_W || keycode == KEY_Z || keycode == KEY_UP)
        ft_move_player(game, 0, -1); // Mover Arriba (dy = -1)
    else if (keycode == KEY_S || keycode == KEY_DOWN)
        ft_move_player(game, 0, 1);  // Mover Abajo (dy = 1)
    else if (keycode == KEY_A || keycode == KEY_Q || keycode == KEY_LEFT)
        ft_move_player(game, -1, 0); // Mover Izquierda (dx = -1)
    else if (keycode == KEY_D || keycode == KEY_RIGHT)
        ft_move_player(game, 1, 0);  // Mover Derecha (dx = 1)
    return (0);
}


/* Los pasos que hace la funcion ft_move_player

static void ft_move_player(t_game *game, int dx, int dy)
{
    // Aquí irá la lógica para:
    // 1. Calcular la nueva posición (new_x, new_y)
    // 2. Verificar si el nuevo tile es un muro ('1'). Si lo es, no moverse.
    // 3. Si es coleccionable ('C'), recogerlo.
    // 4. Si es salida ('E'), verificar si se recogieron todos los coleccionables.
    // 5. Actualizar la posición del jugador en game->map_info->map
    // 6. Volver a dibujar el mapa (ft_draw_map(game))
    
    (void)game; // Esto es solo para evitar warnings temporales
    (void)dx;
    (void)dy;
}
*/