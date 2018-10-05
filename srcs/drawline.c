#include "mlx.h"
#include <stdio.h>
#include "../include/fdf.h"

void	draw_line(int pos[4], void *mlx, void *win)
{
    int dx, dy, sx, sy, err, e2;
    dx =  abs(pos[2] - pos[0]);
    dy = abs(pos[3] - pos[1]);
    err = (dx > dy ? dx : -dy) / 2;
    sx = pos[0] < pos[2] ? 1 : -1;
    sy = pos[1] < pos[3] ? 1 : -1;

    while (1)
    {
        mlx_pixel_put(mlx, win, pos[0], pos[1], 0x6400); 
        if (pos[0] == pos[2] && pos[1] == pos[3])
            break;
        e2 = err;
        if (e2 > -dx)
        {
            err -= dy;
            pos[0] += sx;
        }
        if (e2 < dy)
        {
            err += dx;
            pos[1] += sy;
        }
    }
}
