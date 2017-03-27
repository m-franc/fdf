/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 13:38:43 by mfranc            #+#    #+#             */
/*   Updated: 2017/02/16 19:57:40 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_complete_precision(char **second, int l_sec)
{
	char	*complete;

	if (!(complete = ft_strnew(l_sec)))
		return (NULL);
	while (l_sec-- > 0)
		complete[l_sec] = '0';
	if (!(complete = ft_strjoin(*second, complete)))
		return (NULL);
	return (complete);
}

static char	*ft_zero_precision(char *sec)
{
	int	i;

	i = 0;
	if (!(sec = ft_memalloc(6 * sizeof(*sec))))
		return (NULL);
	while (i < 6)
		sec[i++] = '0';
	sec[i] = '\0';
	return (sec);
}

static char	*ft_get_precision(long double n, int base, char *bl)
{
	char	*sec;
	char	*cp;

	sec = NULL;
	if (n == 0)
	{
		if (!(sec = ft_zero_precision(sec)))
			return (NULL);
		return (sec);
	}
	else
	{
		if (!(sec = ft_itoa(n, base, bl)))
			return (NULL);
		if (ft_strlen(sec) < 6)
		{
			if (!(cp = ft_complete_precision(&sec, 6 - ft_strlen(sec))))
				return (NULL);
			ft_strdel(&sec);
			return (cp);
		}
		return (sec);
	}
}

char		*ft_ftoa(long double n, int base, char *bl)
{
	char		*result;
	char		*entier;
	char		*second;
	char		*getdot;
	long double	tmp;

	if (!(entier = ft_itoa(n, base, bl)))
		return (NULL);
	n = ((n - ft_atoi(entier)) * 100);
	n = ABS(n);
	tmp = n;
	while (((long long)tmp % 10) != 0)
	{
		n /= 10;
		tmp *= 10;
	}
	second = ft_get_precision(tmp, base, bl);
	if (!(getdot = ft_straddchar(entier, '.')))
		return (NULL);
	entier = getdot;
	if (!(result = ft_strjoin(entier, second)))
		return (NULL);
	ft_strdel(&entier);
	ft_strdel(&second);
	return (result);
}
