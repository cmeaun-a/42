/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_block.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeaun-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 15:09:49 by cmeaun-a          #+#    #+#             */
/*   Updated: 2016/12/06 14:22:11 by cmeaun-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_strtmp(char *tetri)
{
	size_t	i;
	size_t	len;
	char	*tmp;

	if (!tetri)
		return (NULL);
	i = 0;
	len = ft_strlen(tetri);
	if (!(tmp = (char*)malloc(sizeof(*tmp) * (len - ((len + 1) / 5) + 1))))
		return (NULL);
	while (*tetri)
	{
		if (*tetri != '\n')
		{
			tmp[i] = *tetri;
			i++;
		}
		tetri++;
	}
	tmp[i] = '\0';
	return (tmp);
}

size_t	ft_nb_connect(char *tetri)
{
	size_t j;
	size_t cn;

	if (!tetri)
		return (0);
	j = 0;
	cn = 0;
	while (j < 16)
	{
		if (tetri[j] == '#')
		{
			if (j % 4 != 3 && tetri[j + 1] == '#')
				cn++;
			if (j % 4 != 0 && tetri[j - 1] == '#')
				cn++;
			if (j > 3 && tetri[j - 4] == '#')
				cn++;
			if (j < 12 && tetri[j + 4] == '#')
				cn++;
		}
		j++;
	}
	return (cn);
}

int		ft_ch_cn(char *tetri)
{
	size_t		i;
	size_t		check;

	if (!tetri)
		return (0);
	i = 0;
	while (i < ft_strlen(tetri))
	{
		check = ft_nb_connect(&tetri[i]);
		if (check != 6 && check != 8)
			return (0);
		i += 16;
	}
	return (1);
}
