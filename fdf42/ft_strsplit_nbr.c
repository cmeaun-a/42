/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_nbr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeaun-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 17:42:01 by cmeaun-a          #+#    #+#             */
/*   Updated: 2017/02/14 17:54:13 by cmeaun-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		ft_nbword(char const *s, char c)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;

	if (!s)
		return (0);
	i = 0;
	j = 0;
	k = 0;
	while (s[i] == c && s[i])
		i++;
	while (s[i])
	{
		if (s[i] == c || s[i + 1] == '\0')
			j++;
		if (s[i] == c && (s[i + 1] == c && s[i + 1]))
			k++;
		i++;
	}
	return (j - k);
}

static int		ft_lenword(char const *s, char c)
{
	unsigned int i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != c && s[i])
	{
		i++;
	}
	return (i);
}

int				*ft_strsplit_nbr(char const *s, char c, int *w)
{
	int		*tab;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	*w = ft_nbword(s, c);
	if (!(tab = (int*)malloc(sizeof(*tab) * (*w))))
		return (NULL);
	i = 0;
	j = 0;
	while (j < *w)
	{
		while (s[i] == c)
			i++;
		tab[j] = ft_atoi(&s[i]);
		i = i + ft_lenword(&s[i], c);
		j++;
	}
	return (tab);
}
