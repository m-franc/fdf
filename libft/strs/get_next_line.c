/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 14:32:21 by mfranc            #+#    #+#             */
/*   Updated: 2017/04/05 17:28:16 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_file				*lstnew(t_file **begin, int fd)
{
	t_file			*new;

	if (!*begin)
	{
		if (!(*begin = (t_file*)malloc(sizeof(t_file))))
			return (NULL);
		(*begin)->fd = fd;
		(*begin)->tmp = ft_strnew(0);
		(*begin)->next = NULL;
		return (*begin);
	}
	else
	{
		if (!(new = (t_file*)malloc(sizeof(t_file))))
			return (NULL);
		new->fd = fd;
		new->tmp = ft_strnew(0);
		new->next = *begin;
		*begin = new;
		return (new);
	}
}

t_file				*get_file(t_file **begin, int fd)
{
	t_file			*tmplst;
	t_file			*tmpnext;

	if (!*begin)
		return (*begin = lstnew(begin, fd));
	if ((*begin)->fd == fd)
		return (*begin);
	tmplst = *begin;
	tmpnext = (*begin)->next;
	while (tmpnext)
	{
		if (tmpnext->fd == fd)
		{
			tmplst->next = tmpnext->next;
			tmpnext->next = *begin;
			*begin = tmpnext;
			return (*begin);
		}
		tmplst = tmplst->next;
		tmpnext = tmpnext->next;
	}
	return (lstnew(begin, fd));
}

void				remove_file(t_file **file)
{
	t_file	*supp;

	supp = *file;
	supp->fd = -1;
	ft_strdel(&((*file)->tmp));
	if ((*file)->next)
	{
		free(supp);
		*file = (*file)->next;
	}
	else
		free(supp);
}

int					save_lines(char *ndtmp, t_file **file, char **line)
{
	char			*nexttmp;

	if ((*file)->tmp[0] == '\0')
	{
		remove_file(file);
		return (0);
	}
	if (ndtmp == NULL)
	{
		*line = ft_strdup((*file)->tmp);
		ft_bzero((*file)->tmp, ft_strlen((*file)->tmp));
		return (1);
	}
	else
	{
		*line = ft_strsub((*file)->tmp, 0, ft_strlen((*file)->tmp)
				- ft_strlen(ndtmp));
		nexttmp = (*file)->tmp;
		(*file)->tmp = ft_strdup(ndtmp + 1);
		ft_strdel(&nexttmp);
		return (1);
	}
}

int					get_next_line(const int fd, char **line)
{
	char			buf[BUFF_SIZE + 1];
	int				ret;
	char			*tmpline;
	char			*ndtmp;
	static t_file	*file;

	if (!line)
		return (-1);
	file = get_file(&file, fd);
	*line = NULL;
	ndtmp = ft_strchr(file->tmp, '\n');
	while (!ndtmp || *((file)->tmp))
	{
		if ((ret = read(file->fd, buf, BUFF_SIZE)) == 0)
			break ;
		if (ret < 0)
			return (-1);
		buf[ret] = '\0';
		tmpline = file->tmp;
		file->tmp = ft_strjoin(tmpline, buf);
		ft_strdel(&tmpline);
		ndtmp = ft_strchr(file->tmp, '\n');
	}
	return (save_lines(ndtmp, &file, line));
}
