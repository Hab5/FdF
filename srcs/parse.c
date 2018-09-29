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


int main(int argc, char **argv)
{
    long int **array = parse(count_columns(get_line(argv[1])), count_rows(argv[1]), argv[1]);
    
    int x = 0;
    int y = 0;
    int column = count_columns(get_line(argv[1]));
    int line = count_rows(argv[1]); 
    while (y != line)
    {
        while (x != column)
        {
            printf("%ld ", array[x][y]);
                x++;
        }
        printf("\n");
        x=0;
        y++;
    }

    free_grid(&array, count_columns(get_line(argv[1])));
    return 0; 
}
