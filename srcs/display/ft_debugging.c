/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_coordline.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/01 17:45:59 by mfranc            #+#    #+#             */
/*   Updated: 2017/04/06 16:21:16 by mfranc           ###   ########.fr       */
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

void		ft_putline(t_coord *line)
{
	if (!line)
		return ;
	ft_printf("ligne : \n");
	while (line)
	{
		ft_printf("{green}%d{eoc},{red}%lu{eoc} ", line->z, line->color);
		line = line->next;
	}
	ENDL
}

void		ft_putcoord(t_coord **coord)
{
	int	i;

	i = -1;
	while (coord[++i])
		ft_putline(coord[i]);
}
