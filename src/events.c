/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smouzdah <smouzdah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 16:58:38 by smouzdah          #+#    #+#             */
/*   Updated: 2019/06/30 17:23:59 by smouzdah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		key_press(int key, void *param)
{
	t_env *e;

	e = (t_env *)param;
	key == 123 ? (e->tx = e->tx - 8) : 0;
	key == 124 ? (e->tx = e->tx + 8) : 0;
	key == 125 ? (e->ty = e->ty + 8) : 0;
	key == 126 ? (e->ty = e->ty - 8) : 0;
	key == 69 ? e->scale++ : 0;
	key == 78 ? e->scale-- : 0;
	key == 7 ? (e->draw_mode = 1) : 0;
	key == 11 ? (e->draw_mode = 0) : 0;
	key == 34 ? (e->projec = 1) : 0;
	key == 35 ? (e->projec = 0) : 0;
	if (key == 53)
	{
		mlx_destroy_image(e->mlx.mlx_ptr, e->mlx.img.img_ptr);
		mlx_destroy_window(e->mlx.mlx_ptr, e->mlx.win);
		free_map(e->darr, e->maxh);
		exit(0);
	}
	reset_img(e);
	reload_map(e);
	return (0);
}

int		mouse_press(int key, int x, int y, void *param)
{
	t_env *e;

	e = (t_env *)param;
	x++;
	y++;
	if (key == 4)
		e->scalez++;
	if (key == 5)
		e->scalez--;
	reset_img(e);
	reload_map(e);
	return (0);
}

int		close_win(void *param)
{
	t_env *e;

	e = (t_env *)param;
	mlx_destroy_image(e->mlx.mlx_ptr, e->mlx.img.img_ptr);
	mlx_destroy_window(e->mlx.mlx_ptr, e->mlx.win);
	free_map(e->darr, e->maxh);
	exit(0);
}
