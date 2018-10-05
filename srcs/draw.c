#include "../include/fdf.h"

void draw_x(double ***coordtable, int y, int x, void *mlx, void *win)
{
    int i;
    int j;
    int coordinates[4];

    j = 0;
    while (j < y)
    {
        i = 0;
        while (i < x-1)
        {
            coordinates[0] = coordtable[i][j][0];
            coordinates[1] = coordtable[i][j][1];
                coordinates[2] = coordtable[i+1][j][0];
                coordinates[3] = coordtable[i+1][j][1];
                draw_line(coordinates, mlx, win);
            //mlx_pixel_put(mlx, win, coordtable[i][j][0], coordtable[i][j][1], 0x00FFFF);
            i++;
        }
        j++;
    }
}

void draw_y(double ***coordtable, int y, int x, void *mlx, void *win)
{
    int i;
    int j;
    int coordinates[4];

    j = 0;
    while (j < y)
    {
        i = 0;
        while (i < x && j < y - 1)
        {
            coordinates[0] = coordtable[i][j][0];
            coordinates[1] = coordtable[i][j][1];
            coordinates[2] = coordtable[i][j+1][0];
            coordinates[3] = coordtable[i][j+1][1];
            draw_line(coordinates, mlx, win);
            //mlx_pixel_put(mlx, win, coordtable[i][j][0], coordtable[i][j][1], 0x00FFFF);
            i++;
        }
        j++;
    }
}

/*int main(int argc, char **argv)
{
    void *mlx;
    void *win;

    int x = count_columns(get_line(argv[1]));
    int y = count_rows(argv[1]);
    mlx = mlx_init();
    win = mlx_new_window(mlx, 1280, 720, "1280x720");

    long **grid = parse(x, y, argv[1]);
    double ***positions = iso_xy(grid, x, y);

    draw_x(positions, y, x, mlx, win);
    draw_y(positions, y, x, mlx, win);
    
    mlx_loop(mlx);
}*/
