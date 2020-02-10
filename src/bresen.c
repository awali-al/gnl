/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smouzdah <smouzdah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 19:45:24 by smouzdah          #+#    #+#             */
/*   Updated: 2019/07/01 16:09:04 by smouzdah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	init(t_elem *p0, t_elem *p1, t_env e)
{
	p0->x = p0->x * e.scale;
	p0->y = p0->y * e.scale;
	p0->z = p0->z * e.scalez;
	p1->x = p1->x * e.scale;
	p1->y = p1->y * e.scale;
	p1->z = p1->z * e.scalez;
	if (!e.projec)
	{
		oblique(&p0->x, &p0->y, p0->z);
		oblique(&p1->x, &p1->y, p1->z);
	}
	else
	{
		iso(&p0->x, &p0->y, p0->z);
		iso(&p1->x, &p1->y, p1->z);
	}
}

void		bresenham(t_elem p0, t_elem p1, t_env *e)
{
	int dx;
	int dy;
	int err;
	int err_mem;

	init(&p0, &p1, *e);
	dx = abs(p1.x - p0.x);
	dy = abs(p1.y - p0.y);
	err = (dx > dy ? dx : -dy) / 2;
	while (p0.x != p1.x || p0.y != p1.y)
	{
		e->mlx.img.data[pixel(p0.x, p0.y, e)] =
		(p1.color == 0x47CACC ? p0.color : p1.color);
		err_mem = err;
		if (err_mem > -dx)
		{
			err = err - dy;
			p0.x += p0.x < p1.x ? 1 : -1;
		}
		if (err_mem < dy)
		{
			err = err + dx;
			p0.y += p0.y < p1.y ? 1 : -1;
		}
	}
}
