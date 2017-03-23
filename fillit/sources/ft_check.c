/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcentaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 11:47:54 by jcentaur          #+#    #+#             */
/*   Updated: 2016/12/05 16:19:43 by cmeaun-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_ch_len(char *tetri)
{
	int		i;
	int		len;

	if (!tetri)
		return (0);
	i = 0;
	while (tetri[i])
	{
		len = 0;
		while (tetri[i] == '.' || tetri[i] == '#')
		{
			len++;
			i++;
		}
		if (len != 4 && len != 0)
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int		ft_ch_rt(char *tetri)
{
	int i;
	int len;

	if (!tetri)
		return (0);
	len = ft_strlen(tetri);
	i = 20;
	while (i < len)
	{
		if (tetri[i] != '\n')
			return (0);
		i = i + 21;
	}
	if (tetri[len - 2] == '\n' || tetri[len - 23] == '\n' || !len)
		return (0);
	return (1);
}

int		ft_ch_dz(char *tetri)
{
	int i;
	int j;
	int len;
	int dz;

	if (!tetri)
		return (0);
	i = 0;
	len = ft_strlen(tetri);
	while (i < len)
	{
		j = 0;
		dz = 0;
		while (j < 20)
		{
			if (tetri[j + i] == '#')
				dz++;
			j++;
		}
		if (dz != 4)
			return (0);
		i = i + 21;
	}
	return (1);
}

int		ft_ch_pt(char *tetri)
{
	int i;
	int j;
	int len;
	int dz;

	if (!tetri)
		return (0);
	i = 0;
	len = ft_strlen(tetri);
	while (i < len)
	{
		j = 0;
		dz = 0;
		while (j < 20)
		{
			if (tetri[j + i] == '.')
				dz++;
			j++;
		}
		if (dz != 12)
			return (0);
		i = i + 21;
	}
	return (1);
}

int		ft_check(char *tetri)
{
	int			i;

	if (!tetri)
		return (0);
	i = 0;
	while (tetri[i])
	{
		if (tetri[i] != '.' && tetri[i] == '#' && tetri[i] == '\n')
		{
			return (0);
		}
		i++;
	}
	if (ft_ch_pt(tetri) == 0 || ft_ch_len(tetri) == 0
			|| ft_ch_rt(tetri) == 0 || ft_ch_dz(tetri) == 0)
		return (0);
	return (1);
}
