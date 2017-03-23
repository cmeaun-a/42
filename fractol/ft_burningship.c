/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_burningship.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeaun-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 13:36:02 by cmeaun-a          #+#    #+#             */
/*   Updated: 2017/03/01 17:38:53 by cmeaun-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_burningship_cal(t_env *e, int *i)
{
	while (e->z_r * e->z_r + e->z_i * e->z_i < 4 && *i < e->iteration_max)
	{
		e->tmp = e->z_r;
		e->z_r = (e->z_r) * (e->z_r) - (e->z_i) * (e->z_i) + e->c_r;
		e->z_i = 2 * fabs(e->z_i) * fabs(e->tmp) + e->c_i;
		(*i)++;
	}
	e->color = *i * 80000 * e->p;
}

void	ft_burningship(t_env *e)
{
	int x;
	int	y;
	int i;

	x = 0;
	while (x < e->image_x && x < L)
	{
		y = 0;
		while (y < e->image_y && y < H)
		{
			e->c_r = x / e->zoom + e->x1;
			e->c_i = y / e->zoom + e->y1;
			e->z_r = 0;
			e->z_i = 0;
			i = 0;
			ft_burningship_cal(e, &i);
			if (i == e->iteration_max)
				ft_put_pixel_to_image(e, x, y, 0x000000);
			else
				ft_put_pixel_to_image(e, x, y, e->color);
			y++;
		}
		x++;
	}
}

void	ft_tricorn_cal(t_env *e, int *i)
{
	while (e->z_r * e->z_r + e->z_i * e->z_i < 4 && *i < e->iteration_max)
	{
		e->tmp = e->z_r;
		e->z_r = (e->z_r) * (e->z_r) - (e->z_i) * (e->z_i) + e->c_r;
		e->z_i = -2 * (e->z_i) * (e->tmp) + e->c_i;
		(*i)++;
	}
	e->color = *i * 80000 * e->p;
}

void	ft_tricorn(t_env *e)
{
	int x;
	int	y;
	int i;

	x = 0;
	while (x < e->image_x && x < L)
	{
		y = 0;
		while (y < e->image_y && y < H)
		{
			e->c_r = x / e->zoom + e->x1;
			e->c_i = y / e->zoom + e->y1;
			e->z_r = 0;
			e->z_i = 0;
			i = 0;
			ft_tricorn_cal(e, &i);
			if (i == e->iteration_max)
				ft_put_pixel_to_image(e, x, y, 0x000000);
			else
				ft_put_pixel_to_image(e, x, y, e->color);
			y++;
		}
		x++;
	}
}
