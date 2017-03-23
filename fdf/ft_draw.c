/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeaun-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 01:33:02 by cmeaun-a          #+#    #+#             */
/*   Updated: 2017/02/13 16:38:05 by cmeaun-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_put_pixel_to_image(t_env *e, int x, int y, int color)
{
	int		i;

	if (x < 0 || x >= e->l || y < 0 || y >= e->h)
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

void	ft_color_i(t_env *e, int i, int j)
{
	e->color = 0xFF0000;
	if (e->map[j][i] + e->map[j][i + 1] > 0 && i < e->x_max)
		e->color = 0xFF6600;
	if (e->map[j][i] + e->map[j][i + 1] >= 4 && i < e->x_max)
		e->color = 0xFFCC33;
	if (e->map[j][i] + e->map[j][i + 1] >= 8 && i < e->x_max)
		e->color = 0x33CC33;
	if (e->map[j][i] + e->map[j][i + 1] >= 12 && i < e->x_max)
		e->color = 0x3300CC;
	if (e->map[j][i] + e->map[j][i + 1] >= 16 && i < e->x_max)
		e->color = 0x660066;
	if (e->map[j][i] + e->map[j][i + 1] >= 20 && i < e->x_max)
		e->color = 0xFF0000;
	if (e->map[j][i] + e->map[j][i + 1] >= 24 && i < e->x_max)
		e->color = 0xFF6600;
	if (e->map[j][i] + e->map[j][i + 1] >= 28 && i < e->x_max)
		e->color = 0xFFCC33;
	if (e->map[j][i] + e->map[j][i + 1] >= 40 && i < e->x_max)
		e->color = 0x33CC33;
	if (e->map[j][i] + e->map[j][i + 1] >= 80 && i < e->x_max)
		e->color = 0x3300CC;
	if (e->map[j][i] + e->map[j][i + 1] >= 160 && i < e->x_max)
		e->color = 0x660066;
}

void	ft_color_j(t_env *e, int i, int j)
{
	e->color = 0xFF0000;
	if (e->map[j][i] + e->map[j + 1][i] > 0 && j < e->y_max)
		e->color = 0xFF6600;
	if (e->map[j][i] + e->map[j + 1][i] >= 4 && j < e->y_max)
		e->color = 0xFFCC33;
	if (e->map[j][i] + e->map[j + 1][i] >= 8 && j < e->y_max)
		e->color = 0x33CC33;
	if (e->map[j][i] + e->map[j + 1][i] >= 12 && j < e->y_max)
		e->color = 0x3300CC;
	if (e->map[j][i] + e->map[j + 1][i] >= 16 && j < e->y_max)
		e->color = 0x660066;
	if (e->map[j][i] + e->map[j + 1][i] >= 20 && j < e->y_max)
		e->color = 0xFF0000;
	if (e->map[j][i] + e->map[j + 1][i] >= 24 && j < e->y_max)
		e->color = 0xFF6600;
	if (e->map[j][i] + e->map[j + 1][i] >= 28 && j < e->y_max)
		e->color = 0xFFCC33;
	if (e->map[j][i] + e->map[j + 1][i] >= 40 && j < e->y_max)
		e->color = 0x33CC33;
	if (e->map[j][i] + e->map[j + 1][i] >= 80 && j < e->y_max)
		e->color = 0x3300CC;
	if (e->map[j][i] + e->map[j + 1][i] >= 160 && j < e->y_max)
		e->color = 0x660066;
}

void	ft_proj_para(t_env *e, int i, int j)
{
	t_point		pt1;
	t_point		pt2;

	e->b = -e->a / 4;
	pt1.x = e->px + e->cst1 * ((i * e->a) - e->cst2 * (j * e->a));
	pt1.y = e->py + e->map[j][i] * e->b + (e->cst1 / 2) * i * e->a +
		(e->cst2 / 2) * j * e->a;
	if ((i + 1) != e->x_max)
	{
		pt2.x = e->px + e->cst1 * (((i + 1) * e->a) - e->cst2 * (j * e->a));
		pt2.y = e->py + e->map[j][i + 1] * e->b + (e->cst1 / 2) * (i + 1) * e->a
			+ (e->cst2 / 2) * j * e->a;
		ft_color_i(e, i, j);
		ft_draw_line(e, pt1, pt2);
	}
	if ((j + 1) != e->y_max)
	{
		pt2.x = e->px + e->cst1 * (((i) * e->a) - e->cst2 * ((j + 1) * e->a));
		pt2.y = e->py + e->map[j + 1][i] * e->b + (e->cst1 / 2) * (i) * e->a
			+ (e->cst2 / 2) * (1 + j) * e->a;
		ft_color_j(e, i, j);
		ft_draw_line(e, pt1, pt2);
	}
}

void	ft_draw(t_env *e)
{
	int i;
	int j;

	j = 0;
	while (j < e->y_max)
	{
		i = 0;
		while (i < e->x_max)
		{
			ft_proj_para(e, i, j);
			i++;
		}
		j++;
	}
}
