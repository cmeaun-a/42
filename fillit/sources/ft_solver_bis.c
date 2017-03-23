/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solver_bis.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeaun-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 10:00:46 by cmeaun-a          #+#    #+#             */
/*   Updated: 2016/12/06 14:22:35 by cmeaun-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_initmap(size_t i)
{
	char	**map;
	size_t	tmp;

	if (!(map = (char**)malloc(sizeof(*map) * (i + 1))))
		return (NULL);
	tmp = 0;
	while (tmp < i)
	{
		map[tmp] = ft_strnew(i);
		ft_memset(map[tmp], '.', sizeof(char) * i);
		tmp++;
	}
	map[tmp] = NULL;
	return (map);
}

void	ft_printmap(char **map, size_t size)
{
	size_t	i;

	if (!map)
		return ;
	i = 0;
	while (i < size)
	{
		ft_putendl_fd(map[i], 1);
		i++;
	}
}

void	ft_map(t_tetri *tetri, int size)
{
	char	**map;

	if (!tetri)
		return ;
	map = ft_initmap(size);
	if (ft_isvalide(map, tetri, size, 'A') == 0)
	{
		free(map);
		map = NULL;
		ft_map(tetri, size + 1);
	}
	else
		ft_printmap(map, size);
}
