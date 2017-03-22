/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeaun-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 04:01:04 by cmeaun-a          #+#    #+#             */
/*   Updated: 2017/02/15 11:47:09 by cmeaun-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_mouse(int button, int x, int y, t_env *e)
{
	if (button == 1)
	{
		e->px = x;
		e->py = y;
	}
	mlx_destroy_image(e->mlx, e->img);
	e->img = mlx_new_image(e->mlx, e->l, e->h);
	e->data = mlx_get_data_addr(e->img, &e->bpp, &e->sizeline, &e->endian);
	ft_draw(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	return (0);
}

void	ft_key_2(int keycode, t_env *e)
{
	if (keycode == 86 && e->cst1 > 0.5)
		e->cst1 -= 0.05;
	if (keycode == 88 && e->cst1 < 1)
		e->cst1 += 0.05;
	if (keycode == 91 && e->cst2 > 0.5)
		e->cst2 -= 0.05;
	if (keycode == 84 && e->cst2 < 1)
		e->cst2 += 0.05;
}

int		ft_key(int keycode, t_env *e)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 124)
		e->px += 10;
	if (keycode == 126)
		e->py -= 10;
	if (keycode == 123)
		e->px -= 10;
	if (keycode == 125)
		e->py += 10;
	if (keycode == 69)
		e->a *= 1.2;
	if (keycode == 78 && e->a > 1)
		e->a *= 0.8;
	ft_key_2(keycode, e);
	mlx_destroy_image(e->mlx, e->img);
	e->img = mlx_new_image(e->mlx, e->l, e->h);
	e->data = mlx_get_data_addr(e->img, &e->bpp, &e->sizeline, &e->endian);
	ft_draw(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	return (0);
}

void	ft_init(t_env *e)
{
	e->l = 1500;
	e->h = 1200;
	e->px = 500;
	e->py = 500;
	e->a = 20;
	e->cst1 = 0.8;
	e->cst2 = 0.5;
	while ((e->x_max + e->y_max) * e->a > 1500)
		e->a *= 0.8;
}

int		main(int ac, char **av)
{
	t_env	e;

	if (ac != 2)
	{
		ft_putstr_fd("Usage : ./fdf + [map]\n", 2);
		return (0);
	}
	ft_map_size(&e, av[1]);
	if (ft_map(&e, av[1]) == 0)
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	e.mlx = mlx_init();
	ft_init(&e);
	e.win = mlx_new_window(e.mlx, e.l, e.h, "fdf");
	e.img = mlx_new_image(e.mlx, e.l, e.h);
	e.data = mlx_get_data_addr(e.img, &e.bpp, &e.sizeline, &e.endian);
	ft_draw(&e);
	mlx_put_image_to_window(e.mlx, e.win, e.img, 0, 0);
	mlx_key_hook(e.win, ft_key, &e);
	mlx_mouse_hook(e.win, ft_mouse, &e);
	mlx_loop(e.mlx);
	return (0);
}
