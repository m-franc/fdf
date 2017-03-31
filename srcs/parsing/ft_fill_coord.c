/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_coord.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 18:36:34 by mfranc            #+#    #+#             */
/*   Updated: 2017/03/31 18:19:49 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int 	ft_coord_first(t_coord **coord_cpy, char *abs, int y, int *j)
{
	char	*hexa_to_dec;

	while (abs[*j] && (ft_isdigit(abs[*j]) == 0 && abs[*j] != '-'))
		*j += 1;
	if (!(coord_cpy[y] = (t_coord*)malloc(sizeof(t_coord))))
		return (-1);
	coord_cpy[y]->z = ft_atoi(abs);
	if (abs[*j + ft_ilen(coord_cpy[y]->z, 10)] == ',')
	{
		if (!(hexa_to_dec = ft_convbase(abs + (*j + ft_ilen(coord_cpy[y]->z, 10)
							+ 1), 16, 10, BASELW)))
			return (-1);
		coord_cpy[y]->color = ft_atoi(hexa_to_dec);
		ft_strdel(&hexa_to_dec);
	}
	else
		coord_cpy[y]->color = 16777215;
	return (0);
}

static int 	ft_coord_current(t_coord **coord_cpy, char *abs, int y)
{
	char	*hexa_to_dec;

	if (!(coord_cpy[y] = malloc(sizeof(t_coord))))
		return (-1);
	coord_cpy[y]->z = ft_atoi(abs);
	if (abs[ft_ilen(coord_cpy[y]->z, 10)] == ',')
	{
		if (!(hexa_to_dec = ft_convbase(abs +
						ft_ilen(coord_cpy[y]->z, 10) + 1, 16, 10, BASELW)))
			return (-1);
		coord_cpy[y]->color = ft_atoi(hexa_to_dec);
		ft_strdel(&hexa_to_dec);
	}
	else
		coord_cpy[y]->color = 16777215;
	return (0);
}

int			ft_fill_coord(t_fdf fdf)
{
	int		y;
	int		j;
	t_coord	**coord_cpy;
	char	*abs;
	
	y = -1;
	abs = fdf.map_info->content;
	if (!(fdf.coord = (t_coord**)malloc(sizeof(t_coord*) * ft_listcount(fdf.map_info))))
		return (ft_exit_fdf("Coord init", NULL));
	coord_cpy = fdf.coord;
	while (fdf.map_info && ++y < (int)ft_listcount(fdf.map_info))
	{
		j = 0;
		if ((ft_coord_first(coord_cpy, abs, y, &j)) == -1)
			return (ft_exit_fdf("Coord init", NULL));
		while (abs[j])
		{
			if (ft_isdigit(abs[j]) || abs[j] == '-')
			{
				coord_cpy[y] = coord_cpy[y]->next; 
				if ((ft_coord_current(coord_cpy, abs + j, y)) == -1)
					return (ft_exit_fdf("Coord init", NULL));
			}
			j++;
		}
		fdf.map_info = fdf.map_info->next;
	}
	return (0);
}
