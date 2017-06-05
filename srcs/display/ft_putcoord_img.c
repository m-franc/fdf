/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putcoord_img.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 17:22:19 by mfranc            #+#    #+#             */
/*   Updated: 2017/06/05 15:25:50 by mfranc           ###   ########.fr       */
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
			ft_put_pxl_img(fdf, 0xFFFF00, (draw_datas.y * LI + draw_datas.x));
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
		if (cumul >=draw_datas. distance_y)
		{
			cumul -= draw_datas. distance_y;
			draw_datas.x +=draw_datas. x_inc;
		}
		if ((draw_datas.y >= 0 && draw_datas.y < LI) && (draw_datas.x >= 0 && draw_datas.x < WI))
			ft_put_pxl_img(fdf, 0x00FFFF, (draw_datas.y * LI + draw_datas.x));
	}
}

static t_draw_datas	ft_init_draw_datas(int x_start, int y_start, int x_end, int y_end)
{
	t_draw_datas	draw_datas;

	draw_datas.x = x_start;
	draw_datas.y = y_start;
	draw_datas.distance_x = x_end - x_start;
	draw_datas.distance_y = y_end - y_start;
	draw_datas.x_inc = (draw_datas.distance_x > 0) ? 1 : -1;
	draw_datas.y_inc = (draw_datas.distance_y > 0) ? 1 : -1;
	draw_datas.distance_x = ft_abs(draw_datas.distance_x);
	draw_datas.distance_y = ft_abs(draw_datas.distance_y);
	return (draw_datas);
}

int					ft_putlpoint(t_fdf *fdf, int x_start, int y_start, int x_end, int y_end)
{
	t_draw_datas	draw_datas;

	draw_datas = ft_init_draw_datas(x_start, y_start, x_end, y_end);
	if ((draw_datas.y >= 0 && draw_datas.y < LI) && (draw_datas.x >= 0 && draw_datas.x < WI))
		ft_put_pxl_img(fdf, 0xFFFFFF, (draw_datas.y * LI + draw_datas.x));
	if (draw_datas.distance_x > draw_datas.distance_y)
		ft_put_hor_segm(fdf, draw_datas);
	else
		ft_put_vert_segm(fdf, draw_datas);
	return (0);
}

void			ft_ratio_application(t_coord **coord)
{
	int		i;
	t_coord	*tmp;

	i = 0;
	while (coord[i])
	{
		tmp = coord[i];
		while (tmp)
		{
			tmp->x *= 2;
			tmp->y *= 2;
			tmp->z *= 2;
			tmp = tmp->next;
		}
		i++;
	}
}

static t_coord*		ft_get_down_point(t_coord *act_point, int index)
{
	while (act_point && index-- > 0)
		act_point = act_point->next;
	return (act_point);
}

int					ft_putcoord_img(t_fdf *fdf, t_datacoord *dc)
{
	t_coord			**points;
	t_coord			*down_point;
	int				i;
	int				j;

	i = 0;
	points = fdf->coord;
	ft_ratio_application(points);
	while (i < dc->nb_line)
	{
		j = 0;
		while (points[i])
		{
			if (points[i]->next)
			{
				PNBR(i)
				ft_putlpoint(fdf, points[i]->x, points[i]->y, points[i]->next->x, points[i]->next->y);
			}
			if (i < (dc->nb_line - 1))
			{				
				down_point = ft_get_down_point(points[i + 1], j);
				ft_putlpoint(fdf, points[i]->x, points[i]->y, down_point->x, down_point->y);
			}
			j++;
			points[i] = points[i]->next;
		}
		i++;
	}
	return (1);
}
