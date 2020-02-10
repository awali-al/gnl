/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smouzdah <smouzdah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 16:56:06 by smouzdah          #+#    #+#             */
/*   Updated: 2019/06/30 16:57:39 by smouzdah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	draw_xia(t_env *e)
{
	int i;
	int j;

	i = 0;
	while (i < e->maxh)
	{
		j = 0;
		while (j < e->darr[i][0].maxw)
		{
			if (i < e->maxh - 1)
				xiaolin(e->darr[i][j], e->darr[i + 1][j], e);
			if (j + 1 < e->darr[i][0].maxw)
				xiaolin(e->darr[i][j], e->darr[i][j + 1], e);
			j++;
		}
		i++;
	}
}

static void	draw_bres(t_env *e)
{
	int i;
	int j;

	i = 0;
	while (i < e->maxh)
	{
		j = 0;
		while (j < e->darr[i][0].maxw)
		{
			if (i < e->maxh - 1)
				bresenham(e->darr[i][j], e->darr[i + 1][j], e);
			if (j + 1 < e->darr[i][0].maxw)
				bresenham(e->darr[i][j], e->darr[i][j + 1], e);
			j++;
		}
		i++;
	}
}

void		draw(t_env *e)
{
	if (e->draw_mode && e->projec)
		draw_xia(e);
	else
		draw_bres(e);
}
