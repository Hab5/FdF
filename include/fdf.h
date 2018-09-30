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

typedef struct s_all
{
    void *mlx;
    void *win;
}              t_all;

int						to_double_coord(
	long **ar,
	int x_sz,
	int y_sz,
	t_p **ret);

int						coordinate_tr(
	int i,
	int j,
	t_p *ar);

long int **allocate_grid(int x, int y);
long int **parse(int line, int column, char *map);
char *get_line(char *map);
int count_rows(char *map);
int count_columns(char *line);
#endif
