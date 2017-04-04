/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 12:21:05 by mfranc            #+#    #+#             */
/*   Updated: 2017/04/04 16:49:21 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int 		main(int ac, char **av)
{
	t_fdf		*fdf;
	t_datacoord	*datacoord;
	t_list		*map_info_cpy;

	if (!(fdf = ft_fdf_init()))
		return (-1);
	if (ac == 1)
		return (ft_exit_fdf("Number arguments", NULL));
	if (!av[1])
		return (ft_exit_fdf("File", NULL));
	if ((ft_get_map_info(fdf, av[1])) == -1)
		return (-1);
	datacoord = NULL;
	if ((ft_prepare_coord(fdf, datacoord)) == -1)
		return (-1);
	map_info_cpy = fdf->map_info;
	if ((ft_fill_coord(datacoord, map_info_cpy)) == -1)
		return (-1);
	ft_lstdel(&fdf->map_info);
	fdf->img_in_win =
		mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 50, 50);
	mlx_loop(fdf->mlx);
	return (0);
}

