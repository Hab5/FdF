#include "../include/fdf.h"

void draw_all(double ***positions, int x, int y, void *mlx, void *win)
{
    int i;
    int j;
    int pos[4];
    i = 0;
    j = 0;
    while (j != y)
    {
        while (i != x)
        {
            pos[0] = positions[i][j][0];
            pos[1] = positions[i][j][1];
            pos[2] = positions[i+1][j][0];
            pos[3] = positions[i+1][j][1];
            draw_line(pos, mlx, win);
        }
        j++;
        i = 0;
    }
    i++;
}


int main(int argc, char **argv)
{
    void *mlx;
    void *win;

    int x = count_columns(get_line(argv[1]));
    int y = count_rows(argv[1]);
    mlx = mlx_init();
    win = mlx_new_window(mlx, 1080, 720, "This is a test. (1080x 700)");
    
    long **grid = parse(x, y, argv[1]);
    double ***positions = iso_xy(grid, x, y);

    draw_all(positions, x, y, mlx, win);

    mlx_loop(mlx);
}
