#include "../include/fdf.h"

int key_exit(int key)
{
    if (key == 53)
    {
        exit(EXIT_SUCCESS);
    }
    return (0);
}

int main(int argc, char **argv)
{
	long int **grid;
	double ***positions;
	int x;
	int y;
    void *mlx;
    void *win;
    (void)argc;

	x = count_columns(argv[1]);
	y = count_rows(argv[1]);
    grid = NULL;
    if(!(grid = parse(x, y, argv[1])))
        return 0;
    positions = iso_xy(grid, x, y);
    mlx = mlx_init();
    win = mlx_new_window(mlx, 1280, 720, "1280x720");

    mlx_key_hook(win, key_exit, mlx);
    draw_x(positions, y, x, mlx, win);
    draw_y(positions, y, x, mlx, win);
    mlx_loop(mlx);
    return 0;
}
