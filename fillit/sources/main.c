/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcentaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 08:31:59 by jcentaur          #+#    #+#             */
/*   Updated: 2016/12/06 09:39:18 by cmeaun-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int ac, char **av)
{
	char		buf[BUF_SIZE];
	char		*tmp;
	int			fd;
	t_tetri		*tetri;

	if (ac != 2)
	{
		ft_putendl_fd("usage: ./fillit file", 1);
		return (0);
	}
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (0);
	read(fd, buf, BUF_SIZE);
	tmp = ft_strtmp(buf);
	if (ft_check(buf) == 0 || ft_ch_cn(tmp) == 0 || (ft_strlen(tmp) / 16) > 26)
	{
		ft_putendl_fd("error", 1);
		return (0);
	}
	tetri = ft_chartocoord(tmp);
	ft_map(tetri, 2);
	if (close(fd) == -1)
		return (1);
	return (0);
}
