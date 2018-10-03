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

typedef double	(t_p)[3];
typedef double  (t_xy)[2];

typedef struct s_all
{
    void *mlx;
    void *win;
}              t_all;

void print_input_ar(long **ar, int x_sz, int y_sz);

double ***allocate_xyz(const int x, const int y, const int z);
double ***iso_x(double ***positions, long **grid, const int x, const int y);
double ***iso_y(double ***positions, long **grid, const int x, const int y);
double ***iso(long **grid, const int x, const int y);

void print_iso(double ***positions, int x, int y);
void print_grid(long **grid, int x, int y);

long int **allocate_grid(int x, int y);
char free_grid(long int ***gridref, const int i);
long int **parse(int line, int column, char *map);

char *get_line(char *map);
int count_rows(char *map);
int count_columns(char *line);
#endif
