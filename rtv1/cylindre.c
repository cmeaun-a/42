/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylindre.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeaun-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 23:39:35 by cmeaun-a          #+#    #+#             */
/*   Updated: 2017/03/28 13:25:06 by cmeaun-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static t_coord		ft_dist_coord(t_coord *c1, t_coord *c2)
{
	t_coord res;

	res.y = c1->y - c2->y;
	res.z = c1->z - c2->z;
	return (res);
}

static float		ft_multi(t_coord *c1, t_coord *c2)
{
	return (c1->y * c2->y + c1->z * c2->z);
}

int					ft_cylindre(t_ray *r, t_cyl *s)
{
	float	delta;
	t_coord	dist;

	s->a = ft_multi(&r->dir, &r->dir);
	dist = ft_dist_coord(&r->eye, &s->pos);
	s->b = 2 * ft_multi(&r->dir, &dist);
	s->c = ft_multi(&dist, &dist) - (s->radius * s->radius);
	delta = s->b * s->b - 4 * s->a * s->c;
	if (delta < 0)
		return (0);
	else
	{
		if (delta == 0)
			s->t = -s->b / 2 * s->a;
		s->t1 = (-s->b + sqrt(delta)) / (2 * s->a);
		s->t2 = (-s->b - sqrt(delta)) / (2 * s->a);
		if (s->t1 < s->t2)
			s->t = s->t1;
		else
			s->t = s->t2;
	}
	return (1);
}
