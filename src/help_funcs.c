/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smouzdah <smouzdah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 16:16:57 by smouzdah          #+#    #+#             */
/*   Updated: 2019/07/01 16:09:15 by smouzdah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		int_num(float x)
{
	return ((int)x);
}

float	frac_of_num(float x)
{
	return (x - int_num(x));
}

float	one_frac_of_num(float x)
{
	return (1 - frac_of_num(x));
}

void	swap(int *x1, int *y1, int *x2, int *y2)
{
	int help;

	help = *x1;
	*x1 = *y1;
	*y1 = help;
	help = *x2;
	*x2 = *y2;
	*y2 = help;
}

int		pixel(int x, int y, t_env *e)
{
	int ret_val;

	x = x + e->tx;
	y = y + e->ty;
	if (y < -300 || y >= 780 || x < -1000 || x >= 920)
		return (0);
	ret_val = WIN_WIDTH * (y + 300) + x + 1000;
	return (ret_val);
}
