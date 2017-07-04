/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_picture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmalkevy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 13:17:48 by rmalkevy          #+#    #+#             */
/*   Updated: 2017/03/04 13:17:51 by rmalkevy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rot_coordinate(t_mod *mod, t_img *img, t_sincos *a)
{
	int		i;
	float	x;
	float	y;
	float	z;

	i = -1;
	a->cy_cz = cos(img->angl_y) * cos(img->angl_z);
	a->cy_sz = cos(img->angl_y) * sin(img->angl_z);
	a->sy = sin(img->angl_y);
	a->sx_sy_cz = sin(img->angl_x) * sin(img->angl_y) * cos(img->angl_z);
	a->cx_sz = cos(img->angl_x) * sin(img->angl_z);
	a->sx_sy_sz = sin(img->angl_x) * sin(img->angl_y) * sin(img->angl_z);
	a->cx_cz = cos(img->angl_x) * cos(img->angl_z);
	a->sx_cy = sin(img->angl_x) * cos(img->angl_y);
	a->sum1 = (a->sx_sy_cz + a->cx_sz);
	a->sum2 = (a->sx_sy_sz + a->cx_cz);
	while (++i < mod->y_len * mod->x_len)
	{
		x = mod[i].rx * img->zoom + img->rile;
		y = mod[i].ry * img->zoom + img->updo;
		z = mod[i].rz * img->zoom * mod->img->zzoom;
		mod[i].x = ceil(x * a->cy_cz - y * a->cy_sz - z * a->sy);
		mod[i].y = ceil(x * a->sum1 - y * a->sum2 + z * a->sx_cy);
	}
}
