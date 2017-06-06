/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 12:08:46 by mfranc            #+#    #+#             */
/*   Updated: 2017/06/06 20:19:14 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			ft_iso_application(t_coord **coord)
{
	int		i;
	t_coord	*tmp;

	i = 0;
	while (coord[i])
	{
		tmp = coord[i];
		while (tmp)
		{
			tmp->x = (tmp->x - tmp->y) / 2;
			tmp->y = ((tmp->x + tmp->y) / 2) - (tmp->z / 2);
			tmp = tmp->next;
		}
		i++;
	}
}

int				ft_get_padd_z(t_coord **coord)
{
	int			z_min;
	int			z_max;
	int			i;
	t_coord		*tmp;

	i = 0;
	z_max = 0;
	z_min = 0;
	while (coord[i])
	{
		tmp = coord[i];
		while (tmp)
		{
			if (tmp->z < z_min)
				z_min = tmp->z;
			if (tmp->z > z_max)
				z_max = tmp->z;
			tmp = tmp->next;
		}
		i++;
	}
	return (ft_abs(z_max) + ft_abs(z_min));
}

int				ft_get_scale(int ratio_x, int ratio_y, int ratio_z)
{
	int	result;

	if (ratio_x > ratio_y)
	{
		result = ratio_y;
		if (result > ratio_z)
			result = ratio_z;
	}
	else
	{
		result = ratio_x;
		if (result > ratio_z)
			result = ratio_z;
	}
	return (result);
}

void			ft_ratio_application(t_coord **coord, t_datacoord *dc)
{
	int		i;
	int		z;
	int		scale;
	t_coord	*tmp;

	i = 0;
	z = ft_get_padd_z(coord);	
	scale = ft_get_scale(LI / dc->x, WI / dc->y, WI / z);
	while (coord[i])
	{
		tmp = coord[i];
		while (tmp)
		{
			tmp->x *= scale;
			tmp->y *= scale;	
			tmp->z *= scale;
			tmp = tmp->next;
		}
		i++;
	}
}

int				ft_get_min_max_x(t_coord **coord, int *x_max)
{
	int			i;
	int			x_min;
	t_coord		*cpy;

	i = 0;
	while (coord[i])
	{
		cpy = coord[i];
		x_min = cpy->x;
		while (cpy)
		{
			if (i == 0 && !cpy->next)
				*x_max = cpy->x;
			cpy = cpy->next;
		}
		i++;
	}
	return (x_min);
}

int				ft_get_min_max_y(t_datacoord *dc, t_coord **coord, int *y_max)
{
	int			i;
	int			y_min;
	t_coord		*cpy;

	i = 0;
	while (coord[i])
	{
		cpy = coord[i];
		if (i == 0)
			y_min = cpy->y;
		while (cpy)
		{
			if (i == dc->y - 1 && !cpy->next)
				*y_max = cpy->y;
			cpy = cpy->next;
		}
		i++;
	}
	return (y_min);
}

void			ft_placement_application(t_coord *tmp, t_coord **coord, t_datacoord *dc)
{
	int		x_max;
	int		x_min;
	int		y_max;
	int		y_min;
	int		z;

	x_max = 0;
	y_max = 0;
	x_min = ft_get_min_max_x(coord, &x_max);
	y_min = ft_get_min_max_y(dc, coord, &y_max);
	z = ft_get_padd_z(coord);
	while (*coord)
	{
		tmp = *coord;
		while (tmp)
		{
			tmp->x += ((LI - ft_abs(x_max) + ft_abs(x_min)) / 2);
			tmp->y += ((WI - ft_abs(y_max) + ft_abs(y_min)) / 2);
			if (z >= LI)
				tmp->y += y_max;
			tmp = tmp->next;
		}
		coord++;
	}
}
