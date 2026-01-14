#include "minilibx_opengl_20191021/mlx.h"

int main()
{
    void *mlx;
    void *window;

    mlx = mlx_init();
    window = mlx_new_window(mlx, 800, 600, "So Long Game");

    mlx_loop(mlx);
    return 0;
}