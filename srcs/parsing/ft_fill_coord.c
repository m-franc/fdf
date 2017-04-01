/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_coord.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 18:36:34 by mfranc            #+#    #+#             */
/*   Updated: 2017/04/01 19:29:19 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_coord	*ft_coord_new(char *abs)
{
	char	*hexa_to_dec;
	char	*color_hexa;
	int		ci;
	t_coord	*line;

	if (!(line = (t_coord*)malloc(sizeof(t_coord))))
		return (NULL);
	line->z = ft_atoi(abs);
	ci = ft_ilen(line->z, 10) + 1;
	if (abs[ci] != '\0' && abs[ci] == ',')
	{
		if (!(color_hexa = ft_strsub(abs, ci, ft_strspn(abs + ci, BASELW))))
			return (NULL);
		if (!(hexa_to_dec = ft_convbase(color_hexa, 16, 10, BASELW)))
			return (NULL);
		line->color = ft_atoi(hexa_to_dec);
		ft_strdel(&color_hexa);
		ft_strdel(&hexa_to_dec);
	}		
	else	
		line->color = 16777215;
	PSTR("BONJOUR\n")
	ft_printf("z : {grey}%d{eoc} - color : {grey}%lu{eoc}\n", line->z, line->color); 
	line->next = NULL;
	return (line);
}

int			ft_fill_coord(t_fdf fdf)
{
	int		y;
	int		j;
	t_coord	**coord_cpy;
	char	*abs;
	
	y = -1;
	if (!(fdf.coord = malloc(sizeof(t_coord*) * ft_listcount(fdf.map_info))))
		return (ft_exit_fdf("Coord init", NULL));
	coord_cpy = fdf.coord;
	while (fdf.map_info->next && ++y < (int)ft_listcount(fdf.map_info))
	{
		abs = (char*)fdf.map_info->content;
		j = 0;
		while (abs[j] && (ft_isdigit(abs[j]) == 0 && abs[j] != '-'))
			j++;
		if (abs[j] == '\0')
			return (ft_exit_fdf("No more info in map", NULL));
		if (!(coord_cpy[y] = ft_coord_new(abs + j)))
			return (ft_exit_fdf("Coord init", NULL));
		while (abs[j])
		{
			if (ft_isdigit(abs[j]) || abs[j] == '-')
			{
				if (!(coord_cpy[y]->next = ft_coord_new(abs + j)))
					return (ft_exit_fdf("Coord init", NULL));
				coord_cpy[y] = coord_cpy[y]->next;
			}
			j++;
		}
		ft_lstdelone(&fdf.map_info);
		fdf.map_info = fdf.map_info->next;
	}
	ft_lstdelone(&fdf.map_info->next);
	return (0);
}
