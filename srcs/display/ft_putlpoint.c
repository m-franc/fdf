/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlpoint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 20:43:16 by mfranc            #+#    #+#             */
/*   Updated: 2017/06/06 22:29:16 by mfranc           ###   ########.fr       */
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
		if ((draw_datas.y >= 0 && draw_datas.y < LI)\
				&& (draw_datas.x >= 0 && draw_datas.x < WI))
			ft_put_pxl_img(fdf, draw_datas.color,
					(draw_datas.y * LI + draw_datas.x));
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
		draw_datas.y += draw_datas.y_inc;
		cumul += draw_datas.distance_x;
		if (cumul >= draw_datas.distance_y)
		{
			cumul -= draw_datas.distance_y;
			draw_datas.x += draw_datas.x_inc;
		}
		if ((draw_datas.y >= 0 && draw_datas.y < LI)\
				&& (draw_datas.x >= 0 && draw_datas.x < WI))
			ft_put_pxl_img(fdf, draw_datas.color,
					(draw_datas.y * LI + draw_datas.x));
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
	if ((draw_datas.y >= 0 && draw_datas.y < LI)\
			&& (draw_datas.x >= 0 && draw_datas.x < WI))
		ft_put_pxl_img(fdf, draw_datas.color,
				(draw_datas.y * LI + draw_datas.x));
	if (draw_datas.distance_x > draw_datas.distance_y)
		ft_put_hor_segm(fdf, draw_datas);
	else
		ft_put_vert_segm(fdf, draw_datas);
	return (0);
}
