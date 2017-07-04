/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmalkevy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 14:14:16 by rmalkevy          #+#    #+#             */
/*   Updated: 2017/03/04 14:14:19 by rmalkevy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_LIBFDF_H
# define FDF_LIBFDF_H
# include "libft/libft.h"
# include <math.h>
# include "minilibx/mlx.h"

# define CY		600
# define CX		1000
# define WX		2000
# define HY		1200

# define BUFF	100000
# define LINE	WX * 4
# define MAX	HY * LINE

# define ZZOOM	10

typedef struct	s_img
{
	void		*mlx;
	void		*win;
	int			zoom;
	int			zzoom;
	int			rile;
	int			updo;
	double		angl_x;
	double		angl_y;
	double		angl_z;
	void		*image;
	char		*line;
}				t_img;

typedef struct	s_sincos
{
	double		cy_cz;
	double		cy_sz;
	double		sy;
	double		sx_sy_cz;
	double		cx_sz;
	double		sx_sy_sz;
	double		cx_cz;
	double		sx_cy;
	double		sum1;
	double		sum2;
}				t_sincos;

typedef struct	s_shape
{
	int			y_len;
	int			x_len;
	int			y;
	int			x;
	int			z;
	int			rx;
	int			ry;
	int			rz;
	long		color;
	int			red;
	int			green;
	int			blue;
	t_img		*img;
	t_sincos	*a;
}				t_mod;

typedef struct	s_str
{
	char		**line;
	int			y_len;
	int			x_len;
}				t_str;

long			ft_atoi_base(char *str, unsigned int base);
int				ft_read_map(char **argv, char **map);
t_str			*create_str(char **map, int len);
t_mod			*fill_mod(t_str *str);
void			write_to_image(t_mod *mod, t_img *img);
int				my_key_funct(int keycode, t_mod *mod);
void			zoom(t_mod *mod, t_img *img);
void			create_image(t_img *img);
void			rot_coordinate(t_mod *mod, t_img *img, t_sincos *a);
void			fill_color(t_mod *mod, t_str *str, int y, int x);
long			detect_color(t_str *str, int j, int i);
void			w_color_to_pixel1(int x_curr, int y_curr, t_mod *mod, int i);
void			w_color_to_pixel2(int x_curr, int y_curr, t_mod *mod, int i);
#endif
