/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbellaic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 15:23:37 by mbellaic          #+#    #+#             */
/*   Updated: 2018/10/13 15:23:38 by mbellaic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

char				*get_line(char *map)
{
	int				fd;
	char			*str;
	char			*line;

	fd = open(map, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr("Invalid File.");
		exit(EXIT_SUCCESS);
	}
	while (get_next_line(fd, &str) != 0)
	{
		line = str;
	}
	return (line);
}

int					count_rows(char *map)
{
	int				fd;
	char			*str;
	int				lines;

	lines = 0;
	fd = open(map, O_RDONLY);
	while (get_next_line(fd, &str) != 0)
	{
		lines++;
	}
	return (lines);
}

int					count_columns(char *map)
{
	int				i;
	int				space;
	char			*line;

	line = get_line(map);
	space = 0;
	i = 0;
	while (line[i++])
	{
		if (line[i] == ' ' && line[i - 1] != ' ')
			space++;
	}
	if (line[ft_strlen(line) - 1] != ' ')
		return (space + 1);
	return (space);
}

char				**clean(char *str)
{
	char			**clean_str;
	char			*tmp;

	tmp = ft_strtrim(str);
	clean_str = ft_strsplit(tmp, ' ');
	return (clean_str);
}

long int			**parse(const int column, const int line, char *map)
{
	long int		**grid;
	char			*str;
	int				fd;
	char			**clean_str;
	t_ij			p;

	grid = allocate_grid(column, line);
	p.j = -1;
	fd = open(map, O_RDONLY);
	while (++p.j < line)
	{
		get_next_line(fd, &str);
		clean_str = clean(str);
		p.i = -1;
		while (++p.i < column)
		{
			if (clean_str[p.i] == NULL)
				return (0);
			grid[p.i][p.j] = ft_atoi(clean_str[p.i]);
		}
	}
	return (grid);
}
