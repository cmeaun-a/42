/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeaun-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 14:43:27 by cmeaun-a          #+#    #+#             */
/*   Updated: 2017/03/16 23:38:04 by cmeaun-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

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
