/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 21:06:55 by mfranc            #+#    #+#             */
/*   Updated: 2017/04/04 16:00:00 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_fdf		*ft_fdf_init(void)
{
	t_fdf	*fdf;

	if (!(fdf = (t_fdf*)malloc(sizeof(t_fdf))))
		return (NULL);
	fdf->mlx = mlx_init();
	fdf->win = mlx_new_window(fdf->mlx, 420, 420, "42");
	fdf->img = mlx_new_image(fdf->mlx, 420, 420);
	fdf->addr = mlx_get_data_addr(fdf->img, &fdf->b_pxl, &fdf->size_l, &fdf->endian);
	fdf->b_pxl = BITS_PER_PIXEL;
	fdf->size_l = SIZE_LINE;
	fdf->endian = ENDIAN;
	return (fdf);
}
