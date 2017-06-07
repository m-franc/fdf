/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 12:21:05 by mfranc            #+#    #+#             */
/*   Updated: 2017/06/07 12:33:09 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			ft_coorddel(t_coord **coord)
{
	t_coord		*tmp;
	t_coord		*to_free;
	int			i;

	i = 0;
	while (coord[i])
	{
		tmp = coord[i];
		while (tmp)
		{
			to_free = tmp;
			tmp = tmp->next;
			free(to_free);
		}
		i++;
	}
}

int				ft_key_application(int keycode, t_fdf *fdf)
{
	(void)fdf;
	if (keycode == 53)
		exit(0);
	return (0);
}

int				ft_parsing(t_fdf **fdf,
		t_datacoord **datacoord, char **av)
{
	if ((ft_fdf_init(fdf)) == -1)
		return (-1);
	if (!av[1] || !av)
		return (ft_exit_fdf("File"));
	if ((ft_get_map_info(*fdf, av[1])) == -1)
		return (-1);
	if ((ft_prepare_coord(*fdf, datacoord)) == -1)
		return (-1);
	if ((ft_fill_coord(*datacoord)) == -1)
		return (-1);
	return (1);
}

void			ft_display(t_fdf **fdf, t_datacoord **datacoord)
{
	ft_putcoord_img(*fdf, *datacoord);
	(*fdf)->img_in_win =
		mlx_put_image_to_window((*fdf)->mlx, (*fdf)->win, (*fdf)->img, 0, 0);
	mlx_key_hook((*fdf)->win, ft_key_application, 0);
	mlx_loop((*fdf)->mlx);
}

int				main(int ac, char **av)
{
	t_fdf		*fdf;
	t_datacoord	*datacoord;

	fdf = NULL;
	datacoord = NULL;
	if (ac != 2)
		return (ft_exit_fdf("Number arguments"));
	if (ft_parsing(&fdf, &datacoord, av) == -1)
		return (-1);
	ft_display(&fdf, &datacoord);	
	ft_lstdel(&fdf->map_info);
	ft_coorddel(fdf->coord);
	free(datacoord);
	free(fdf);	
	return (0);
}
