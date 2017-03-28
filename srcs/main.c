/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 17:27:05 by mfranc            #+#    #+#             */
/*   Updated: 2017/03/28 17:50:41 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int 		main(void)
{
	void	*mlx;
	void	*img;
	void	*win;
	int		img_in_win;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 420, 420, "42");
	img = mlx_new_image(mlx, 420, 420);
	img_in_win = mlx_put_image_to_window(mlx, win, img, 420, 420);
	sleep(5);
	return (0);
}


// This function put pxl on img
// It receive :
// - the pointer of the octets to fill, got w mlx_get_data_addr
// - the color code of the octet which it fill in the octet pointed, got w mlx_get_color_value
void		pxl_init(t_pxl *pxl)
{
	pxl->b_ppxl = BITS_PER_PIXEL;
	pxl->size_l = SIZE_LINE;
	pxl->endian = ENDIAN;
}

int			ft_put_pxl_img(char **addr, unsigned int color, int *id)
{
	int		i;
	int		shift;

	i = -1;
	shift = 24;
	while (*addr[++i] && i < 4)
	{
		*addr[i] = (color >> shift) & 0xFF;
		shift -= 8;
	}
	if (i < 4 || shift != 0)
		return (-1);
	*id -= i;
	return (0);
}

int			ft_fill_img(void *img, unsigned int color)
{
	char	*datas;
	t_pxl	*pxl;
	int		i;
	int		*id;
	
	i = 0;
	id = &i;
	pxl = NULL;
	pxl_init(pxl);
	datas = mlx_get_data_addr(img, &pxl->b_ppxl, &pxl->size_l, &pxl->endian);
	while (datas[i])
	{
		if (!(ft_put_pxl_img(&datas + i, color, id)))
			return (-1);
	}
	return (0);
}

int			ft_exit(char *msg, ...)
{
	void	*elem;
	va_list	ap;
	va_start(ap, msg);
	while (!(elem = va_arg(ap, void *)))
		ft_memdel(&elem);
	ft_printf("%s, ", )
	return (-1);
}
