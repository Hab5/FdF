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

int free_grid(long int ***gridref, const int y)
{
    int i;
    i = 0;

    if( i<0 || !gridref || !*gridref )
        return (0);

    while(i < y)
    {
        free((*gridref)[i]);
        (*gridref)[i] = NULL;
        i++;
    }

    free(*gridref);
    *gridref=NULL;
    return (1);
}

long int **parse(const int column, const int line, char *map)
{
    long int **grid;
    int y;
    int x;
    char *str;
    char *tmp;
    int fd;
    char **clean_str;

    grid = allocate_grid(column, line);
    y = -1;
    fd = open(map, O_RDONLY);
    while (++y < line)
    {
        get_next_line(fd, &str);
        tmp = ft_strtrim(str);
        clean_str = ft_strsplit(tmp, ' ');
        x = -1;
        while (++x < column)
        {
            grid[x][y] = ft_atoi(clean_str[x]);
        }
    }
    return(grid);
}
