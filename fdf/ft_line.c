/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeaun-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/05 22:42:15 by cmeaun-a          #+#    #+#             */
/*   Updated: 2017/02/10 15:54:06 by cmeaun-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_draw_1(t_env *e, int x, int y)
{
	int	cumul;
	int	i;

	cumul = e->dx / 2;
	i = 1;
	while (i <= e->dx)
	{
		x += e->xinc;
		cumul += e->dy;
		if (cumul >= e->dx)
		{
			cumul -= e->dx;
			y += e->yinc;
		}
		ft_put_pixel_to_image(e, x, y, e->color);
		i++;
	}
}

void	ft_draw_2(t_env *e, int x, int y)
{
	int	cumul;
	int	i;

	cumul = e->dy / 2;
	i = 1;
	while (i <= e->dy)
	{
		y += e->yinc;
		cumul += e->dx;
		if (cumul >= e->dy)
		{
			cumul -= e->dy;
			x += e->xinc;
		}
		ft_put_pixel_to_image(e, x, y, e->color);
		i++;
	}
}

void	ft_draw_line(t_env *e, t_point pt1, t_point pt2)
{
	int	x;
	int	y;

	x = pt1.x;
	y = pt1.y;
	e->dx = pt2.x - pt1.x;
	e->dy = pt2.y - pt1.y;
	e->xinc = (e->dx > 0) ? 1 : -1;
	e->yinc = (e->dy > 0) ? 1 : -1;
	e->dx *= (e->dx < 0) ? -1 : 1;
	e->dy *= (e->dy < 0) ? -1 : 1;
	ft_put_pixel_to_image(e, x, y, e->color);
	if (e->dx > e->dy)
		ft_draw_1(e, x, y);
	else
		ft_draw_2(e, x, y);
}
