#include "../include/fdf.h"
#include <stdio.h>
#include <unistd.h>
#include "../gnl/get_next_line.h"

char *get_line(char *map)
{
    int fd;
    char *str;
    char *line;

    fd = open(map, O_RDONLY);
    while(get_next_line(fd, &str)!= 0)
    {
        line = str;
    }
    return(line);
}

int count_rows(char *map)
{
    int fd;
    char *str;
    int lines;

    lines = 0;
    fd = open(map, O_RDONLY);
    
    while (get_next_line(fd, &str) != 0)
    {
        lines++;
    }
    return(lines);
}

int count_columns(char *line)
{
    int i;
    int space;

    space = 0;
    i = 0;
    while(line[i++])
    {
        if (line[i] == ' ' && line[i - 1] != ' ')
            space++;
    }
    if (line[ft_strlen(line) - 1] != ' ')
        return(space + 1);
    return (space);

}

/*int main(int argc, char **argv)
{
    printf("len: %ld\n", ft_strlen(get_line(argv[1])));
    printf("Rows : %d\n", count_rows(argv[1]));
    printf("Columns : %d\n", count_columns(get_line(argv[1]))); 
    return (0);
}*/
