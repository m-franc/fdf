/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_coord.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 18:36:34 by mfranc            #+#    #+#             */
/*   Updated: 2017/03/30 21:42:00 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int 	ft_cnew(t_fdf fdf, char *x_i, int x)
{
	char	*hexa_to_dec;

	if (!(fdf.coord[x] = malloc(sizeof(t_coord))))
		return (-1);
	fdf.coord[x]->z = ft_atoi(x_i);
	if (x_i[ft_ilen(fdf.coord[x]->z, 10)] == ',')
	{
		if (!(hexa_to_dec =
			ft_convbase(x_i +
			ft_ilen(fdf.coord[x]->z, 10) + 1, 16, 10, BASELW)))
			return (-1);
		fdf.coord[x]->color = ft_atoi(hexa_to_dec);
		ft_strdel(&hexa_to_dec);
	}
	fdf.coord[x] = fdf.coord[x]->next; 
	return (0);
}

int			ft_fill_coord(t_fdf fdf)
{
	int		x;
	int		j;
	char	*abs;
	
	x = -1;
	abs = fdf.map_info->content;
	while (fdf.map_info && ++x < (int)ft_listcount(fdf.map_info))
	{
		j = -1;
		while (abs[++j] && (ft_isdigit(abs[j]) || abs[j] == '-'))
			;
		if ((ft_cnew(fdf, abs + j, x)) == -1)
			return (ft_exit_fdf("Coord init", NULL));
		while (abs[++j])
		{
			if (ft_isdigit(abs[j]) || abs[j] == '-')
			{
				if ((ft_cnew(fdf, abs + j, x)) == -1)
					return (ft_exit_fdf("Coord init", NULL));
			}
		}
		fdf.map_info = fdf.map_info->next;
	}
	return (0);
}
