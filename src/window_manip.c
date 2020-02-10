/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_manip.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smouzdah <smouzdah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 17:01:44 by smouzdah          #+#    #+#             */
/*   Updated: 2019/07/01 16:10:48 by smouzdah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		setwindow(t_mlx *mlx)
{
	int x;
	int y;

	y = 1080;
	while (--y >= 0)
	{
		x = 1920;
		while (--x >= 0)
			mlx->img.data[y * WIN_WIDTH + x] = 0x0B0500;
	}
}

void		setmenu(t_mlx *mlx)
{
	int x;
	int y;

	y = 1080;
	while (--y >= 0)
	{
		x = 400;
		while (--x >= 0)
			mlx->img.data[y * WIN_WIDTH + x] = 0x1C0118;
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win, mlx->img.img_ptr, 0, 0);
	mlx_string_put(mlx->mlx_ptr, mlx->win, 10, 10, 0xFFFFFF, "MENU :");
	mlx_string_put(mlx->mlx_ptr, mlx->win, 15, 30, 0xFFFFFF,
	">Arrow keys: Move the map");
	mlx_string_put(mlx->mlx_ptr, mlx->win, 15, 50, 0xFFFFFF, "> + / - : Zoom");
	mlx_string_put(mlx->mlx_ptr, mlx->win, 15, 70, 0xFFFFFF,
	">Mouse scroll : Change Z");
	mlx_string_put(mlx->mlx_ptr, mlx->win, 15, 90, 0xFFFFFF, "> I: Isometric");
	mlx_string_put(mlx->mlx_ptr, mlx->win, 15, 110, 0xFFFFFF, "> P: Parallel");
	mlx_string_put(mlx->mlx_ptr, mlx->win, 15, 130, 0xFFFFFF,
	"> X: Xiaolin AA");
	mlx_string_put(mlx->mlx_ptr, mlx->win, 15, 150, 0xFFFFFF, "> B: Bresenham");
	mlx_string_put(mlx->mlx_ptr, mlx->win, 15, 190, 0xFFFFFF, "> ESC: Quit");
	mlx_string_put(mlx->mlx_ptr, mlx->win, 15, 850, 0xFFFFFF,
	"Made by : CouscousAgha And GoatBeard");
}

void		reset_img(t_env *e)
{
	mlx_destroy_image(e->mlx.mlx_ptr, e->mlx.img.img_ptr);
	e->mlx.img.img_ptr = mlx_new_image(e->mlx.mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	e->mlx.img.data = (int *)mlx_get_data_addr(e->mlx.img.img_ptr,
	&e->mlx.img.bpp, &e->mlx.img.size_l, &e->mlx.img.endian);
}

void		reload_map(t_env *e)
{
	setwindow(&e->mlx);
	draw(e);
	setmenu(&e->mlx);
}
