/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeaun-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 13:56:08 by cmeaun-a          #+#    #+#             */
/*   Updated: 2017/03/02 15:02:10 by cmeaun-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_error(void)
{
	ft_putstr("Usage : ./fractol + fractal_type (2 max)\n");
	ft_putstr("- mandelbrot\n- mandel3\n- mandel5\n- julia\n");
	ft_putstr("- julia3\n- julia5\n- tricorn\n- tricorn5\n- ship\n");
}

void	ft_mlx(t_env *e, char *av)
{
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, L, H, av);
	e->img = mlx_new_image(e->mlx, L, H);
	e->data = mlx_get_data_addr(e->img, &e->bpp, &e->sizeline, &e->endian);
	ft_draw(e);
	mlx_hook(e->win, KEYPRESS, KEYPRESSMASK, ft_key, e);
	mlx_hook(e->win, BUTTONPRESS, BUTTONPRESSMASK, ft_mouse, e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	mlx_loop(e->mlx);
}

void	ft_mlx_2(t_env *e, char *av)
{
	e->win = mlx_new_window(e->mlx, L, H, av);
	e->img = mlx_new_image(e->mlx, L, H);
	e->data = mlx_get_data_addr(e->img, &e->bpp, &e->sizeline, &e->endian);
	ft_draw(e);
	mlx_hook(e->win, KEYPRESS, KEYPRESSMASK, ft_key, e);
	mlx_hook(e->win, BUTTONPRESS, BUTTONPRESSMASK, ft_mouse, e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
}

int		main(int ac, char **av)
{
	t_env	e;
	t_env	f;

	if (ac == 2 && ft_fractol(&e, av[1]) != 0)
		ft_mlx(&e, av[1]);
	else if (ac == 3)
	{
		if (ft_fractol(&e, av[1]) == 0 || ft_fractol(&e, av[2]) == 0)
			ft_error();
		if (ft_fractol(&e, av[1]) == 0 && ft_fractol(&e, av[2]) == 0)
			return (0);
		e.mlx = mlx_init();
		if (ft_fractol(&e, av[1]) != 0)
			ft_mlx_2(&e, av[1]);
		if (ft_fractol(&f, av[2]) != 0)
		{
			f.mlx = e.mlx;
			ft_mlx_2(&f, av[2]);
		}
		mlx_loop(e.mlx);
	}
	else
		ft_error();
	return (0);
}
