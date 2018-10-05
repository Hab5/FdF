#include "mlx.h"
#include <stdio.h>
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
        mlx_pixel_put(mlx, win, draw[0], draw[1], 0x6400); 
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
