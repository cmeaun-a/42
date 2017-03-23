/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeaun-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 16:06:06 by cmeaun-a          #+#    #+#             */
/*   Updated: 2017/03/02 16:53:58 by cmeaun-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_init_julia(t_env *e)
{
	e->x1 = -2;
	e->x2 = 2;
	e->y1 = -2;
	e->y2 = 2;
	e->zoom = L / (e->x2 - e->x1);
	e->iteration_max = 50;
	e->xi = 0;
	e->yi = 0;
	e->p = 1;
	e->i = 0;
	e->image_x = (e->x2 - e->x1) * e->zoom;
	e->image_y = (e->y2 - e->y1) * e->zoom;
	e->c_r = 0.285;
	e->c_i = 0.01;
}

void	ft_init_mandel(t_env *e)
{
	e->x1 = -2;
	e->x2 = 2;
	e->y1 = -2;
	e->y2 = 2;
	e->zoom = L / (e->x2 - e->x1);
	e->iteration_max = 50;
	e->xi = 0;
	e->yi = 0;
	e->p = 1;
	e->i = 1;
	e->image_x = (e->x2 - e->x1) * e->zoom;
	e->image_y = (e->y2 - e->y1) * e->zoom;
}
