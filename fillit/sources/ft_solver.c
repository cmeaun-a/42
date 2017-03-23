/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solver.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeaun-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 11:43:15 by cmeaun-a          #+#    #+#             */
/*   Updated: 2016/12/06 14:23:47 by cmeaun-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_point(char **map, t_tetri *tetri, t_coord pos)
{
	if (!map || !tetri)
		return (0);
	return (map[pos.y][pos.x] == '.'
			&& map[pos.y + tetri->pts[0].y][pos.x + tetri->pts[0].x] == '.'
			&& map[pos.y + tetri->pts[1].y][pos.x + tetri->pts[1].x] == '.'
			&& map[pos.y + tetri->pts[2].y][pos.x + tetri->pts[2].x] == '.');
}

void	ft_replace(char **map, t_tetri *tetri, t_coord pos, char alpha)
{
	if (!map || !tetri)
		return ;
	map[pos.y][pos.x] = alpha;
	map[pos.y + tetri->pts[0].y][pos.x + tetri->pts[0].x] = alpha;
	map[pos.y + tetri->pts[1].y][pos.x + tetri->pts[1].x] = alpha;
	map[pos.y + tetri->pts[2].y][pos.x + tetri->pts[2].x] = alpha;
}

void	ft_limit_x(t_tetri *tetri, t_coord *pos, int size)
{
	if (!tetri)
		return ;
	if (pos->x >= size || pos->x + tetri->pts[0].x >= size
		|| pos->x + tetri->pts[1].x >= size
		|| pos->x + tetri->pts[2].x >= size)
	{
		pos->x = 0;
		pos->y++;
	}
}

int		ft_isvalide_2(char **map, t_tetri *tetri, int size, char alpha)
{
	t_coord pos;

	if (!map || !tetri)
		return (0);
	pos = ft_initcoord(0, 0);
	while (pos.y < size && pos.y + tetri->pts[0].y < size
		&& pos.y + tetri->pts[1].y < size && pos.y + tetri->pts[2].y < size)
	{
		while (pos.x + tetri->pts[0].x < 0 || pos.x + tetri->pts[1].x < 0
				|| pos.x + tetri->pts[2].x < 0)
			pos.x++;
		if (ft_point(map, tetri, pos))
		{
			ft_replace(map, tetri, pos, alpha);
			if (ft_isvalide(map, tetri->next, size, alpha + 1) == 0)
				ft_replace(map, tetri, pos, '.');
			else
				return (1);
		}
		pos.x++;
		ft_limit_x(tetri, &pos, size);
	}
	return (0);
}

int		ft_isvalide(char **map, t_tetri *tetri, int size, char alpha)
{
	if (!tetri)
		return (1);
	if (!map)
		return (0);
	return (ft_isvalide_2(map, tetri, size, alpha));
}
