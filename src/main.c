/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smouzdah <smouzdah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 20:23:51 by aminewalial       #+#    #+#             */
/*   Updated: 2019/07/01 16:06:27 by smouzdah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	free_map(t_elem **map, int h)
{
	int		i;

	i = 0;
	while (i < h)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int		main(int ac, char **av)
{
	t_env	e;

	if (ac != 2 && ac != 4)
		usage();
	e.darr = dar_fil(av[1], &e.maxh);
	e.scale = (e.maxh >= 40 ? 1 : 30);
	e.scale = (ac == 4 ? ft_atoi(av[2]) : e.scale);
	e.scalez = (ac == 4 ? ft_atoi(av[3]) : 2);
	e.tx = 0;
	e.ty = 0;
	e.draw_mode = 0;
	e.projec = 1;
	e.mlx.mlx_ptr = mlx_init();
	e.mlx.win = mlx_new_window(e.mlx.mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "FDF");
	e.mlx.img.img_ptr = mlx_new_image(e.mlx.mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	e.mlx.img.data = (int *)mlx_get_data_addr(e.mlx.img.img_ptr,
	&e.mlx.img.bpp, &e.mlx.img.size_l, &e.mlx.img.endian);
	setwindow(&e.mlx);
	draw(&e);
	setmenu(&e.mlx);
	mlx_hook(e.mlx.win, 2, 0, key_press, (void *)&e);
	mlx_hook(e.mlx.win, 4, 0, mouse_press, (void *)&e);
	mlx_hook(e.mlx.win, 17, 0, close_win, (void *)&e);
	mlx_loop(e.mlx.mlx_ptr);
	return (0);
}
