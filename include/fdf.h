#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include "mlx.h"
# include "gnl/get_next_line.h"

#define VRWIDTH 1200
#define VRHEIGHT 1200
#define OFFSETX 600
#define OFFSETY 50
#define RATIO 1
#define COLOR 0xff00

typedef struct  s_line
{
    int dx;
    int dy;
    int sx; 
    int sy; 
    int err; 
    int e2;
}               t_line;

long int **allocate_grid(int x, int y);
char **clean(char *str);
long int **parse(int line, int column, char *map);
double ***allocate_xyz(const int x, const int y, const int z);
double ***iso_xy(long **grid, const int x, const int y);

char *get_line(char *map);
int count_rows(char *map);
int count_columns(char *map);

t_line init_bresenham(int draw[4]);
void draw_line(int draw[4], void *mlx, void *win);
int draw_x(double ***positions, int y, int x, void *mlx, void *win);
int draw_y(double ***positions, int y, int x, void *mlx, void *win);

int key_exit(int key);
float key_down(int key);

#endif
