/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeaun-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 14:00:24 by cmeaun-a          #+#    #+#             */
/*   Updated: 2017/03/01 19:07:15 by cmeaun-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

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
# define H 500
# define L 500

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*data;
	int				bpp;
	int				sizeline;
	int				endian;
	int				color;
	int				xi;
	int				yi;
	int				p;
	int				fractol;
	double			x1;
	double			x2;
	double			y1;
	double			y2;
	double			image_x;
	double			image_y;
	double			iteration_max;
	double			zoom;
	int				i;
	double			c_r;
	double			c_i;
	double			z_r;
	double			z_i;
	double			tmp;
	double			ecart_x;
	double			ecart_y;
	char			on_p;
	char			on_j;
	char			*name;
}					t_env;

int					ft_mouse(int button, int x, int y, t_env *e);
int					ft_key(int keycode, t_env *e);
void				ft_put_pixel_to_image(t_env *e, int x, int y, int color);
void				ft_mandelbrot(t_env *e);
void				ft_julia(t_env *e);
void				ft_mandel_3(t_env *e);
void				ft_mandel_5(t_env *e);
int					ft_color(t_env *e);
void				ft_draw(t_env *e);
int					ft_motion(int x, int y, t_env *e);
void				ft_burningship(t_env *e);
void				ft_init_newton(t_env *e);
void				ft_init_julia(t_env *e);
void				ft_init_mamdel(t_env *e);
int					ft_fractol(t_env *e, char *av);
void				ft_mlx(t_env *e, char *av);
void				ft_init_julia(t_env *e);
void				ft_init_mandel(t_env *e);
void				ft_list_touch(void);
void				ft_julia_3(t_env *e);
void				ft_julia_5(t_env *e);
void				ft_tricorn(t_env *e);
void				ft_tricorn5(t_env *e);
int					ft_color(t_env *e);
int					ft_motion(int x, int y, t_env *e);
int					ft_mouse(int button, int x, int y, t_env *e);
void				ft_list_fractal(t_env *e);

#endif
