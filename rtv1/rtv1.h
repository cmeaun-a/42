/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeaun-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 02:57:29 by cmeaun-a          #+#    #+#             */
/*   Updated: 2017/03/17 05:34:11 by cmeaun-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <mlx.h>
# include <math.h>
# include "./libft/libft.h"
# include "./libft/get_next_line.h"

# define KEYPRESSMASK		(1L<<0)
# define KEYPRESS			2
# define BUTTONPRESSMASK	(1L<<2)
# define BUTTONPRESS		4
# define POINTERMOTIONMASK	(1L<<6)
# define MOTIONNOTIFY		6
# define LEAVEWINMASK		(1L<<5)
# define DESTROYNOTIFY		17
# define H 480
# define L 640

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*data;
	int				bpp;
	int				sizeline;
	int				endian;
}					t_env;

typedef struct		s_coord
{
	float			x;
	float			y;
	float			z;
}					t_coord;

typedef struct		s_ray
{
	t_coord			start;
	t_coord			dir;
}					t_ray;

typedef struct		s_sphere
{
	t_coord			pos;
	float			radius;
}					t_sphere;

void				ft_init_mlx(t_env *e);
void				ft_put_pixel_to_image(t_env *e, int x, int y, int color);
int					ft_key(int keycode, t_env *e);
int					ft_win(t_env *e);
int					ft_expose(t_env *e);
void				ft_rt(t_env *e);

#endif
