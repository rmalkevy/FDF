/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmalkevy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 13:19:15 by rmalkevy          #+#    #+#             */
/*   Updated: 2017/03/04 13:19:19 by rmalkevy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void	addition_key_func(int keycode, t_mod *mod)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 24)
	{
		if (mod->img->zoom < 11)
			mod->img->zoom += 1;
	}
	else if (keycode == 27)
	{
		if (mod->img->zoom > 1)
			mod->img->zoom -= 1;
	}
	else if (keycode == 1)
		mod->img->updo += 10;
	else if (keycode == 13)
		mod->img->updo -= 10;
	else if (keycode == 0)
		mod->img->rile -= 10;
	else if (keycode == 2)
		mod->img->rile += 10;
	else if (keycode == 69)
		mod->img->zzoom += 1;
	else if (keycode == 78)
		mod->img->zzoom -= 1;
}

int		my_key_funct(int k, t_mod *mod)
{
	char	*buf;
	int		a;

	printf(" k = %d\n", k);
	if (k < 82)
		addition_key_func(k, mod);
	else if (k == 126)
		mod->img->angl_x += 0.04;
	else if (k == 125)
		mod->img->angl_x -= 0.04;
	else if (k == 123)
		mod->img->angl_y += 0.04;
	else if (k == 124)
		mod->img->angl_y -= 0.04;
	else if (k == 83)
		mod->img->angl_z += 0.04;
	else if (k == 82)
		mod->img->angl_z -= 0.04;
	rot_coordinate(mod, mod->img, mod->a);
	buf = mlx_get_data_addr(mod->img->image, &a, &a, &a);
	ft_bzero(mlx_get_data_addr(mod->img->image, &a, &a, &a), 4 * WX * HY);
	write_to_image(mod, mod->img);
	return (0);
}

void	create_image(t_img *img)
{
	int		size_line;
	int		bits_p_p;
	int		endian;

	img->image = mlx_new_image(img->mlx, WX, HY);
	img->line = mlx_get_data_addr(img->image, &bits_p_p, &size_line, &endian);
	img->angl_x = 190 * 0.0174532925;
	img->angl_y = 0 * 0.0174532925;
	img->angl_z = -10 * 0.0174532925;
	img->zoom = 1;
	img->zzoom = 1;
	img->updo = 0;
	img->rile = 0;
}

int		main(int ac, char **argv)
{
	char		**map;
	int			len;
	t_mod		*mod;
	t_sincos	*a;
	t_str		*str;

	if (ac == 2)
	{
		map = (char**)malloc(BUFF);
		len = ft_read_map(argv, map);
		str = create_str(map, len);
		mod = fill_mod(str);
		mod->img = (t_img*)malloc(sizeof(t_img));
		mod->img->mlx = mlx_init();
		mod->img->win = mlx_new_window(mod->img->mlx, WX, HY, "Star 42");
		create_image(mod->img);
		a = (t_sincos*)malloc(sizeof(t_sincos));
		mod->a = a;
		rot_coordinate(mod, mod->img, a);
		write_to_image(mod, mod->img);
	}
	else
		ft_putstr("Add one map :)");
	return (0);
}
