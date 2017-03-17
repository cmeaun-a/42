/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeaun-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 16:06:06 by cmeaun-a          #+#    #+#             */
/*   Updated: 2017/03/16 23:42:05 by cmeaun-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	ft_init_mlx(t_env *e)
{
	if (!(e->mlx = mlx_init()))
			return ;
	if (!(e->win = mlx_new_window(e->mlx, L, H, "rtv1")))
			return ;
	if (!(e->img = mlx_new_image(e->mlx, L, H)))
		return ;
	if (!(e->data = mlx_get_data_addr(e->img, &e->bpp, &e->sizeline,
					&e->endian)))
		return ;
}

