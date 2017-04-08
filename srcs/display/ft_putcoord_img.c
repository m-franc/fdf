/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putcoord_img.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 17:22:19 by mfranc            #+#    #+#             */
/*   Updated: 2017/04/08 17:05:39 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_putlpoint(t_fdf *fdf, t_coord *line_point, int *pj, int *pi)
{
	t_coord	*tmp;
	size_t	len_line;
	int		padding;
	int		i;

	i = 0;
	tmp = line_point;
	len_line = ft_count_coord(tmp);
	padding = WI / len_line;
	while (line_point)
	{
//		if (ft_strlen(fdf->addr + *pj) >= 4)
//		{
			if ((ft_put_pxl_img(fdf, line_point->color, pj)) == -1)
				return (-1);
			*pj += (WI * (*pi + 1)) + (len_line - ft_count_coord(line_point));
		//	if (ft_strlen(fdf->addr + *pj) >= (WI / len_line))
//		}
//		else
//			break ;
		line_point = line_point->next;
	}
	return (1);
}

int			ft_putcoord_img(t_fdf *fdf)
{
	t_coord	**points;
	int		i;
	int		*pi;
	int		j;
	int		*pj;

	ft_putcoord(fdf->coord);
	points = fdf->coord;
	i = -1;
	j = 0;
	pi = &i;
	pj = &j;
	while (points[++i])
	{
		if ((ft_putlpoint(fdf, points[i], pj, pi)) == -1)
			return (-1);
	}
	return (1);
}
