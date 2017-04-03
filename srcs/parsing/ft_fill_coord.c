/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_coord.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 18:36:34 by mfranc            #+#    #+#             */
/*   Updated: 2017/04/03 20:27:47 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_coord	*ft_coord_new(char *abs, int *j)
{
//	char	*hexa_to_dec;
//	char	*color_hexa;
	int		ci;
	t_coord	*line;

	ft_printf("Le reste de la ligne de coord a stock : {blue}|%s|{eoc}\n", abs);
	if (!(line = (t_coord*)malloc(sizeof(t_coord))))
		return (NULL);
	line->z = ft_atoi(abs);
	ci = ft_ilen(line->z, 10);
//	if (abs[ci] == '\0')
//	{
//		line->color = 16777215;
//		return (line);
//	}
	*j += ci;
//	ft_printf("Apres le Z : {green}|%c|{eoc}\n", abs[ci]);
/*	if (abs[ci] != '\0' && abs[ci] == ',')
	{
		if (!(ft_strstr(abs + (ci + 1), "0x")))
			return (NULL);
		if (!(color_hexa = ft_strsub(abs, ci + 3,
						ft_strspn(abs + (ci + 3), BASELW))))
			return (NULL);
		ft_printf("la couleur : {purple}|%s|{eoc}\n", color_hexa);
		*j += (ft_strlen(color_hexa) + 3);
		if (!(hexa_to_dec = ft_convbase(color_hexa, 16, 10, BASELW)))
			return (NULL);
		line->color = ft_atoi(hexa_to_dec);
		ft_strdel(&color_hexa);
		ft_strdel(&hexa_to_dec);
	}
	else*/	
	line->color = 16777215;
	ft_printf("z : {grey}%d{eoc} - color : {grey}%lu{eoc}\n\n", line->z, line->color); 
	line->next = NULL;
	return (line);
}

int			ft_fill_coord(t_fdf fdf)
{
	int		y;
	int		j;
	int		*pj;
	t_coord	**coord_cpy;
	char	*abs;
	int		lenfile;
	
	y = -1;
	if (!(fdf.coord = malloc(sizeof(t_coord*) * ft_listcount(fdf.map_info))))
		return (ft_exit_fdf("Coord init", NULL));
	coord_cpy = fdf.coord;
	ft_printf("==========================|%d|\n", ft_listcount(fdf.map_info));
	lenfile = ft_listcount(fdf.map_info);
	while (fdf.map_info && ++y < lenfile)
	{
		abs = (char*)fdf.map_info->content;
		j = 0;
		pj = &j;
		while (abs[j] && (ft_isdigit(abs[j]) == 0 && abs[j] != '-'))
			j++;
		if (abs[j] == '\0')
			return (ft_exit_fdf("No more info in map", NULL));
		if (!(coord_cpy[y] = ft_coord_new(abs + j, &j)))
			return (ft_exit_fdf("Coord init", NULL));
		while (abs[j])
		{
			ft_printf("---------------------------{green}|%c|{eoc}\n", abs[j]);
			if (ft_isdigit(abs[j]) || abs[j] == '-')
			{
				if (!(coord_cpy[y]->next = ft_coord_new(abs + j, &j)))
					return (ft_exit_fdf("Coord init", NULL));
				coord_cpy[y] = coord_cpy[y]->next;
			}
			else
				j++;
			ft_putstrcolor("COUCOU\n", PURPLE);
		}
		ft_putstrcolor("COUCOUCAPASEE\n", GREEN);
		ft_printf("Valeur du y : {green}|%d{eoc}\n", y);
	//	ft_lstdelone(&fdf.map_info);
		fdf.map_info = fdf.map_info->next;
	}
//	ft_lstdelone(&fdf.map_info->next);
	return (0);
}
