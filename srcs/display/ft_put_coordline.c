/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_coordline.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/01 17:45:59 by mfranc            #+#    #+#             */
/*   Updated: 2017/04/04 20:56:45 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_put_coordline(t_coord *line)
{
	while (line)
	{
		ft_printf("z : {grey}%d{eoc} - color : {grey}%lu{eoc}\n",
				line->z, line->color);
		line = line->next;
	}
}
