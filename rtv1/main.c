/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeaun-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 13:56:08 by cmeaun-a          #+#    #+#             */
/*   Updated: 2017/03/17 05:34:16 by cmeaun-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"


int		main()
{
	t_env	e;

	ft_init_mlx(&e);
	ft_rt(&e);
	mlx_hook(e.win, KEYPRESS, KEYPRESSMASK, ft_key, &e);
	mlx_hook(e.win, DESTROYNOTIFY, LEAVEWINMASK, ft_win, &e);
	mlx_put_image_to_window(e.mlx, e.win, e.img, 0, 0);
	mlx_loop(e.mlx);
	return (0);
}
