#include "../include/fdf.h"
int main(int argc, char **argv)
{
	long int **grid;
	double ***positions;
	int x;
	int y;
    void *mlx;
    void *win;

	x = count_columns(get_line(argv[1]));
	y = count_rows(argv[1]);
    grid = parse(x, y, argv[1]);
    positions = iso_xy(grid, x, y);
    mlx = mlx_init();
    win = mlx_new_window(mlx, 1280, 720, "1280x720");

    draw_x(positions, y, x, mlx, win);
    draw_y(positions, y, x, mlx, win);

    printf("INPUT MAP: \n");
    print_grid(grid, x, y);
    printf("\n");
    //printf("ISOMETRIC MAPPING : \n");
    //print_iso(positions, x, y);
	free_grid(&grid, count_columns(get_line(argv[1])));

    mlx_loop(mlx);
    return 0;
}
