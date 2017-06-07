/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 21:56:07 by mfranc            #+#    #+#             */
/*   Updated: 2017/06/07 12:32:53 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			ft_get_map_info(t_fdf *fdf, char *map)
{
	int		fd;
	int		read;
	char	*line;
	t_list	*test;

	if ((fd = open(map, O_RDONLY)) == -1)
		return (ft_exit_fdf("File"));
	if ((read = get_next_line(fd, &line)) == -1)
		return (ft_exit_fdf("Reading"));
	if (!(fdf->map_info = ft_lstnew(line, (ft_strlen(line) + 1))))
		return (ft_exit_fdf("Storage line"));
	ft_strdel(&line);
	test = fdf->map_info;
	while ((read = get_next_line(fd, &line)) == 1)
	{
		if (!(test->next = ft_lstnew(line, (ft_strlen(line) + 1))))
			return (ft_exit_fdf("Storage line"));
		ft_strdel(&line);
		test = test->next;
	}
	if (read == -1)
		return (ft_exit_fdf("Reading"));
	return (1);
}
