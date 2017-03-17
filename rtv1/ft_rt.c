/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rt.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeaun-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 04:03:47 by cmeaun-a          #+#    #+#             */
/*   Updated: 2017/03/17 05:55:14 by cmeaun-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_coord		ft_distance(t_coord *c1, t_coord *c2)
{
	t_coord res;

	res.x = c1->x - c2->x;
	res.y = c1->y - c2->y;
	res.z = c1->z - c2->z;
	return (res);
}

float		ft_multi(t_coord *c1, t_coord *c2)
{
	return (c1->x * c2->x + c1->y * c2->y + c1->z * c2->z);
}

int			ft_discriminant(t_ray *r, t_sphere *s)
{
	float	a;
	float	b;
	float	c;
	float	discr;
	t_coord	dist;

	a = ft_multi(&r->dir, &r->dir);
	dist = ft_distance(&r->start, &s->pos);
	b = 2 * ft_multi(&r->dir, &dist);
	c = ft_multi(&dist, &dist) - (s->radius * s->radius);
	discr = b * b - 4 * a * c;
	if (discr < 0)
		return (0);
	else
		return (1);
}

void		ft_rt(t_env *e)
{
	int x;
	int y;
	t_sphere s;
	t_ray r;

	s.pos.x = L / 2;
	s.pos.y = H / 2;
	s.pos.z = 100;
	s.radius = 100;

	r.dir.x = 0;
	r.dir.y = 0;
	r.dir.z = 1;
	r.start.z = 0;
	y = 0;
	while (y < H)
	{
		r.start.y = y;
		x = 0;
		while (x < L)
		{
			r.start.x = x;
			if (ft_discriminant(&r, &s))
				ft_put_pixel_to_image(e, x, y, 0x7F0000);
			else
				ft_put_pixel_to_image(e, x, y, 0x000000);
			x++;
		}
		y++;
	}
}
