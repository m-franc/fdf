/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_pxl_img.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 21:07:34 by mfranc            #+#    #+#             */
/*   Updated: 2017/06/06 12:33:08 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_put_pxl_img(t_fdf *fdf, unsigned int color, int id)
{
	fdf->addr[id * 4] = (color >> 0) & 0xFF;
	fdf->addr[id * 4 + 1] = (color >> 8) & 0xFF;
	fdf->addr[id * 4 + 2] = (color >> 16) & 0xFF;
	fdf->addr[id * 4 + 3] = 0;
}
