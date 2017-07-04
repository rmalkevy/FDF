/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_picture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmalkevy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 13:17:31 by rmalkevy          #+#    #+#             */
/*   Updated: 2017/03/04 13:17:33 by rmalkevy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		cal_xcurr(t_mod *mod, int x1, int x2, int y_curr)
{
	int x_curr;

	x_curr = mod[x1].x;
	if (mod[x2].y - mod[x1].y != 0)
	{
		x_curr = (mod[x2].x - mod[x1].x) * (y_curr - mod[x1].y);
		x_curr = x_curr / (mod[x2].y - mod[x1].y) + mod[x1].x;
	}
	return (x_curr);
}

int		cal_ycurr(t_mod *mod, int x1, int x2, int x_curr)
{
	int y_curr;

	y_curr = mod[x1].y;
	if (mod[x2].x - mod[x1].x != 0)
	{
		y_curr = ((x_curr - mod[x1].x) * (mod[x2].y - mod[x1].y));
		y_curr = y_curr / (mod[x2].x - mod[x1].x) + mod[x1].y;
	}
	return (y_curr);
}

void	print_yline(t_mod *mod, int x1, int x2)
{
	int x_curr;
	int y_curr;
	int y_max;
	int x_max;

	y_curr = (mod[x1].y <= mod[x2].y) ? mod[x1].y : mod[x2].y;
	y_max = (mod[x1].y >= mod[x2].y) ? mod[x1].y : mod[x2].y;
	while (y_curr <= y_max)
	{
		x_curr = cal_xcurr(mod, x1, x2, y_curr);
		w_color_to_pixel2(x_curr, y_curr, mod, x1);
		y_curr++;
	}
	x_curr = (mod[x1].x <= mod[x2].x) ? mod[x1].x : mod[x2].x;
	x_max = (mod[x1].x >= mod[x2].x) ? mod[x1].x : mod[x2].x;
	while (x_curr < x_max)
	{
		y_curr = cal_ycurr(mod, x1, x2, x_curr);
		w_color_to_pixel2(x_curr, y_curr, mod, x1);
		x_curr++;
	}
}

void	print_xline(t_mod *mod, int i)
{
	int x_curr;
	int y_curr;
	int x_max;
	int y_max;

	x_curr = (mod[i].x <= mod[i + 1].x) ? mod[i].x : mod[i + 1].x;
	x_max = (mod[i].x >= mod[i + 1].x) ? mod[i].x : mod[i + 1].x;
	while (x_curr <= x_max)
	{
		y_curr = cal_ycurr(mod, i, i + 1, x_curr);
		w_color_to_pixel1(x_curr, y_curr, mod, i);
		x_curr++;
	}
	y_curr = (mod[i].y <= mod[i + 1].y) ? mod[i].y : mod[i + 1].y;
	y_max = (mod[i].y >= mod[i + 1].y) ? mod[i].y : mod[i + 1].y;
	while (y_curr < y_max)
	{
		x_curr = cal_xcurr(mod, i, i + 1, y_curr);
		w_color_to_pixel1(x_curr, y_curr, mod, i);
		y_curr++;
	}
}

void	write_to_image(t_mod *mod, t_img *img)
{
	int y;
	int x;
	int i;

	y = 0;
	i = 0;
	mlx_put_image_to_window(img->mlx, img->win, img->image, 0, 0);
	while (y < mod->y_len)
	{
		x = 0;
		while (x < mod->x_len)
		{
			if (x + 1 < mod->x_len)
				print_xline(mod, i);
			if (y + 1 < mod->y_len)
				print_yline(mod, i, i + mod->x_len);
			x++;
			i++;
		}
		y++;
	}
	mlx_put_image_to_window(img->mlx, img->win, img->image, 0, 0);
	mlx_hook(img->win, 2, 5, my_key_funct, mod);
	mlx_loop(img->mlx);
}
