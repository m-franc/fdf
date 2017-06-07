/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 12:08:46 by mfranc            #+#    #+#             */
/*   Updated: 2017/06/07 12:42:19 by mfranc           ###   ########.fr       */
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

void			ft_ratio_application(t_coord **coord, t_datacoord *dc)
{
	int		i;
	int		z;
	int		scale;
	t_coord	*tmp;

	i = 0;
	z = ft_get_padd_z(coord);
	if (z != 0)
		scale = ft_get_scale(LI / dc->x, WI / dc->y, WI / z);
	else
		scale = ft_get_scale(LI / dc->x, WI / dc->y, WI);
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

void			ft_placement_application(t_coord *tmp,
		t_coord **coord, t_datacoord *dc)
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
