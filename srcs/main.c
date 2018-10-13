/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbellaic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 15:23:22 by mbellaic          #+#    #+#             */
/*   Updated: 2018/10/13 15:23:26 by mbellaic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

long int			**allocate_grid(const int x, const int y)
{
	int				i;
	long int		**grid;

	grid = malloc(sizeof(*grid) * x);
	i = 0;
	while (i < x)
	{
		grid[i] = malloc(sizeof(grid[i]) * y);
		i++;
	}
	return (grid);
}

double				***allocate_xyz(const int x, const int y, const int z)
{
	int				i;
	int				j;
	double			***xyz;

	i = -1;
	j = -1;
	xyz = malloc(x * sizeof(double**));
	while (++i < x)
	{
		xyz[i] = malloc(y * sizeof(double *));
		while (++j < y)
		{
			xyz[i][j] = malloc(z * sizeof(double));
		}
		j = -1;
	}
	return (xyz);
}

int					key_exit(int key)
{
	if (key == 53)
		exit(EXIT_SUCCESS);
	return (0);
}

void				init_draw(double ***positions, int x, int y)
{
	t_mlx *ptr;

	ptr = malloc(sizeof(t_mlx *));
	ptr->mlx = mlx_init();
	ptr->win = mlx_new_window(ptr->mlx, 1280, 720, "1280x720");
	mlx_key_hook(ptr->win, key_exit, ptr);
	draw_x(positions, y, x, ptr);
	draw_y(positions, y, x, ptr);
	mlx_loop(ptr->mlx);
}

int					main(int argc, char **argv)
{
	long int		**grid;
	double			***positions;
	int				x;
	int				y;

	if (argc != 2)
	{
		ft_putstr("Usage : ./fdf [filename.fdf]");
		return (0);
	}
	x = count_columns(argv[1]);
	y = count_rows(argv[1]);
	grid = NULL;
	if (!(grid = parse(x, y, argv[1])))
	{
		ft_putstr("Invalid File.");
		return (0);
	}
	positions = iso_xy(grid, x, y);
	init_draw(positions, x, y);
	return (0);
}
