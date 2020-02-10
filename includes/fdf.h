/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smouzdah <smouzdah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 20:56:51 by aminewalial       #+#    #+#             */
/*   Updated: 2019/07/01 16:12:28 by smouzdah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include "../minilibx_macos/mlx.h"
# include <fcntl.h>
# include <math.h>

# define WIN_WIDTH 1920
# define WIN_HEIGHT 1080

typedef struct		s_img
{
	void			*img_ptr;
	int				*data;
	int				size_l;
	int				bpp;
	int				endian;
}					t_img;

typedef struct		s_mlx
{
	void			*mlx_ptr;
	void			*win;
	t_img			img;
}					t_mlx;

typedef struct		s_elem
{
	int				x;
	int				y;
	int				z;
	int				maxw;
	int				color;
}					t_elem;

typedef struct		s_lls
{
	t_elem			*sarr;
	struct s_lls	*next;
}					t_lls;

typedef struct		s_file
{
	char			*line;
	int				fd;
}					t_file;

typedef struct		s_env
{
	t_elem			**darr;
	t_mlx			mlx;
	int				scale;
	int				scalez;
	int				tx;
	int				ty;
	int				maxh;
	int				draw_mode;
	int				projec;
}					t_env;

int					white(char c);
int					whitelen(char *str);
char				*ft_strndup(const char *s1, size_t n);
char				**split_whitespaces(char *str);
void				usage(void);
void				no_file(char *av);
void				length_error(void);
void				free_list(t_lls *head);
int					color_ver(char *str);
void				color_error(t_lls *head);
t_elem				**dar_fil(char *av, int *maxh);
int					hextodec(char *str);
int					is_hex(char c);
int					ft_pow(int n, int p);
void				setwindow(t_mlx *mlx);
void				setmenu(t_mlx *mlx);
void				reset_img(t_env *e);
void				reload_map(t_env *e);
void				xiaolin(t_elem p0, t_elem p1, t_env *e);
void				bresenham(t_elem p0, t_elem p1, t_env *e);
void				draw(t_env *e);
int					int_num(float x);
float				frac_of_num(float x);
float				one_frac_of_num(float x);
void				swap(int *x1, int *y1, int *x2, int *y2);
int					pixel(int x, int y, t_env *e);
void				iso(int *x, int *y, int z);
void				oblique(int *x, int *y, int z);
void				free_map(t_elem **map, int h);
int					key_press(int key, void *param);
int					mouse_press(int key, int x, int y, void *param);
int					close_win(void *param);

#endif
