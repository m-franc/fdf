/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_pxl_img.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 21:07:34 by mfranc            #+#    #+#             */
/*   Updated: 2017/05/31 18:05:14 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			ft_put_pxl_img(t_fdf *fdf, unsigned int color, int *id)
{
	int		shift;
	int		d;

	d = -1;
	shift = 0;
	if (ft_strlen(fdf->addr + *id) < 4)
		return (0);
	while (++d < 4)
	{
		fdf->addr[*id] = (color >> shift) & 0xFF;
		shift += 8;
		*id += 1;
	}
	return (1);
}
