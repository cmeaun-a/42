/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeaun-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 14:16:39 by cmeaun-a          #+#    #+#             */
/*   Updated: 2017/03/01 17:37:18 by cmeaun-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_color(t_env *e)
{
	usleep(10000);
	if (e->on_p == 1 && e->p < 2000000)
	{
		e->p += 10500;
		ft_bzero(e->data, L * H * 4);
		ft_draw(e);
		mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	}
	if (e->p > 2000000)
		e->p = 1;
	return (0);
}

int		ft_motion(int x, int y, t_env *e)
{
	if (e->on_j == 1 && x <= L && y <= H && x >= 0 && y >= 0)
	{
		e->c_r = 0.285 + (((double)x) - (L / 2)) / 100;
		e->c_i = 0.01 + (((double)y) - (L / 2)) / 100;
		e->z_r = 0 + (((double)x) - (L / 2)) / 100;
		e->z_i = 0 + (((double)y) - (L / 2)) / 100;
	}
	ft_bzero(e->data, L * H * 4);
	ft_draw(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	return (0);
}

void	ft_mouse_bis(int button, int x, int y, t_env *e)
{
	if (button == 1 && x >= 0 && y >= 0 && y <= H && x <= L)
	{
		e->ecart_x = (e->x2 - e->x1);
		e->ecart_y = (e->y2 - e->y1);
		e->x2 = e->ecart_x - (((double)x / L) * e->ecart_x);
		e->x1 = -(((double)x / L) * e->ecart_x);
		e->y2 = e->ecart_y - (((double)y / H) * e->ecart_y);
		e->y1 = -(((double)y / H) * e->ecart_y);
	}
}

int		ft_mouse(int button, int x, int y, t_env *e)
{
	ft_mouse_bis(button, x, y, e);
	if (button == 4 || button == 6)
	{
		e->zoom *= 1.1;
		e->ecart_x = (e->x2 - e->x1) - (e->x2 - e->x1) / 1.1;
		e->ecart_y = (e->y2 - e->y1) - (e->y2 - e->y1) / 1.1;
		e->x1 += (double)x / L * e->ecart_x;
		e->x2 -= (L - (double)x) / L * e->ecart_x;
		e->y1 += (double)y / H * e->ecart_y;
		e->y2 -= (L - (double)y) / H * e->ecart_y;
	}
	if (button == 5 || button == 7)
	{
		e->zoom /= 1.1;
		e->ecart_x = -(e->x2 - e->x1) + (e->x2 - e->x1) * 1.1;
		e->ecart_y = -(e->y2 - e->y1) + (e->y2 - e->y1) * 1.1;
		e->x1 -= (double)x / L * e->ecart_x;
		e->x2 += (L - (double)x) / L * e->ecart_x;
		e->y1 -= (double)y / H * e->ecart_y;
		e->y2 += (L - (double)y) / H * e->ecart_y;
	}
	ft_bzero(e->data, L * H * 4);
	ft_draw(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	return (0);
}
