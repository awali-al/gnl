/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xiaolin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smouzdah <smouzdah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 18:20:03 by smouzdah          #+#    #+#             */
/*   Updated: 2019/07/01 16:11:03 by smouzdah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int		col(float val, int mode, t_elem p1, t_elem p0)
{
	int		red;
	int		blue;
	int		green;

	if (val < 0.0)
	{
		mode = (mode == 0 ? 1 : 0);
		val = -val;
	}
	if (p1.color == 0xFA9284)
		p1.color = p0.color;
	red = p1.color >> 16 & 0xFF;
	green = p1.color >> 8 & 0xFF;
	blue = p1.color & 0xFF;
	if (mode)
		return ((int)(frac_of_num(val) * blue))
		| ((int)(frac_of_num(val) * green) << 8)
		| ((int)(frac_of_num(val) * red) << 16);
	return ((int)(one_frac_of_num(val) * blue))
	| ((int)(one_frac_of_num(val) * green) << 8)
	| ((int)(one_frac_of_num(val) * red) << 16);
}

static float	init(t_elem *p0, t_elem *p1, t_env e)
{
	int ret_val;

	p0->x = p0->x * e.scale;
	p0->y = p0->y * e.scale;
	p0->z = p0->z * e.scalez;
	p1->x = p1->x * e.scale;
	p1->y = p1->y * e.scale;
	p1->z = p1->z * e.scalez;
	iso(&p0->x, &p0->y, p0->z);
	iso(&p1->x, &p1->y, p1->z);
	ret_val = abs(p1->y - p0->y) > abs(p1->x - p0->x) ? 1 : 0;
	if (ret_val)
		swap(&p0->x, &p0->y, &p1->x, &p1->y);
	if (p0->x > p1->x)
		swap(&p0->x, &p1->x, &p0->y, &p1->y);
	return (ret_val);
}

void			xiaolin(t_elem p0, t_elem p1, t_env *e)
{
	int		steep;
	float	gradient;
	float	iny;

	steep = init(&p0, &p1, *e);
	iny = (float)p0.y;
	gradient = (p1.x == p0.x ? 1 : (float)(p1.y - p0.y) / (float)(p1.x - p0.x));
	if (steep)
		while (p0.x <= p1.x)
		{
			e->mlx.img.data[pixel(int_num(iny - 1), p0.x, e)] =
			col(iny, 0, p0, p1);
			e->mlx.img.data[pixel(int_num(iny), p0.x++, e)] =
			col(iny, 1, p0, p1);
			iny = iny + gradient;
		}
	else
		while (p0.x <= p1.x)
		{
			e->mlx.img.data[pixel(p0.x, int_num(iny - 1), e)] =
			col(iny, 0, p0, p1);
			e->mlx.img.data[pixel(p0.x++, int_num(iny), e)] =
			col(iny, 1, p0, p1);
			iny = iny + gradient;
		}
}
