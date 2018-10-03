#include "../include/fdf.h"

int	to_double_coord(long **ar, int x_sz, int y_sz, t_p **ret)
{
	int		x;
	int		y;
	t_p		*p;

	if (!(p = malloc(x_sz * y_sz * sizeof(t_p))))
		return (1);
	x = -1;
	while (++x < x_sz)
	{
		y = -1;
		while (++y < y_sz)
			ft_memcpy(&p[x * y_sz + y], &(t_p){x, y, ar[x][y]}, sizeof(t_p));
        y=0;
	}
	*ret = p;
	return (0);
}

# define SQ2 0x1.6a09e667f3bcdp+0
# define SQ3 0x1.bb67ae8584caap+0
# define SQ6 0x1.3988e1409212ep+1

static void	transform(t_p *pt)
{
	double const	m[3][3] = {
		{SQ3 / SQ6, 0, -SQ3 / SQ6},
		{1.0 / SQ6, 2.0 / SQ6, 1.0 / SQ6},
		{SQ2 / SQ6, -SQ2 / SQ6, SQ2 / SQ6},
	};
	int		i;
	int		j;
	t_p		new_p;

	i = -1;
	while (++i < 3)
	{
		new_p[i] = 0;
		j = -1;
		while (++j < 3)
			new_p[i] += m[i][j] * (*pt)[j];
	}
	i = -1;
	while (++i < 3)
		(*pt)[i] = new_p[i];
}

int						coordinate_tr(int x_sz, int y_sz, t_p *ar)
{
	t_p (*const	p_ar)[y_sz] = (t_p(*)[y_sz])ar;
	int		x;
	int		y;

	x = -1;
	while (++x < x_sz)
	{
		y = -1;
		while (++y < y_sz)
			transform(&p_ar[x][y]);
	}
	return (1);
}
