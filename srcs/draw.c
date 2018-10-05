#include "../include/fdf.h"


void draw_x(void *mlx, double ***coordtable, int y, int x, void *win)
{
    int i;
    int j;
    int coordinates[4];

    j = 0;

    
    while (j < y)
    {
        i = 0;
        while (i < x)
        {
            coordinates[0] = coordtable[i][j][0];
            coordinates[1] = coordtable[i][j][1];
            if (i < x-1)
            {
                coordinates[2] = coordtable[i+1][j][0];
                coordinates[3] = coordtable[i+1][j][1];
                draw_line(coordinates, mlx, win);
            }
            //mlx_pixel_put(mlx, win, coordtable[i][j][0], coordtable[i][j][1], 0x00FFFF);
            i++;
        }
        j++;
    }
}

void draw_y(void *mlx, double ***coordtable, int y, int x, void *win)
{
    int i;
    int j;
    int coordinates[4];

    j = 0;

    
    while (j < y)
    {
        i = 0;
        while (i < x)
        {
            coordinates[0] = coordtable[i][j][0];
            coordinates[1] = coordtable[i][j][1];
            
            if (j < y-1)
            {
                coordinates[2] = coordtable[i][j+1][0];
                coordinates[3] = coordtable[i][j+1][1];
                draw_line(coordinates, mlx, win);
            }
            //mlx_pixel_put(mlx, win, coordtable[i][j][0], coordtable[i][j][1], 0x00FFFF);
            i++;
        }
        j++;
    }
}

int main(int argc, char **argv)
{
    void *mlx;
    void *win;

    int x = count_columns(get_line(argv[1]));
    int y = count_rows(argv[1]);
    mlx = mlx_init();
    win = mlx_new_window(mlx, 1270, 720, "800x700");

    long **grid = parse(x, y, argv[1]);
    double ***positions = iso_xy(grid, x, y);


    draw_x(win, positions, y, x, win);
    draw_y(win, positions, y, x, win);
    
    mlx_loop(mlx);
}
