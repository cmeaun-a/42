/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_touch.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeaun-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 16:59:13 by cmeaun-a          #+#    #+#             */
/*   Updated: 2017/03/01 19:03:24 by cmeaun-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_list_touch(void)
{
	ft_putstr("Commande :\n");
	ft_putstr("- Variation parametres julia\t: ESP + souris\n");
	ft_putstr("- Deplacement\t\t\t: Fleches ou Clic souris\n- Zoom\t\t\t\t");
	ft_putstr(": Molette vers");
	ft_putstr("bas/gauche\n- Dezoom\t\t\t: Molette vers haut/droite\n");
	ft_putstr("- Couleur\t\t\t: P ou O\n- Iteration\t\t\t: I(+) ou U(-)\n");
	ft_putstr("- Changement de fractale\t: Y\n");
	ft_putstr("- Reset\t\t\t\t: R\n");
}
