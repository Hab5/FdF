#include "./minilibx/mlx.h"

int main()
{
    void *mlx_ptr;
    void *mlx_window;

    mlx_ptr = mlx_init();
    mlx_window = mlx_new_window(mlx_ptr, 500, 600, "42");
    mlx_loop(mlx_ptr);
}
