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
    while(get_next_line(fd, &str) != 0)
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

int count_columns(char *map)
{
    int i;
    int space;
    char *line;

    line = get_line(map);
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
