/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 17:10:28 by mfranc            #+#    #+#             */
/*   Updated: 2016/11/23 12:31:08 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_word_count(char const *s, char c)
{
	int	result;
	int	i;

	i = 0;
	result = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			result++;
		i++;
	}
	return (result);
}

static	size_t	ft_slen_untilc(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	return (i);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		i;
	int		j;

	if ((!s) || !(tab = (char **)malloc(sizeof(*tab)
					* (ft_word_count(s, c)))))
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i])
		{
			if (!(tab[j] = (char*)malloc(sizeof(tab[j]) *
							(ft_slen_untilc(s + i, c)))))
				return (NULL);
			tab[j++] = ft_strsub(s, i, ft_slen_untilc(s + i, c));
			while (s[i] != c && s[i])
				i++;
		}
	}
	tab[j] = 0;
	return (tab);
}
