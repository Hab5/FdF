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
    win_ptr = mlx_new_window(mlx_ptr, 1080, 720, "pls work (800x700)");
    
    draw_line(0, 0, 70, 40, mlx_ptr, win_ptr);draw_line(70, 40, 140, 80, mlx_ptr, win_ptr);
    draw_line(0, 0, 0, 80, mlx_ptr, win_ptr);
    draw_line(0, 80, 70, 120, mlx_ptr, win_ptr);
    draw_line(0, 80, 0, 160, mlx_ptr, win_ptr);
    draw_line(0, 160, 70, 200, mlx_ptr, win_ptr);
    draw_line(0, 160, 0, 240, mlx_ptr, win_ptr);
    draw_line(0, 240, 70, 280, mlx_ptr, win_ptr);
    
    
    draw_line(70, 40, 70, 120, mlx_ptr, win_ptr);
    draw_line(70, 120, 70, 200, mlx_ptr, win_ptr);
    draw_line(70, 200, 70, 280, mlx_ptr, win_ptr);
    //draw_line(70, 200, 70, 240, mlx_ptr, win_ptr);
    mlx_loop(mlx_ptr);
} 
