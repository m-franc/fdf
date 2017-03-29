/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 19:06:32 by mfranc            #+#    #+#             */
/*   Updated: 2017/03/29 21:36:54 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_parse_map(t_fdf fdf, char *map)
{
	int		fd;
	int		read;
	char	*line;
	t_list	*t;

	if (!map)
		return (ft_exit_fdf("File", NULL));
	fd = open(map, O_RDONLY);
	line = NULL;
	if ((read = get_next_line(fd, &line)) == -1)
		return (ft_exit_fdf("Reading", NULL));
	if (read == -1)
		return (ft_exit_fdf("Reading", NULL));
	if (!(fdf.coord = ft_lstnew(ft_strsplit(line, ' '), sizeof(char **))))
		return (ft_exit_fdf("Reading", NULL));
	t = fdf.coord;
	while ((read = get_next_line(fd, &line)) == 1)
	{
		ft_puttab(t->content);
		if (!(t->next = ft_lstnew(ft_strsplit(line, ' '), sizeof(char **))))
			return (ft_exit_fdf("Reading", NULL));
		ft_strdel(&line);
		t = t->next;
	}
//	while (fdf.coord)
//	{
//		ft_puttab(fdf.coord->content);
//		fdf.coord = fdf.coord->next;
//	}
	if (read == -1)
		return (ft_exit_fdf("Reading", NULL));
	return (0);
}
