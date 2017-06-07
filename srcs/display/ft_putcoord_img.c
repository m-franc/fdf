/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putcoord_img.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 17:22:19 by mfranc            #+#    #+#             */
/*   Updated: 2017/06/07 12:36:07 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_coord		*ft_get_down_point(t_coord *act_point, int index)
{
	while (act_point && index-- > 0)
		act_point = act_point->next;
	if (!act_point)
	{
		ft_putendl("Coord Error");
		exit(-1);
	}
	return (act_point);
}

static void			ft_application(t_coord *tmp,
		t_coord **coord, t_datacoord *dc)
{
	ft_ratio_application(coord, dc);
	ft_iso_application(coord);
	ft_placement_application(tmp, coord, dc);
}

void				ft_putcoord_img(t_fdf *fdf, t_datacoord *dc)
{
	t_coord			*point;
	t_coord			*tmp;
	t_coord			*down_point;
	int				i;
	int				j;

	i = -1;
	tmp = *fdf->coord;
	ft_application(tmp, fdf->coord, dc);
	while (++i < dc->nb_line)
	{
		j = -1;
		point = fdf->coord[i];
		while (point && ++j < dc->x)
		{
			if (point->next)
				ft_putlpoint(fdf, point, point->next);
			if (i < (dc->nb_line - 1))
			{
				down_point = ft_get_down_point(fdf->coord[i + 1], j);
				ft_putlpoint(fdf, point, down_point);
			}
			point = point->next;
		}
	}
}
