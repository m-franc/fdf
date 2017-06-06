/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putcoord_img.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 17:22:19 by mfranc            #+#    #+#             */
/*   Updated: 2017/06/06 16:38:13 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void			ft_put_hor_segm(t_fdf *fdf, t_draw_datas draw_datas)
{
	int				cumul;
	int				i;

	cumul = draw_datas.distance_x / 2;
	i = -1;
	while (++i < draw_datas.distance_x)
	{
		draw_datas.x += draw_datas.x_inc;
		cumul += draw_datas.distance_y;
		if (cumul >= draw_datas.distance_x)
		{
			cumul -= draw_datas.distance_x;
			draw_datas.y += draw_datas.y_inc;
		}
		if ((draw_datas.y >= 0 && draw_datas.y < LI) && (draw_datas.x >= 0 && draw_datas.x < WI))
			ft_put_pxl_img(fdf, draw_datas.color, (draw_datas.y * LI + draw_datas.x));
	}
}
static void			ft_put_vert_segm(t_fdf *fdf, t_draw_datas draw_datas)
{
	int				cumul;
	int				i;

	cumul = draw_datas.distance_y / 2;	
	i = -1;
	while (++i < draw_datas.distance_y)
	{
		draw_datas.y +=draw_datas. y_inc;
		cumul +=draw_datas. distance_x;
		if (cumul >= draw_datas. distance_y)
		{
			cumul -= draw_datas. distance_y;
			draw_datas.x +=draw_datas. x_inc;
		}
		if ((draw_datas.y >= 0 && draw_datas.y < LI) && (draw_datas.x >= 0 && draw_datas.x < WI))
			ft_put_pxl_img(fdf, draw_datas.color, (draw_datas.y * LI + draw_datas.x));
	}
}

static t_draw_datas	ft_init_draw_datas(t_coord *start, t_coord *end)
{
	t_draw_datas	draw_datas;

	draw_datas.x = start->x;
	draw_datas.y = start->y;
	draw_datas.distance_x = end->x - start->x;
	draw_datas.distance_y = end->y - start->y;
	draw_datas.x_inc = (draw_datas.distance_x > 0) ? 1 : -1;
	draw_datas.y_inc = (draw_datas.distance_y > 0) ? 1 : -1;
	draw_datas.distance_x = ft_abs(draw_datas.distance_x);
	draw_datas.distance_y = ft_abs(draw_datas.distance_y);
	draw_datas.color = start->color;
	return (draw_datas);
}

int					ft_putlpoint(t_fdf *fdf, t_coord *start, t_coord *end)
{
	t_draw_datas	draw_datas;

	draw_datas = ft_init_draw_datas(start, end);
	if ((draw_datas.y >= 0 && draw_datas.y < LI) && (draw_datas.x >= 0 && draw_datas.x < WI))
		ft_put_pxl_img(fdf, draw_datas.color, (draw_datas.y * LI + draw_datas.x));
	if (draw_datas.distance_x > draw_datas.distance_y)
		ft_put_hor_segm(fdf, draw_datas);
	else
		ft_put_vert_segm(fdf, draw_datas);
	return (0);
}

static t_coord	*ft_get_down_point(t_coord *act_point, int index)
{
	while (act_point && index-- > 0)
		act_point = act_point->next;
	return (act_point);
}

int					ft_putcoord_img(t_fdf *fdf, t_datacoord *dc)
{
	t_coord			*point;
	t_coord			*down_point;
	int				i;
	int				j;

	i = 0;
	ft_ratio_application(fdf->coord, dc);
	ft_iso_application(fdf->coord);
	ft_placement_application(fdf->coord, dc);
	while (i < dc->nb_line)
	{
		j = 0;
		point = fdf->coord[i];
		while (point)
		{
			if (point->next)
				ft_putlpoint(fdf, point, point->next);
			if (i < (dc->nb_line - 1))
			{
				down_point = ft_get_down_point(fdf->coord[i + 1], j);
				ft_putlpoint(fdf, point, down_point);	
			}
			j++;
			point = point->next;
		}
		i++;
	}
	return (1);
}
