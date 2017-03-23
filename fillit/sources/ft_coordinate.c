/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_coordinate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeaun-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 11:41:57 by cmeaun-a          #+#    #+#             */
/*   Updated: 2016/12/05 16:27:27 by cmeaun-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_coord	ft_initcoord(int x, int y)
{
	t_coord res;

	res.x = x;
	res.y = y;
	return (res);
}

t_tetri	*ft_inittetri(void)
{
	t_tetri	*res;

	if (!(res = (t_tetri*)malloc(sizeof(t_tetri))))
		return (NULL);
	res->next = NULL;
	return (res);
}

void	ft_chartocoord_2(char *sub, t_tetri *tmp, int i)
{
	int j;
	int nbdz;

	if (!sub || !tmp)
		return ;
	while (sub[i] != '#')
		i++;
	j = i + 1;
	nbdz = 0;
	while (nbdz < 3)
	{
		if (sub[j] == '#' && j)
		{
			tmp->pts[nbdz] = ft_initcoord(j % 4 - i % 4, j / 4 - i / 4);
			nbdz++;
		}
		j++;
	}
}

t_tetri	*ft_chartocoord(char *tetri)
{
	size_t		i;
	t_tetri		*res;
	t_tetri		*tmp;
	char		*sub;

	if (!tetri)
		return (NULL);
	res = ft_inittetri();
	tmp = res;
	i = 0;
	sub = ft_strsub(tetri, 0, 16);
	while (sub)
	{
		ft_chartocoord_2(sub, tmp, i);
		if (ft_strlen(tetri) > 16)
		{
			tmp->next = ft_inittetri();
			tmp = tmp->next;
			tetri += 16;
			sub = ft_strsub(tetri, 0, 16);
		}
		else
			sub = 0;
	}
	return (res);
}
