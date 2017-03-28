/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 17:27:05 by mfranc            #+#    #+#             */
/*   Updated: 2017/03/28 20:03:25 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_pxl		pxl_init(void)
{
	t_pxl	pxl;

	pxl.b_ppxl = BITS_PER_PIXEL;
	pxl.size_l = SIZE_LINE;
	pxl.endian = ENDIAN;
	return (pxl);
}

int			ft_put_pxl_img(char **addr, unsigned int color)
{
	int		i;
	int		shift;

	i = 0;
	shift = 24;
	while (addr[0][i] && i < 4)
	{
		addr[0][i] = (color >> shift) & 0xFF;
		shift -= 8;
		i++;
	}
	exit(0);
	if (i != 4 || shift != 0)
		return (ft_exit_fdf("put_pxl_img", NULL));
	return (0);
}

int			ft_fill_img(t_mlxdatas mlx_datas, unsigned int color)
{
	int		i;
	
	i = 0;
	while (i < 420)
	{
		if (!(ft_put_pxl_img(&mlx_datas.addr, color)))
			return (ft_exit_fdf("fill_img", NULL));
		i += 4;
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
	t_mlxdatas	mlx_datas;

	mlx_datas.mlx = mlx_init();
	mlx_datas.win = mlx_new_window(mlx_datas.mlx, 420, 420, "42");
	mlx_datas.img = mlx_new_image(mlx_datas.mlx, 420, 420);
	mlx_datas.addr = mlx_get_data_addr(mlx_datas.img,
			&mlx_datas.pxl.b_ppxl, &mlx_datas.pxl.size_l, &mlx_datas.pxl.endian);
	mlx_datas.pxl = pxl_init();
	if (!(ft_fill_img(mlx_datas, 0xFFFFFF)))
		return (-1);
	mlx_datas.img_in_win =
		mlx_put_image_to_window(mlx_datas.mlx,
				mlx_datas.win, mlx_datas.img, 0, 0);
	sleep(5);
	return (0);
}
