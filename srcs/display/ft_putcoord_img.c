/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putcoord_img.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 17:22:19 by mfranc            #+#    #+#             */
/*   Updated: 2017/06/02 20:19:01 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		ft_delete_draw_datas(t_draw_datas *draw_datas)
{
	draw_datas->x = 0;
	draw_datas->y = 0;
	draw_datas->distance_x = 0;
	draw_datas->distance_y = 0;
	draw_datas->x_inc = 0;
	draw_datas->y_inc = 0;
	free(draw_datas);
}

static void		ft_put_hor_segm(t_fdf *fdf, t_draw_datas* draw_datas)
{
	int	cumul;
	int	i;

	cumul = draw_datas->distance_x / 2;
	i = -1;
	while (++i <= draw_datas->distance_x)
	{
		draw_datas->x += draw_datas->x_inc;
		cumul += draw_datas->distance_y;
		if (cumul >= draw_datas->distance_x)
		{
			cumul -= draw_datas->distance_x;
			draw_datas->y += draw_datas->y_inc;
		}
		if ((draw_datas->y > 0 && draw_datas->y < LI)
				&& (draw_datas->x > 0 && draw_datas->x < WI))
			ft_put_pxl_img(fdf, 0xFFFFFF, (draw_datas->y * LI + draw_datas->x));
	}
}

static void		ft_put_vert_segm(t_fdf *fdf, t_draw_datas* draw_datas)
{
	int	cumul;
	int	i;

	cumul = draw_datas->distance_y / 2;	
	i = -1;
	while (++i < draw_datas->distance_y)
	{
		draw_datas->y += draw_datas->y_inc;
		cumul += draw_datas->distance_x;
		if (cumul >= draw_datas->distance_y)
		{
			cumul -= draw_datas->distance_y;
			draw_datas->x += draw_datas->x_inc;
		}
		if ((draw_datas->y > 0 && draw_datas->y < LI)
				&& (draw_datas->x > 0 && draw_datas->x < WI))
			ft_put_pxl_img(fdf, 0xFFFFFF, (draw_datas->y * LI + draw_datas->y));
	}
}



static t_draw_datas	*ft_init_draw_datas(int x_start, int y_start, int x_end, int y_end)
{
	t_draw_datas	*draw_datas;

	if (!(draw_datas = (t_draw_datas*)malloc(sizeof(t_draw_datas))))
		return (NULL);
	draw_datas->x = x_start;
	draw_datas->y = y_start;
	draw_datas->distance_x = x_end - x_start;
	draw_datas->distance_y = y_end - y_start;
	draw_datas->x_inc = (draw_datas->distance_x > 0) ? 1 : -1;
	draw_datas->y_inc = (draw_datas->distance_y > 0) ? 1 : -1;
	draw_datas->distance_x = ft_abs(draw_datas->distance_x);
	draw_datas->distance_y = ft_abs(draw_datas->distance_y);
	return (draw_datas);
}

/*
int	ft_putlpoint(t_fdf *fdf, int x_start, int y_start, int x_end, int y_end)
{
	int		x;
	int		y;
	int		i;
	int		distance_x;
	int		distance_y;
	int		x_inc;
	int		y_inc;
	int		cumul;

	x = x_start;
	y = y_start;
	distance_x = x_end - x_start;
	distance_y = y_end - y_start;
	x_inc = (distance_x > 0) ? 1 : -1;
	y_inc = (distance_y > 0) ? 1 : -1;
	distance_x = ft_abs(distance_x);
	distance_y = ft_abs(distance_y);
	if ((y > 0 && y < LI) && (x > 0 && x < WI))
		ft_put_pxl_img(fdf, 0xFFFFFF, (y * LI + x));
	i = -1;
	if (distance_x > distance_y)
	{
		cumul = distance_x / 2;
		while (++i <= distance_x)
		{
			x += x_inc;
			cumul += distance_y;
			if (cumul >= distance_x)
			{
				cumul -= distance_x;
				y += y_inc;
			}
			if ((y > 0 && y < LI) && (x > 0 && x < WI))
				ft_put_pxl_img(fdf, 0xFFFFFF, (y * LI + x));
		}
	}
	else
	{
		cumul = distance_y / 2;	
		while (++i < distance_y)
		{
			y += y_inc;
			cumul += distance_x;
			if (cumul >= distance_y)
			{
				cumul -= distance_y;
				x += x_inc;
			}
			if ((y > 0 && y < LI) && (x > 0 && x < WI))
				ft_put_pxl_img(fdf, 0xFFFFFF, (y * LI + x));
		}
	}
	return (0);
}*/

int				ft_putlpoint(t_fdf *fdf, int x_start, int y_start, int x_end, int y_end)
{
	t_draw_datas	*draw_datas;

	if (!(draw_datas = ft_init_draw_datas(x_start, y_start, x_end, y_end)))
		return (-1);
	if ((draw_datas->y > 0 && draw_datas->y < LI)
			&& (draw_datas->x > 0 && draw_datas->x < WI))
		ft_put_pxl_img(fdf, 0xFFFFFF, (draw_datas->y * LI + draw_datas->x));
	if (draw_datas->distance_x > draw_datas->distance_y)
		ft_put_hor_segm(fdf, draw_datas);
	else
		ft_put_vert_segm(fdf, draw_datas);
	ft_delete_draw_datas(draw_datas);
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
