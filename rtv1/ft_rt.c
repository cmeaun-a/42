/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rt.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeaun-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 04:03:47 by cmeaun-a          #+#    #+#             */
/*   Updated: 2017/04/21 03:33:51 by cmeaun-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void	ft_init_scene(t_ray *r)
{
	r->dir.x = 0;
	r->dir.y = 0;
	r->dir.z = 1;
	r->eye.z = 0;
}

void		ft_scene(t_sdl *sdl, t_scene *scene)
{
	int			x;
	int			y;
	t_ray		r;

	ft_init_scene(&r);
	while ((scene)->obj)
	{
	y = 0;
	while (y < H)
	{
		r.eye.y = y;
		x = 0;
		while (x < L)
		{
			r.eye.x = x;
			if (ft_sphere(&r, ((t_sphere *)((scene)->obj->data))))
			{
				sdl->pixels[y * L + x] = ((t_sphere *)((scene)->obj->data))->color;
			}
//			if (ft_cone(&r, &co))
//			{
//				ft_put_pixel_to_image(e, x, y, rgb(250 * (1 - s.t / s.radius),
//					150 * (1 - s.t / s.radius), 150 * (1 - s.t / s.radius)));
//				printf("x = %d,\t y = %d,\t s.t = %.2f\n", x, y, co.t);
//			}
//			if (ft_cylindre(&r, &c))
//				ft_put_pixel_to_image(e, x, y, rgb(150 * (1 - c.t / c.radius),
//					150 * (1 - c.t / c.radius), 150 * (1 - c.t / c.radius)));
			else
				sdl->pixels[y * L + x] = 0x000000;
			x++;
		}
		y++;
	}
	(scene)->obj = (scene)->obj->next;
	}
}
