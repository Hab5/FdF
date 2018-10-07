#include "../include/fdf.h"

void	draw_line(int draw[4], void *mlx, void *win)
{
    int dx, dy, sx, sy, err, e2;
    dx =  abs(draw[2] - draw[0]);
    dy = abs(draw[3] - draw[1]);
    err = (dx > dy ? dx : -dy) / 2;
    sx = draw[0] < draw[2] ? 1 : -1;
    sy = draw[1] < draw[3] ? 1 : -1;

    while (1)
    {
        mlx_pixel_put(mlx, win, draw[0], draw[1], COLOR); 
        if (draw[0] == draw[2] && draw[1] == draw[3])
            break;
        e2 = err;
        if (e2 > -dx)
        {
            err -= dy;
            draw[0] += sx;
        }
        if (e2 < dy)
        {
            err += dx;
            draw[1] += sy;
        }
    }
}

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
