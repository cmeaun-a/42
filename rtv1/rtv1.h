/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeaun-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 02:57:29 by cmeaun-a          #+#    #+#             */
/*   Updated: 2017/04/21 03:34:06 by cmeaun-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H


# include <stdio.h>

# include <SDL2/SDL.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <mlx.h>
# include <math.h>
# include "./libft/libft.h"
# include "./libft/get_next_line.h"

# define H 480
# define L 640
# define SPHERE 1
# define CONE 2
# define CYL 3
# define PLANE 4

typedef struct		s_sdl
{
	SDL_Window		*win;
	SDL_Event		event;
	SDL_Renderer	*renderer;
	SDL_Texture		*texture;
	Uint32			*pixels;
}					t_sdl;

typedef struct		s_coord
{
	float			x;
	float			y;
	float			z;
}					t_coord;

typedef struct		s_ray
{
	t_coord			eye;
	t_coord			dir;
	float			t;
}					t_ray;

typedef struct		s_sphere
{
	t_coord			pos;
	float			radius;
	float			a;
	float			b;
	float			c;
	float			t1;
	float			t2;
	float			t;
	Uint32			color;

}					t_sphere;

typedef struct		s_cyl
{
	t_coord			pos;
	float			radius;
	float			a;
	float			b;
	float			c;
	float			t1;
	float			t2;
	float			t;
}					t_cyl;

typedef struct		s_cone
{
	t_coord			pos;
	float			radius;
	float			a;
	float			b;
	float			c;
	float			t1;
	float			t2;
	float			t;
}					t_cone;

typedef struct		s_plane
{
	t_coord			pos;
}					t_plane;

typedef struct		s_cam
{
	t_coord			origin;
}					t_cam;

typedef struct		s_li
{
	int				name;
	void			*data;
	struct s_li		*next;
}					t_li;

typedef struct		s_scene
{
	t_cam			cam;
	t_li			*obj;
}					t_scene;

Uint32				rgb(int r, int g, int b);
int					ft_sphere(t_ray *r, t_sphere *s);
int					ft_cylindre(t_ray *r, t_cyl *c);
int					ft_cone(t_ray *r, t_cone *co);
void				ft_scene(t_sdl *sdl, t_scene *scene);
int					ft_sphere(t_ray *r, t_sphere *s);
void				ft_get_scene(t_scene *scene, char *av);

#endif
