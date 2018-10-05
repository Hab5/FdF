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

void drawline(int pos[4], void *mlx, void *win)
{
    int i;
    float j;
    float ratio;

    ratio =((float)pos[2] - (float)pos[3])/((float)pos[0] - (float)pos[1]);
    i = pos[1] - pos[0];
    j = (float)pos[3];

    while(i != 0)
    {
        mlx_pixel_put(mlx, win, i + pos[0], (int)j, 0xFF0000);
        i = (pos[1] > pos[0]) ? i - 1 : i + 1;
        j -= ratio;
    }
}


/*int main(void)
{
    void *mlx_ptr;
    void *win_ptr;
    int pos[4] = {0, 100, 0, 100};

    mlx_ptr = mlx_init();
    win_ptr = mlx_new_window(mlx_ptr, 800, 700, "pls work (800x700)");
    
    
    draw_line(pos, mlx_ptr, win_ptr);
    
    draw_line(pos, mlx_ptr, win_ptr);
    
    draw_line(437, 3, 534, 56, mlx_ptr, win_ptr);
    draw_line(534, 56, 632, 109, mlx_ptr, win_ptr);
   
    
    draw_line(48, 209, 145, 156, mlx_ptr, win_ptr);
    draw_line(145, 156, 243, 103, mlx_ptr, win_ptr);
    draw_line(243, 103, 340, 50, mlx_ptr, win_ptr);
    
    draw_line(340, 50, 437, 3, mlx_ptr, win_ptr);
    draw_line(340, 50, 437, 3, mlx_ptr, win_ptr);
    draw_line(340, 50, 437, 3, mlx_ptr, win_ptr);

    mlx_loop(mlx_ptr);
}*/
