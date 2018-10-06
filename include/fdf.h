#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include "mlx.h"
# include "../gnl/get_next_line.h"

#define WIDTH 800
#define HEIGHT 700
#define COLOR 0xff00
#define RATIO 1

double ***allocate_xyz(const int x, const int y, const int z);
double ***iso_xy(long **grid, const int x, const int y);

long int **allocate_grid(int x, int y);
int free_grid(long int ***gridref, const int i);
long int **parse(int line, int column, char *map);

char *get_line(char *map);
int count_rows(char *map);
int count_columns(char *map);

void draw_line(int draw[4], void *mlx, void *win);
int draw_x(double ***positions, int y, int x, void *mlx, void *win);
int draw_y(double ***positions, int y, int x, void *mlx, void *win);

int key_exit(int key);
float key_down(int key);
#endif
