/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeaun-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 16:15:23 by cmeaun-a          #+#    #+#             */
/*   Updated: 2016/12/06 11:16:29 by cmeaun-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include "libft.h"
# define BUF_SIZE 4096

typedef struct		s_coord
{
	int				x;
	int				y;
}					t_coord;

typedef struct		s_tetri
{
	t_coord			pts[3];
	struct s_tetri	*next;
}					t_tetri;

typedef struct		s_check
{
	int				pts;
	int				dz;
	int				rt;
	int				connects;
}					t_check;

int					ft_check(char *tetri);
char				*ft_strtmp(char *tetri);
t_list				*ft_block(char *s);
int					ft_ch_cn(char *tetri);
t_coord				ft_initcoord(int x, int y);
t_tetri				*ft_chartocoord(char *tetri);
void				ft_map(t_tetri *tetri, int size);
int					ft_isvalide(char **map, t_tetri *tetri, int size,
						char alpha);
int					ft_point(char **map, t_tetri *tetri, t_coord pos);
void				ft_replace(char **map, t_tetri *tetri, t_coord pos,
						char alpha);
int					ft_isvalide_2(char **map, t_tetri *tetri, int size,
						char alpha);
void				ft_limit_x(t_tetri *tetri, t_coord *pos, int size);

#endif
