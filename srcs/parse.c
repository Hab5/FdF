#include "../include/fdf.h"

long int **allocate_grid(const int x, const int y)
{
    int i = 0;
    long int **grid = malloc(sizeof(*grid) * x);
    while (i < x)
    {
        grid[i] = malloc(sizeof(grid[i]) * y);
        i++;
    }
    return grid;
}

char free_grid(long int ***gridref, const int i)
{
    if( i<0 || !gridref || !*gridref )
        return 0;
    
    int n;
    n = 0;

    while(n<i)
    {
        free((*gridref)[n]);
        (*gridref)[n] = NULL;
        n++;
    }
  
    free(*gridref), *gridref=NULL;
    return 1;
}

long int **parse(const int column, const int line, char *map)
{
    long int **grid; 
    grid = allocate_grid(column, line);
    
    int x = 0;
    int y = 0;
    char *str;
    char *tmp;
    int fd = open(map, O_RDONLY);
    char **clean_str = 0;
    
    while (y != line)
    {
        get_next_line(fd, &str);
        tmp = ft_strtrim(str);
        clean_str = ft_strsplit(tmp, ' ');
        while (x != column)
        {
            grid[x][y] = ft_atoi(clean_str[x]);
            x++;
        }
        x = 0;
        y++;
    }
    close(fd);
    return(grid);
}

static void					print_input_ar(
	long **ar,
	int x_sz,
	int y_sz)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
    while (y != y_sz)
    {
        while (x != x_sz)
        {
            printf("%ld ", ar[x][y]);
                x++;
        }
        printf("\n");
        x=0;
        y++;
    }
}

static void					print_tr_ar(
	t_p		*p_ar,
	int		x_sz,
	int		y_sz)
{
	t_p (*const	ar)[y_sz] = (t_p(*)[y_sz])p_ar;
	int		x;
	int		y;

	x = 0;
	y = 0;
    while (y != y_sz)
    {
        while (x != x_sz)
        {
			printf("x:%f, y:%f, z:%f\t", ar[x][y][X], ar[x][y][Y], ar[x][y][Z]);
                x++;
        }
        printf("\n");
        x=0;
        y++;
    }
}

int main(int argc, char **argv)
{
	long int	**array;
	t_p			*tr_array;
	int			column;
	int			line;

	(void)argc;
	tr_array = 0;
	column = count_columns(get_line(argv[1]));
	line = count_rows(argv[1]); 
	if ((array = parse(column, line, argv[1])) &&
		!to_double_coord(array, column, line, &tr_array) &&
		coordinate_tr(column, line, tr_array))
	{
			print_input_ar(array, column, line);
			print_tr_ar(tr_array, column, line);
	}
	if (tr_array)
		free(tr_array);
	if (array)
		free_grid(&array, count_columns(get_line(argv[1])));
    return 0; 
}
