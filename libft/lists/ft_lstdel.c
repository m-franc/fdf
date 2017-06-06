/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 21:50:14 by mfranc            #+#    #+#             */
/*   Updated: 2017/06/06 23:19:19 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst)
{
	t_list	*tmp;
	t_list	*to_free;

	if (alst && *alst)
	{
		tmp = *alst;
		while (tmp)
		{
			to_free = tmp;
			tmp = tmp->next;
			free(to_free->content);
			to_free->content = NULL;
			to_free->content_size = 0;
			free(to_free);
		}
		(*alst) = NULL;
	}
}
