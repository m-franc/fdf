/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 12:21:05 by mfranc            #+#    #+#             */
/*   Updated: 2017/03/29 12:27:24 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_fdf		ft_fdf_init(void)
{
	t_fdf	fdf;

	fdf.mlx = mlx_init();
	fdf.win = mlx_new_window(fdf.mlx, 420, 420, "42");
	fdf.img = mlx_new_image(fdf.mlx, 420, 420);
	fdf.addr = mlx_get_data_addr(fdf.img, &fdf.b_pxl, &fdf.size_l, &fdf.endian);
	fdf.b_pxl = BITS_PER_PIXEL;
	fdf.size_l = SIZE_LINE;
	fdf.endian = ENDIAN;
	return (fdf);
}

int			ft_put_pxl_img(t_fdf fdf, unsigned int color, int *id)
{
	int		shift;
	int		d;

	d = -1;
	shift = 0;
	while (++d < 4)
	{
		fdf.addr[*id] = (color >> shift) & 0xFF;
		shift += 8;
		*id += 1;
	}
	if (shift != 32)
		return (ft_exit_fdf("put_pxl_img", NULL));
	return (0);
}

int			ft_fill_img(t_fdf fdf, unsigned int color)
{
	int		i;
	int		*id;

	i = 0;
	id = &i;
	while (i < 420)
	{
		if ((ft_put_pxl_img(fdf, color, id)) == -1)
			return (ft_exit_fdf("fill_img", NULL));
	}
	return (0);
}

int			ft_exit_fdf(char *msg, ...)
{
	void	*elem;
	va_list	ap;

	va_start(ap, msg);
	while (!(elem = va_arg(ap, void *)))
		ft_memdel(&elem);
	ft_printf("%s Error\n", msg);
	return (-1);
}

int 		main(void)
{
	t_fdf	fdf;

	fdf = ft_fdf_init();
	if ((ft_fill_img(fdf, 0xFFFFFF)) == -1)
		return (-1);
	fdf.img_in_win = mlx_put_image_to_window(fdf.mlx, fdf.win, fdf.img, 50, 50);
	mlx_loop(fdf.mlx);
	return (0);
}

