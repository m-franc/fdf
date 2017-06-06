/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 21:06:55 by mfranc            #+#    #+#             */
/*   Updated: 2017/06/06 11:12:05 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			ft_fdf_init(t_fdf **fdf)
{
	if (!(*fdf = (t_fdf*)malloc(sizeof(t_fdf))))
		return (-1);
	(*fdf)->mlx = mlx_init();
	(*fdf)->win = mlx_new_window((*fdf)->mlx, LW, WW, "42");
	(*fdf)->img = mlx_new_image((*fdf)->mlx, LI, WI);
	(*fdf)->b_pxl = BITS_PER_PIXEL;
	(*fdf)->size_l = SIZE_LINE;
	(*fdf)->endian = ENDIAN;
	(*fdf)->addr = mlx_get_data_addr((*fdf)->img, &(*fdf)->b_pxl,
			&(*fdf)->size_l, &(*fdf)->endian);
	return (1);
}
