/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_coordline.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/01 17:45:59 by mfranc            #+#    #+#             */
/*   Updated: 2017/04/05 18:10:52 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			ft_count_coord(t_coord *line)
{
	int i = 0;
	while (line)
	{
		line = line->next;
		i++;
	}
	return (i);
}

void		ft_putcoord(t_coord *line)
{
	if (!line)
		return ;
	while (line)
	{
		ft_printf("{green}%d{eoc},{red}%lu{eoc} ", line->z, line->color);
		line = line->next;
	}
	ENDL
}

void		ft_put_coordline(t_coord **line)
{
		ft_putcoord(line[0]);
		ft_putcoord(line[1]);
		ft_putcoord(line[2]);
		ft_putcoord(line[3]);
		ft_putcoord(line[4]);
		ft_putcoord(line[5]);
		ft_putcoord(line[6]);
		ft_putcoord(line[7]);
		ft_putcoord(line[8]);
		ft_putcoord(line[9]);
		ft_putcoord(line[10]);
}
