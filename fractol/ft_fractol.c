/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeaun-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 15:56:41 by cmeaun-a          #+#    #+#             */
/*   Updated: 2017/03/01 16:38:45 by cmeaun-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_fractol_part1(t_env *e, char *av)
{
	if (ft_strcmp(av, "mandelbrot") == 0)
	{
		ft_init_mandel(e);
		e->fractol = 1;
	}
	if (ft_strcmp(av, "julia") == 0)
	{
		ft_init_julia(e);
		e->fractol = 2;
	}
	if (ft_strcmp(av, "mandel3") == 0)
	{
		ft_init_mandel(e);
		e->fractol = 3;
	}
	if (ft_strcmp(av, "mandel5") == 0)
	{
		ft_init_mandel(e);
		e->fractol = 4;
	}
	if (ft_strcmp(av, "ship") == 0)
	{
		ft_init_mandel(e);
		e->fractol = 5;
	}
}

int		ft_fractol(t_env *e, char *av)
{
	e->fractol = 0;
	ft_fractol_part1(e, av);
	if (ft_strcmp(av, "julia3") == 0)
	{
		ft_init_julia(e);
		e->fractol = 6;
	}
	if (ft_strcmp(av, "julia5") == 0)
	{
		ft_init_julia(e);
		e->fractol = 7;
	}
	if (ft_strcmp(av, "tricorn") == 0)
	{
		ft_init_julia(e);
		e->fractol = 8;
	}
	if (ft_strcmp(av, "tricorn5") == 0)
	{
		ft_init_julia(e);
		e->fractol = 9;
	}
	return (e->fractol);
}
