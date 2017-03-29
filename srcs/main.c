/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 12:21:05 by mfranc            #+#    #+#             */
/*   Updated: 2017/03/29 21:21:41 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int 		main(int ac, char **av)
{
	t_fdf	fdf;

	fdf = ft_fdf_init();
	if (ac == 1)
		return (ft_exit_fdf("Number arguments", NULL));
	if ((ft_parse_map(fdf, av[1])) == -1)
		return (-1);
	fdf.img_in_win = mlx_put_image_to_window(fdf.mlx, fdf.win, fdf.img, 50, 50);
	mlx_loop(fdf.mlx);
	return (0);
}

