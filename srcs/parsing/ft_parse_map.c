/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_parse_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Creatested: 2017/03/29 19:06:32 by mfranc            #+#    #+#             */
/*   Updatested: 2017/03/30 15:50:54 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			ft_get_map_info(t_fdf fdf, char *map)
{
	int		fd;
	int		read;
	char	*line;
	t_list	*test;

	fd = open(map, O_RDONLY);
	if ((read = get_next_line(fd, &line)) == -1)
		return (ft_exit_fdf("Reading", NULL));
	if (!(fdf.map_info = ft_lstnew(line, (ft_strlen(line) + 1))))
		return (ft_exit_fdf("Storage line", NULL));
	ft_strdel(&line);
	test = fdf.map_info;
	while ((read = get_next_line(fd, &line)) == 1)
	{
		if (!(test->next = ft_lstnew(line, (ft_strlen(line) + 1))))
			return (ft_exit_fdf("Storage line", NULL));
		ft_strdel(&line);
		test = test->next;
	}
	if (read == -1)
		return (ft_exit_fdf("Reading", NULL));
	if ((ft_fill_coord(fdf)) == -1)
		return (-1);
	return (1);
}
