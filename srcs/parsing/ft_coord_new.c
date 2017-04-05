/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_coord_new.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 21:36:45 by mfranc            #+#    #+#             */
/*   Updated: 2017/04/05 13:04:37 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_get_color(char **abs, int ci, int *j, t_coord **line)
{
	char	*color_hexa;
	char	*hexa_to_dec;

	if (!(ft_strstr(*abs + (ci + 1), "0x")))
		return (-1);
	if (!(color_hexa = ft_strsub(*abs, ci + 3,
					ft_strspn(*abs + (ci + 3), HEXA))))
		return (-1);
	*j += (ft_strlen(color_hexa) + 3);
	if (!(hexa_to_dec = ft_convbase(color_hexa, 16, 10, HEXA)))
		return (-1);
	(*line)->color = ft_atoi(hexa_to_dec);
	ft_strdel(&color_hexa);
	ft_strdel(&hexa_to_dec);
	return (1);
}

t_coord		*ft_coord_new(char *abs, int *j)
{
	int		ci;
	t_coord	*line;

	if (!(line = (t_coord*)malloc(sizeof(*line))))
		return (NULL);
	line->z = ft_atoi(abs);
	ci = ft_ilen(line->z, 10);
	*j += ci;
	if (abs[ci] != '\0' && abs[ci] == ',')
	{
		if ((ft_get_color(&abs, ci, j, &line)) == -1)
			return (NULL);
	}
	else
		line->color = 16777215;
	line->next = NULL;
	return (line);
}