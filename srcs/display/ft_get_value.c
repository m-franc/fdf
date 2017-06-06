/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_value.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 20:37:57 by mfranc            #+#    #+#             */
/*   Updated: 2017/06/06 22:06:48 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
