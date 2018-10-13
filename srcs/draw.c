/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbellaic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 15:23:45 by mbellaic          #+#    #+#             */
/*   Updated: 2018/10/13 15:23:48 by mbellaic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

t_line				init_bresenham(int draw[4])
{
	t_line			e;

	e.dx = abs(draw[2] - draw[0]);
	e.dy = abs(draw[3] - draw[1]);
	e.err = (e.dx > e.dy ? e.dx : -e.dy) / 2;
	e.sx = draw[0] < draw[2] ? 1 : -1;
	e.sy = draw[1] < draw[3] ? 1 : -1;
	return (e);
}

void				draw_line(int draw[4], void *mlx, void *win)
{
	t_line			e;

	e = init_bresenham(draw);
	while (1)
	{
		mlx_pixel_put(mlx, win, draw[0], draw[1], COLOR);
		if (draw[0] == draw[2] && draw[1] == draw[3])
			break ;
		e.e2 = e.err;
		if (e.e2 > -e.dx)
		{
			e.err -= e.dy;
			draw[0] += e.sx;
		}
		if (e.e2 < e.dy)
		{
			e.err += e.dx;
			draw[1] += e.sy;
		}
	}
}

int					draw_x(double ***coordtable, int y, int x, void *ptr)
{
	int				i;
	int				j;
	int				draw[4];

	j = -1;
	while (++j < y)
	{
		i = -1;
		while (++i < x - 1)
		{
			draw[0] = coordtable[i][j][0];
			draw[1] = coordtable[i][j][1];
			draw[2] = coordtable[i + 1][j][0];
			draw[3] = coordtable[i + 1][j][1];
			draw_line(draw, ((t_mlx *)ptr)->mlx, ((t_mlx *)ptr)->win);
		}
	}
	return (1);
}

int					draw_y(double ***coordtable, int y, int x, void *ptr)
{
	int				i;
	int				j;
	int				draw[4];

	j = -1;
	while (++j < y - 1)
	{
		i = -1;
		while (++i < x)
		{
			draw[0] = coordtable[i][j][0];
			draw[1] = coordtable[i][j][1];
			draw[2] = coordtable[i][j + 1][0];
			draw[3] = coordtable[i][j + 1][1];
			draw_line(draw, ((t_mlx *)ptr)->mlx, ((t_mlx *)ptr)->win);
		}
	}
	return (1);
}
