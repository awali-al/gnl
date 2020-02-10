/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awali-al <awali-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 21:12:54 by aminewalial       #+#    #+#             */
/*   Updated: 2019/06/20 16:26:33 by awali-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	usage(void)
{
	ft_putstr("Usage : ./fdf <filename> [ case_size z_size ]\n");
	exit(0);
}

void	no_file(char *av)
{
	ft_putstr("No file ");
	ft_putstr(av);
	ft_putstr("\n");
	exit(0);
}

void	length_error(void)
{
	ft_putstr("Found wrong line length. Exiting.\n");
	exit(0);
}

void	color_error(t_lls *head)
{
	free_list(head);
	ft_putstr("Found wrong color code. Exiting.\n");
	exit(0);
}
