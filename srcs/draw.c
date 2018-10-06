#include "../include/fdf.h"

int draw_x(double ***coordtable, int y, int x, void *mlx, void *win)
{
    int i;
    int j;
    int draw[4];

    j = -1;
    while (++j < y)
    {
        i = -1;
        while (++i < x-1)
        {
            draw[0] = coordtable[i][j][0];
            draw[1] = coordtable[i][j][1];
            draw[2] = coordtable[i+1][j][0];
            draw[3] = coordtable[i+1][j][1];
            draw_line(draw, mlx, win);
            //mlx_pixel_put(mlx, win, coordtable[i][j][0], coordtable[i][j][1], 0x00FFFF);
        }
    }
    return 1;
}

int draw_y(double ***coordtable, int y, int x, void *mlx, void *win)
{
    int i;
    int j;
    int draw[4];

    j = -1;
    while (++j < y - 1)
    {
        i = -1;
        while (++i < x)
        {
            draw[0] = coordtable[i][j][0];
            draw[1] = coordtable[i][j][1];
            draw[2] = coordtable[i][j+1][0];
            draw[3] = coordtable[i][j+1][1];
            draw_line(draw, mlx, win);
            //mlx_pixel_put(mlx, win, coordtable[i][j][0], coordtable[i][j][1], 0x00FFFF);
        }
    }
    return 1;
}
