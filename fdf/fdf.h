/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeaun-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 00:01:42 by cmeaun-a          #+#    #+#             */
/*   Updated: 2017/02/14 17:52:24 by cmeaun-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <mlx.h>
# include <math.h>
# include "./libft/libft.h"
# include "./libft/get_next_line.h"

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	int				**map;
	int				x_max;
	int				y_max;
	int				w;
	void			*img;
	char			*data;
	int				bpp;
	int				sizeline;
	int				endian;
	int				color;
	double			cst1;
	double			cst2;
	double			px;
	double			py;
	int				l;
	int				h;
	int				dx;
	int				dy;
	int				xinc;
	int				yinc;
	double			a;
	double			b;
	int				move;
	int				inc_x;
	int				inc_y;
}					t_env;

typedef struct		s_point
{
	double				x;
	double				y;
	double				z;
}					t_point;

void				ft_draw(t_env *e);
void				ft_draw_cercle(t_env **e, t_point pt1, int r, int color);
void				ft_draw_eye(t_env **e, t_point pt1, int r, int color);
int					ft_map(t_env *e, char *av);
void				ft_map_size(t_env *e, char *av);
void				ft_put_pixel_to_image(t_env *e, int x, int y, int color);
void				ft_draw_line(t_env *e, t_point pt1, t_point pt2);
int					ft_map_w(char *av);
int					*ft_strsplit_nbr(char const *s, char c, int *w);

#endif
