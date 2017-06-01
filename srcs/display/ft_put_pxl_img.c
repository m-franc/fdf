/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_pxl_img.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 21:07:34 by mfranc            #+#    #+#             */
/*   Updated: 2017/06/01 13:08:58 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			ft_put_pxl_img(t_fdf *fdf, unsigned int color, int id)
{
	int		shift;
	int		d;

	d = -1;
	shift = 0;
//	if (ft_strlen(fdf->addr + id) < 4)
//		return (0);
	while (++d < 4)
	{
		fdf->addr[id * 4 + d] = (color >> shift) & 0xFF;
		shift += 8;
	}
	return (1);
}
