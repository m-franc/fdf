/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_coordline.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/01 17:45:59 by mfranc            #+#    #+#             */
/*   Updated: 2017/06/06 22:32:35 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			ft_count_coord(t_coord *line)
{
	int i;

	i = 0;
	while (line)
	{
		line = line->next;
		i++;
	}
	return (i);
}

void		ft_putline(t_coord *line)
{
	if (!line)
		return ;
	ft_putchar('|');
	while (line)
	{
		ft_printf("{grey}%d{eoc}{cyan}%d{eoc}{red}%d{eoc} ",
				line->x, line->y, line->z);
		line = line->next;
	}
	ft_putchar('|');
}

void		ft_putcoord(t_coord **coord)
{
	int	i;

	i = -1;
	while (coord[++i])
		ft_putline(coord[i]);
}
