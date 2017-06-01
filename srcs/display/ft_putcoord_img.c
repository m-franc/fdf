/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putcoord_img.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 17:22:19 by mfranc            #+#    #+#             */
/*   Updated: 2017/06/01 19:27:29 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_putlpoint(t_fdf *fdf, int x_start, int y_start, int x_end, int y_end)
{
	int		x;
	int		y;
	int		i;
	//	double	a;
	//	double	b;
	int		distance_x;
	int		distance_y;
	int		x_inc;
	int		y_inc;
	int		cumul;
	int		coord;

	//	a = (double)((yf - yi) / (xf - xi));
	//	b = yi - a * xi;
	x = x_start;
	y = y_start;
	distance_x = x_end - x_start;
	distance_y = y_end - y_start;
	x_inc = (distance_x > 0) ? 1 : -1;
	y_inc = (distance_y > 0) ? 1 : -1;
	distance_x = ft_abs(distance_x);
	distance_y = ft_abs(distance_y);
	coord = (y * LI + x);
	ft_put_pxl_img(fdf, 0xFFFFFF, coord);
	i = -1;
	if (distance_x > distance_y)
	{
		cumul = distance_x / 2;
		while (++i <= distance_x)
		{
			x += x_inc;
			cumul += distance_y;
			ft_printf("Valeur du X : {grey}%d{eoc}\n", x);
			ft_printf("Valeur du Y : {grey}%d{eoc}\n", y);
			ft_printf("Valeur du facteur d'augmetation du Y : {grey}%d{eoc}\n", cumul);
			if (cumul >= distance_x)
			{
				cumul -= distance_x;
				ft_printf("On augmente le cumul : {cyan}%d{eoc}\n" , cumul);
				y += y_inc;
			}
			coord = (y * LI + x);
			ft_put_pxl_img(fdf, 0xFFFFFF, coord);
		}
	}
	else
	{
		cumul = distance_y / 2;	
		while (++i < distance_y)
		{
			y += y_inc;
			cumul += distance_x;
			ft_printf("Valeur du X : {grey}%d{eoc}\n", x);
			ft_printf("Valeur du Y : {grey}%d{eoc}\n", y);
			ft_printf("Valeur du facteur d'augmetation du X : {grey}%d{eoc}\n", cumul);
			if (cumul >= distance_y)
			{
				cumul -= distance_y;
				ft_printf("On augmente le cumul : {cyan}%d{eoc}\n" , cumul);
				x += x_inc;
			}
			coord = (y * LI + x);
			ft_put_pxl_img(fdf, 0xFFFFFF, coord);
		}
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
