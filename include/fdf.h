#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include "mlx.h"
# include "../gnl/get_next_line.h"

typedef struct s_all
{
    void *mlx;
    void *win;
}              t_all;

long int **allocate_grid(int x, int y);
long int **parse(int line, int column, char *map);
char *get_line(char *map);
int count_rows(char *map);
int count_columns(char *line);
#endif
