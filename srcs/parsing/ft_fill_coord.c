/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_coord.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 18:36:34 by mfranc            #+#    #+#             */
/*   Updated: 2017/04/04 17:11:54 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_coord	*ft_coord_new(char *abs, int *j)
{
	char	*hexa_to_dec;
	char	*color_hexa;
	int		ci;
	t_coord	*line;

	if (!(line = (t_coord*)malloc(sizeof(t_coord))))
		return (NULL);
	line->z = ft_atoi(abs);
	ci = ft_ilen(line->z, 10);
	*j += ci;
	if (abs[ci] != '\0' && abs[ci] == ',')
	{
		if (!(ft_strstr(abs + (ci + 1), "0x")))
			return (NULL);
		if (!(color_hexa = ft_strsub(abs, ci + 3,
						ft_strspn(abs + (ci + 3), BASELW))))
			return (NULL);
		*j += (ft_strlen(color_hexa) + 3);
		if (!(hexa_to_dec = ft_convbase(color_hexa, 16, 10, BASELW)))
			return (NULL);
		line->color = ft_atoi(hexa_to_dec);
		ft_strdel(&color_hexa);
		ft_strdel(&hexa_to_dec);
	}
	else
		line->color = 16777215;
	line->next = NULL;
	ft_printf("le Z : {grey}%d{default} - la couleur : {grey}%lu{eoc}\n", line->z, line->color);
	return (line);
}

int			ft_fill_coord(t_datacoord *dc, t_list *map_info)
{
	while (map_info && ++dc->y < dc->nb_line)
	{
		PSTR("KJBHGVF88888888888888")

		dc->line_cpy = (char*)map_info->content;
		dc->i = 0;
		while (dc->line_cpy[dc->i]
				&& (ft_isdigit(dc->line_cpy[dc->i]) == 0 && dc->line_cpy[dc->i] != '-'))
			dc->i++;
		if (dc->line_cpy[dc->i] == '\0')
			return (ft_exit_fdf("No more info in map", NULL));
		if (!(dc->coord_cpy[dc->y] = ft_coord_new(dc->line_cpy + dc->i, dc->pi)))
			return (ft_exit_fdf("Coord init", NULL));
		while (dc->line_cpy[dc->i])
		{
			if (ft_isdigit(dc->line_cpy[dc->i]) || dc->line_cpy[dc->i] == '-')
			{
				if (!(dc->coord_cpy[dc->y]->next = ft_coord_new(dc->line_cpy + dc->i, dc->pi)))
					return (ft_exit_fdf("Coord init", NULL));
				dc->coord_cpy[dc->y] = dc->coord_cpy[dc->y]->next;
			}
			else
				dc->i++;
		}
		map_info = map_info->next;
	}
	return (1);
}

int			ft_prepare_coord(t_fdf *fdf, t_datacoord *dc)
{
	if (!(dc = (t_datacoord*)malloc(sizeof(t_datacoord))))
		return (ft_exit_fdf("Coord init", NULL));
	if (!(fdf->coord = malloc(sizeof(t_coord*) * ft_listcount(fdf->map_info))))
		return (ft_exit_fdf("Coord init", NULL));
	dc->y = -1;
	dc->i = 0;
	dc->pi = &dc->i;
	dc->coord_cpy = fdf->coord;
	dc->nb_line = ft_listcount(fdf->map_info);
	return (1);
}
