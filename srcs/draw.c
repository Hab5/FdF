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
 
  /*  int coordinates[4] = {200, 0, 200, 143};
    draw_line(coordinates, mlx, win);
    
    coordinates[0] = 200;
    coordinates[1] = 143;
    coordinates[2] = 200;
    coordinates[3] = 286;
    draw_line(coordinates, mlx, win);
    
    coordinates[0] = 200;
    coordinates[1] = 286;
    coordinates[2] = 200;
    coordinates[3] = 428;
    draw_line(coordinates, mlx, win);
    
    
    coordinates[0] = 200;
    coordinates[1] = 0;
    coordinates[2] = 200;
    coordinates[3] = 143;
    draw_line(coordinates, mlx, win);

    coordinates[0] = 200;
    coordinates[1] = 143;
    coordinates[2] = 200;
    coordinates[3] = 286;
    draw_line(coordinates, mlx, win);
    
    coordinates[0] = 200;
    coordinates[1] = 286;
    coordinates[2] = 200;
    coordinates[3] = 428;
    draw_line(coordinates, mlx, win);


    coordinates[0] = 437;
    coordinates[1] = 3;
    coordinates[2] = 243;
    coordinates[3] = 103;
    draw_line(coordinates, mlx, win);

    coordinates[0] = 145;
    coordinates[1] = 156;
    coordinates[2] = 243;
    coordinates[3] = 103;
    draw_line(coordinates, mlx, win);
    
    coordinates[0] = 243;
    coordinates[1] = 103;
    coordinates[2] = 340;
    coordinates[3] = 50;
    draw_line(coordinates, mlx, win);
*/


int main(int argc, char **argv)
{
    void *mlx;
    void *win;

    int x = count_columns(get_line(argv[1]));
    int y = count_rows(argv[1]);
    mlx = mlx_init();
    win = mlx_new_window(mlx, 800, 700, "800x700");

    long **grid = parse(x, y, argv[1]);
    double ***positions = iso_xy(grid, x, y);


    draw_x(win, positions, y, x, win);
    draw_y(win, positions, y, x, win);
    
    mlx_loop(mlx);
}
