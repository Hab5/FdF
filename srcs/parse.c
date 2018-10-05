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

int free_grid(long int ***gridref, const int i)
{
    if( i<0 || !gridref || !*gridref )
        return (0);
    
    int n;
    n = 0;

    while(n < i)
    {
        free((*gridref)[n]);
        (*gridref)[n] = NULL;
        n++;
    }
  
    free(*gridref);
    *gridref=NULL;
    return (1);
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

void print_grid(long **grid, int x, int y)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
    while (j != y)
    {
        while (i != x)
        {
            printf("[%ld] ", grid[i][j]);
                i++;
        }
        printf("\n");
        i=0;
        j++;
    }
}
