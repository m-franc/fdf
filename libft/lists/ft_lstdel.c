/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 21:50:14 by mfranc            #+#    #+#             */
/*   Updated: 2017/02/09 20:04:38 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst)
{
	if (alst)
	{
		while ((*alst))
		{
			free((*alst)->content);
			(*alst)->content = NULL;
			(*alst)->content_size = 0;
			free(*alst);
			(*alst) = (*alst)->next;
		}
		(*alst) = NULL;
	}
}
