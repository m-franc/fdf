/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_coord.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 18:36:34 by mfranc            #+#    #+#             */
/*   Updated: 2017/04/01 17:06:01 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int 	ft_coord_new(t_coord *line_cpy, char *abs)
{
	char	*hexa_to_dec;
	char	*color_hexa;
	int		color_index;

	if (!(line_cpy = malloc(sizeof(t_coord))))
		return (-1);
	line_cpy->z = ft_atoi(abs);
	color_index = ft_ilen(line_cpy->z, 10);
	if (abs[color_index] == '\0')
		return (-1);
	if (abs[color_index] == ',')
	{
		if (!(color_hexa = ft_strsub(abs, (color_index + 1), 
						ft_strspn(abs + (color_index + 1), BASELW))))
			return (-1);
		if (!(hexa_to_dec = ft_convbase(color_hexa, 16, 10, BASELW)))
			return (-1);
		line_cpy->color = ft_atoi(hexa_to_dec);
		ft_strdel(&color_hexa);
		ft_strdel(&hexa_to_dec);
	}
	else
		line_cpy->color = 16777215;
	ft_printf("z : {grey}%d{eoc} - color : {grey}%lu{eoc}\n", line_cpy->z, line_cpy->color); 
	return (0);
}

int			ft_fill_coord(t_fdf fdf)
{
	int		y;
	int		j;
	t_coord	**coord_cpy;
	t_coord	*line_cpy;
	char	*abs;
	
	y = -1;
	if (!(fdf.coord = (t_coord**)malloc(sizeof(t_coord*) * ft_listcount(fdf.map_info))))
		return (ft_exit_fdf("Coord init", NULL));
	coord_cpy = fdf.coord;
	while (fdf.map_info && ++y < (int)ft_listcount(fdf.map_info))
	{
		line_cpy = coord_cpy[y];
		abs = fdf.map_info->content;
		j = 0;
		while (abs[j] && (ft_isdigit(abs[j]) == 0 && abs[j] != '-'))
			j++;
		if ((ft_coord_new(line_cpy, abs + j)) == -1)
			return (ft_exit_fdf("Coord init", NULL));
		while (abs[j])
		{
			if (ft_isdigit(abs[j]) || abs[j] == '-')
			{
				line_cpy = line_cpy->next; 
				if ((ft_coord_new(line_cpy, abs + j)) == -1)
					return (ft_exit_fdf("Coord init", NULL));
			}
			j++;
		}
		ft_strdel(&abs);
		fdf.map_info = fdf.map_info->next;
	}
	return (0);
}
