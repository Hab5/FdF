/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometry.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbellaic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 15:24:06 by mbellaic          #+#    #+#             */
/*   Updated: 2018/10/13 15:24:07 by mbellaic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

double				***iso_xy(long **grid, const int x, const int y)
{
	int				i;
	int				j;
	double			***positions;

	positions = allocate_xyz(x, y, 2);
	i = -1;
	j = -1;
	while (++j != y)
	{
		while (++i != x)
		{
			positions[i][j][0] = (0.5 + ((i - j) / sqrt(2)) * 0.5)
								* VRWIDTH / sqrt(x * y / 1.5) + OFFSETX;
			positions[i][j][1] = (0.5 + ((i + -(grid[i][j] * RATIO) + j)
								/ sqrt(6) * 0.5) * VRHEIGHT)
								/ sqrt(x * y / 1.5) + OFFSETY;
		}
		i = -1;
	}
	return (positions);
}
