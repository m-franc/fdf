/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 12:21:05 by mfranc            #+#    #+#             */
/*   Updated: 2017/06/05 15:10:44 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int ac, char **av)
{
	t_fdf		*fdf;
	t_datacoord	*datacoord;

	fdf = NULL;
	if ((ft_fdf_init(&fdf)) == -1)
		return (-1);
	if (ac == 1)
		return (ft_exit_fdf("Number arguments", NULL));
	if (!av[1])
		return (ft_exit_fdf("File", NULL));
	if ((ft_get_map_info(fdf, av[1])) == -1)
		return (-1);
	datacoord = NULL;
	if ((ft_prepare_coord(fdf, &datacoord)) == -1)
		return (-1);
	if ((ft_fill_coord(datacoord)) == -1)
		return (-1);
	ft_putcoord_img(fdf, datacoord);
/*	x_end = LI;
	y_end = LI;
	while (y_end >= 0)
	{
		if ((ft_putlpoint(fdf, LI / 2, LI / 2, x_end, y_end)))
			return (-1);
		y_end -= 10;
	}
	y_end = LI;
	while (x_end >= 0)
	{
		if ((ft_putlpoint(fdf, LI / 2, LI / 2, x_end, y_end)))
			return (-1);
		x_end -= 10;
	}
	y_end = LI;
	x_end = 0;
	while (y_end >= 0)
	{
		if ((ft_putlpoint(fdf, LI / 2, LI / 2, x_end, y_end)))
			return (-1);
		y_end -= 10;
	}
	y_end = 0;
	x_end = 0;
	while (x_end <= LI)
	{
		if ((ft_putlpoint(fdf, LI / 2, LI / 2, x_end, y_end)))
			return (-1);
		x_end += 10;
	}
*/	
//	if ((ft_putcoord_img(fdf)) == -1)
	//	return (-1);
//	ft_putcoord(fdf->coord);
//	ft_lstdel(&fdf->map_info);
//	free(&datacoord);
//	while free **coord
//	free(&fdf);
	fdf->img_in_win = 
		mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 5, 5);
	mlx_loop(fdf->mlx);
	return (0);
}
