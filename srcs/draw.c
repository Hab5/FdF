#include "../include/fdf.h"

void draw_x(double ***coordtable, int y, int x, void *mlx, void *win)
{
    int i;
    int j;
    int draw[4];

    j = 0;
    while (j < y)
    {
        i = 0;
        while (i < x-1)
        {
            draw[0] = coordtable[i][j][0];
            draw[1] = coordtable[i][j][1];
            draw[2] = coordtable[i+1][j][0];
            draw[3] = coordtable[i+1][j][1];
            draw_line(draw, mlx, win);
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
    int draw[4];

    j = 0;
    while (j < y)
    {
        i = 0;
        while (i < x && j < y - 1)
        {
            draw[0] = coordtable[i][j][0];
            draw[1] = coordtable[i][j][1];
            draw[2] = coordtable[i][j+1][0];
            draw[3] = coordtable[i][j+1][1];
            draw_line(draw, mlx, win);
            //mlx_pixel_put(mlx, win, coordtable[i][j][0], coordtable[i][j][1], 0x00FFFF);
            i++;
        }
        j++;
    }
}
