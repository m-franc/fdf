/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 12:21:05 by mfranc            #+#    #+#             */
/*   Updated: 2017/06/05 18:00:39 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_coorddel(t_coord **coord)
{
	t_coord	*tmp;
	int		i;
	
	i = 0;
	while (coord[i])
	{
		tmp = coord[i];
		while (tmp)
		{
			free(tmp);
			tmp = tmp->next;		
		}
		i++;
	}
}

int			main(int ac, char **av)
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
	ft_lstdel(&fdf->map_info);
//	ft_coorddel(fdf->coord);
	free(datacoord);
	fdf->img_in_win = 
		mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
	mlx_loop(fdf->mlx);
	free(fdf);
	return (0);
}
