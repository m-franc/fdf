/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putcoord_img.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 17:22:19 by mfranc            #+#    #+#             */
/*   Updated: 2017/06/01 13:11:52 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_putlpoint(t_fdf *fdf, int xi, int yi, int xf, int yf)
{
	int		x;
	int		y;
	double	a;
	double	b;
	int		coord;

	a = (double)((yf - yi) / (xf - xi));
	b = yi - a * xi;
	x = xi;
	while (x <= xf)
	{
		y = (a * x + b);
		coord = (y * LI + x);
		if ((ft_put_pxl_img(fdf, 0xFFFFFF, coord)) == -1)
			return (0);
		x++;
	}
	return (0);
}

/*int			ft_putcoord_img(t_fdf *fdf)
{
	t_coord	**x;
	t_coord	*x_if[2]
	int		y;
	int		y_if[2];
	int		i;
	int		j;

	y = 0;
	x[0] = fdf->coord[y];
	while (points[++y])
	{
		while (x[0])
		{	
			i = 0;
			x_if[0] = x[0];
			x_if[1] = x[0]->next;
			y_if[0] = y;
			y_if[1] = y + 1;
			if ((ft_putlpoint(fdf, x_if, y_if)) == -1)
				return (-1);
			x[0] = x[0]->next;
			i++;
		}
	}
	return (1);
}*/
