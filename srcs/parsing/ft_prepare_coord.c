/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prepare_coord.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 21:35:39 by mfranc            #+#    #+#             */
/*   Updated: 2017/04/05 16:08:14 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			ft_prepare_coord(t_fdf *fdf, t_datacoord **dc)
{
	if (!(*dc = (t_datacoord*)malloc(sizeof(t_datacoord))))
		return (ft_exit_fdf("Coord init", NULL));
	if (!(fdf->coord = (t_coord**)malloc(sizeof(t_coord*)
					* ft_listcount(fdf->map_info))))
		return (ft_exit_fdf("Coord init", NULL));
	(*dc)->y = 0;
	(*dc)->i = 0;
	(*dc)->pi = &(*dc)->i;
	(*dc)->coord_cpy = fdf->coord;
	(*dc)->nb_line = ft_listcount(fdf->map_info);
	(*dc)->map_info = fdf->map_info;
	return (1);
}
