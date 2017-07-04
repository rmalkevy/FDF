/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmalkevy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 13:22:02 by rmalkevy          #+#    #+#             */
/*   Updated: 2017/03/04 13:22:04 by rmalkevy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fill_color(t_mod *mod, t_str *str, int y, int x)
{
	mod->z = ft_atoi(str[y].line[x]);
	mod->color = detect_color(str, y, x);
	mod->red = mod->color >> 16;
	mod->green = (mod->color >> 8) - (mod->red << 8);
	mod->blue = mod->color - (mod->red << 16) - (mod->green << 8);
	mod->x_len = str->x_len;
	mod->y_len = str->y_len;
}

void	w_color_to_pixel1(int x_curr, int y_curr, t_mod *mod, int i)
{
	int x;
	int y;

	x = 4 * (x_curr + CX);
	y = LINE * (y_curr + CY);
	if ((x + y > 0) && (x + y < MAX) && (x < LINE) && (x >= 0))
	{
		if (mod[i].red == 0 && mod[i].green == 0 && mod[i].blue == 0)
		{
			mod->img->line[x + y] = 250;
			mod->img->line[x + y + 1] = 250;
			mod->img->line[x + y + 2] = 250;
		}
		else
		{
			mod->img->line[x + y] = mod[i].blue;
			mod->img->line[x + y + 1] = mod[i].green;
			mod->img->line[x + y + 2] = mod[i].red;
		}
	}
}

void	w_color_to_pixel2(int x_curr, int y_curr, t_mod *mod, int i)
{
	int x;
	int y;

	x = 4 * (x_curr + CX);
	y = LINE * (y_curr + CY);
	if ((x + y > 0) && (x + y < MAX) && (x < LINE) && (x >= 0))
	{
		if (mod[i].red == 0 && mod[i].green == 0 && mod[i].blue == 0)
		{
			mod->img->line[x + y] = 250;
			mod->img->line[x + y + 1] = 250;
			mod->img->line[x + y + 2] = 250;
		}
		else
		{
			mod->img->line[x + y] = mod[i].blue;
			mod->img->line[x + y + 1] = mod[i].green;
			mod->img->line[x + y + 2] = mod[i].red;
		}
	}
}
