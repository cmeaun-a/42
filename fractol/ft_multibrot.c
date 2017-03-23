/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_multibrot.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeaun-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 14:31:01 by cmeaun-a          #+#    #+#             */
/*   Updated: 2017/03/01 17:43:17 by cmeaun-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_mandel_3_cal(t_env *e, int *i)
{
	while (e->z_r * e->z_r + e->z_i * e->z_i < 4 && *i < e->iteration_max)
	{
		e->tmp = e->z_r * e->z_r * e->z_r - 3 * e->z_r * e->z_i * e->z_i +
			e->c_r;
		e->z_i = 3 * e->z_r * e->z_r * e->z_i - e->z_i * e->z_i * e->z_i +
			e->c_i;
		e->z_r = e->tmp;
		(*i)++;
	}
	e->color = *i * 80000 * e->p;
}

void	ft_mandel_3(t_env *e)
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
			ft_mandel_3_cal(e, &i);
			if (i == e->iteration_max)
				ft_put_pixel_to_image(e, x, y, 0x000000);
			else
				ft_put_pixel_to_image(e, x, y, e->color);
			y++;
		}
		x++;
	}
}

void	ft_mandel_5_cal(t_env *e, int *i)
{
	while (e->z_r * e->z_r + e->z_i * e->z_i < 4 && *i < e->iteration_max)
	{
		e->tmp = e->z_r * e->z_r * e->z_r * e->z_r * e->z_r - 10 *
			e->z_r * e->z_r * e->z_r * e->z_i * e->z_i + 5 * e->z_r *
			e->z_i * e->z_i * e->z_i * e->z_i + e->c_r;
		e->z_i = 5 * e->z_r * e->z_r * e->z_r * e->z_r * e->z_i - 10 *
			e->z_r * e->z_r * e->z_i * e->z_i * e->z_i + e->z_i *
			e->z_i * e->z_i * e->z_i * e->z_i + e->c_i;
		e->z_r = e->tmp;
		(*i)++;
	}
	e->color = *i * 80000 * e->p;
}

void	ft_mandel_5(t_env *e)
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
			ft_mandel_5_cal(e, &i);
			if (i == e->iteration_max)
				ft_put_pixel_to_image(e, x, y, 0x000000);
			else
				ft_put_pixel_to_image(e, x, y, e->color);
			y++;
		}
		x++;
	}
}
