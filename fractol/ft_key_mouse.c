/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_mouse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeaun-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 14:50:15 by cmeaun-a          #+#    #+#             */
/*   Updated: 2017/03/01 19:45:19 by cmeaun-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_key_bis(int keycode, t_env *e)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 35)
	{
		e->on_p = (e->on_p == 1) ? 0 : 1;
		mlx_loop_hook(e->mlx, ft_color, e);
	}
	if (keycode == 31)
	{
		if (e->p <= 1)
			e->p += 10000;
		e->p--;
	}
	if (keycode == 124 && e->x1 < 2)
	{
		e->x1 += 1 / (e->zoom / 10);
		e->x2 += 1 / (e->zoom / 10);
	}
	if (keycode == 123)
	{
		e->x1 += -1 / (e->zoom / 10);
		e->x2 += -1 / (e->zoom / 10);
	}
}

void	ft_key_ter(int keycode, t_env *e)
{
	if (keycode == 125 && e->y1 < 2)
	{
		e->y1 += 1 / (e->zoom / 10);
		e->y2 += 1 / (e->zoom / 10);
	}
	if (keycode == 126)
	{
		e->y1 += -1 / (e->zoom / 10);
		e->y2 += -1 / (e->zoom / 10);
	}
	if (keycode == 34)
		e->iteration_max += 10;
	if (keycode == 32)
		e->iteration_max -= 10;
	if (keycode == 49)
	{
		e->on_j = (e->on_j == 1) ? 0 : 1;
		mlx_hook(e->win, MOTIONNOTIFY, POINTERMOTIONMASK, ft_motion, e);
	}
}

void	ft_key_4(int keycode, t_env *e)
{
	if (keycode == 15)
	{
		if (e->fractol == 2 || e->fractol == 6 || e->fractol == 7 ||
				e->fractol == 9)
			ft_init_julia(e);
		else
			ft_init_mandel(e);
	}
	if (keycode == 17)
		ft_list_touch();
	if (keycode == 16)
	{
		e->fractol++;
		if (e->fractol == 2 || e->fractol == 6 || e->fractol == 7 ||
				e->fractol == 9)
			ft_init_julia(e);
		else
			ft_init_mandel(e);
		if (e->fractol == 10)
			e->fractol = 1;
		ft_list_fractal(e);
	}
}

int		ft_key(int keycode, t_env *e)
{
	if (keycode == 53 || keycode == 35 || keycode == 31 || keycode == 124 ||
			keycode == 123)
		ft_key_bis(keycode, e);
	if (keycode == 126 || keycode == 34 || keycode == 32 || keycode == 49 ||
			keycode == 125)
		ft_key_ter(keycode, e);
	if (keycode == 15 || keycode == 17 || keycode == 16)
		ft_key_4(keycode, e);
	ft_bzero(e->data, L * H * 4);
	ft_draw(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	return (0);
}
