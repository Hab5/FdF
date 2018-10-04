#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include "mlx.h"
# include "../gnl/get_next_line.h"

# define X 0
# define Y 1
# define Z 2

void print_input_ar(long **ar, int x_sz, int y_sz);

double ***allocate_xyz(const int x, const int y, const int z);
double ***iso_xy(long **grid, const int x, const int y);

void print_iso(double ***positions, int x, int y);
void print_grid(long **grid, int x, int y);

long int **allocate_grid(int x, int y);
char free_grid(long int ***gridref, const int i);
long int **parse(int line, int column, char *map);

char *get_line(char *map);
int count_rows(char *map);
int count_columns(char *line);

void draw_line(int pos[4], void *mlx_ptr, void *win_ptr);
void draw_coordtable(void *mlx, double ***positions, int y, int x, void *win);
#endif
