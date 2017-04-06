/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_coord.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 18:36:34 by mfranc            #+#    #+#             */
/*   Updated: 2017/04/06 16:24:55 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_fill_first(t_datacoord *dc)
{
	while (dc->line_cpy[*dc->pi] && (ft_isdigit(dc->line_cpy[*dc->pi]) == 0
				&& dc->line_cpy[*dc->pi] != '-'))
		*dc->pi += 1;
	if (dc->line_cpy[*dc->pi] == '\0')
		return (-1);
	if (!(dc->cl_cpy = ft_coord_new(dc->line_cpy + *dc->pi, dc->pi)))
		return (-1);
	return (1);
}

int			ft_fill_coord(t_datacoord *dc)
{
	while (dc->map_info && dc->y < dc->nb_line)
	{
		dc->line_cpy = (char*)dc->map_info->content;
		dc->i = 0;		
		if ((ft_fill_first(dc)) == -1)
			return (ft_exit_fdf("Coord init", NULL));
		dc->coord_cpy[dc->y] = dc->cl_cpy;
		while (dc->line_cpy[dc->i])
		{
			if (ft_isdigit(dc->line_cpy[dc->i]) || dc->line_cpy[dc->i] == '-')
			{
				if (!(dc->cl_cpy->next = ft_coord_new(dc->line_cpy + dc->i, dc->pi)))
					return (ft_exit_fdf("Coord init", NULL));	
				dc->cl_cpy = dc->cl_cpy->next;
			}
			else
				dc->i++;
		}
		dc->map_info = dc->map_info->next;
		dc->y++;
	}
	dc->coord_cpy[dc->y] = 0;
	return (1);
}
