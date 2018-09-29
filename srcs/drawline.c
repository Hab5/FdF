#include "mlx.h"
#include <stdio.h>
#include "../include/fdf.h"

void	draw_line(int x1, int y1, int x2, int y2, void *mlx, void *win)
{
    int dx, dy, sx, sy, err, e2;
    
    dx =  x2 - x1;
    dy = y2 - y1;
    err = (dx > dy ? dx : -dy) / 2;
    sx = x1 < x2 ? 1 : -1;
    sy = y1 < y2 ? 1 : -1;

    while (1)
    {
        mlx_pixel_put(mlx, win, x1, y1, 0x6400); 
        if (x1 == x2 && y1 == y2)
            break;
        e2 = err;
        if (e2 > -dx)
        {
            err -= dy;
            x1 += sx;
        }
        if ( e2 < dy )
        {
            err += dx;
            y1 += sy;
        }
    }
}


 int main(void)
{
    void *mlx_ptr;
    void *win_ptr;

    mlx_ptr = mlx_init();
    win_ptr = mlx_new_window(mlx_ptr, 500, 500, "pls work (500x500)");
    draw_line(0, 0, 235, 349, mlx_ptr, win_ptr);
    draw_line(250, 130, 250, 500, mlx_ptr, win_ptr);
    mlx_loop(mlx_ptr);
} 
