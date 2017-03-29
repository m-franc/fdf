/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_fdf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 21:08:06 by mfranc            #+#    #+#             */
/*   Updated: 2017/03/29 21:08:18 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			ft_exit_fdf(char *msg, ...)
{
	void	*elem;
	va_list	ap;

	va_start(ap, msg);
	while (!(elem = va_arg(ap, void *)))
		ft_memdel(&elem);
	ft_printf("%s Error\n", msg);
	return (-1);
}
