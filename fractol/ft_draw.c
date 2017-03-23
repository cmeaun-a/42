/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeaun-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 14:43:27 by cmeaun-a          #+#    #+#             */
/*   Updated: 2017/03/01 19:05:06 by cmeaun-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_put_pixel_to_image(t_env *e, int x, int y, int color)
{
	int		i;

	if (x < 0 || x >= L || y < 0 || y >= H)
		return ;
	if ((e)->endian == 0)
	{
		i = ((e)->sizeline * y) + (x * ((e)->bpp / 8));
		(e)->data[i] = mlx_get_color_value((e)->mlx, color);
		(e)->data[i + 1] = mlx_get_color_value((e)->mlx, color >> 8);
		(e)->data[i + 2] = mlx_get_color_value((e)->mlx, color >> 16);
	}
	else
	{
		i = ((e)->sizeline * y) + (x * ((e)->bpp / 8));
		(e)->data[i] = mlx_get_color_value((e)->mlx, color >> 16);
		(e)->data[i + 1] = mlx_get_color_value((e)->mlx, color >> 8);
		(e)->data[i + 2] = mlx_get_color_value((e)->mlx, color);
	}
}

void	ft_draw(t_env *e)
{
	if (e->fractol == 1)
		ft_mandelbrot(e);
	if (e->fractol == 2)
		ft_julia(e);
	if (e->fractol == 3)
		ft_mandel_3(e);
	if (e->fractol == 4)
		ft_mandel_5(e);
	if (e->fractol == 5)
		ft_burningship(e);
	if (e->fractol == 6)
		ft_julia_3(e);
	if (e->fractol == 7)
		ft_julia_5(e);
	if (e->fractol == 8)
		ft_tricorn(e);
	if (e->fractol == 9)
		ft_tricorn5(e);
}

void	ft_list_fractal(t_env *e)
{
	if (e->fractol == 1)
		ft_putstr("Mandelbrot\n");
	if (e->fractol == 2)
		ft_putstr("Julia\n");
	if (e->fractol == 3)
		ft_putstr("Mandel 3\n");
	if (e->fractol == 4)
		ft_putstr("Mandel 5\n");
	if (e->fractol == 5)
		ft_putstr("Burningship\n");
	if (e->fractol == 6)
		ft_putstr("Julia 3\n");
	if (e->fractol == 7)
		ft_putstr("Julia 5\n");
	if (e->fractol == 8)
		ft_putstr("Tricorn\n");
	if (e->fractol == 9)
		ft_putstr("Tricorn 5\n");
}
