/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeaun-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 13:55:40 by cmeaun-a          #+#    #+#             */
/*   Updated: 2017/02/15 11:57:24 by cmeaun-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_map_size(t_env *e, char *av)
{
	int		fd;
	char	*line;
	int		i;
	int		ret;

	i = 0;
	if ((fd = open(av, O_RDONLY)) < 0)
		return ;
	while ((ret = get_next_line(fd, &line)) == 1)
	{
		i++;
		free(line);
	}
	if (ret == -1)
		return ;
	e->y_max = i;
	close(fd);
}

int			ft_map_w(char *av)
{
	int		fd;
	int		i;
	int		nb;
	char	*line;

	if ((fd = open(av, O_RDONLY)) < 0)
		return (0);
	get_next_line(fd, &line);
	i = 0;
	nb = 0;
	if (line[0] != ' ' && line[0])
	{
		i++;
		nb++;
	}
	while (line[i])
	{
		if ((line[i] == ' ' || !line[i]) && (line[i + 1] != ' ' && line[i + 1]))
			nb++;
		i++;
	}
	free(line);
	return (nb);
}

int			ft_map(t_env *e, char *av)
{
	char	*line;
	int		i;
	int		fd;
	int		w;

	if ((w = ft_map_w(av)) == 0)
		return (0);
	i = 0;
	if ((fd = open(av, O_RDONLY)) < 0)
		return (0);
	if (!(e->map = (int**)malloc(sizeof(*e->map) * e->y_max)))
		return (0);
	while (get_next_line(fd, &line) == 1)
	{
		e->map[i] = ft_strsplit_nbr(line, ' ', &e->x_max);
		if (e->x_max != w)
			return (0);
		i++;
		free(line);
	}
	if (get_next_line(fd, &line) == -1)
		return (0);
	close(fd);
	return (1);
}
