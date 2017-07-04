/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_structure.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmalkevy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 13:17:03 by rmalkevy          #+#    #+#             */
/*   Updated: 2017/03/06 11:51:37 by rmalkevy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

long	detect_color(t_str *str, int j, int i)
{
	char *p;

	if ((p = ft_strchr(str[j].line[i], ',')))
		return (ft_atoi_base(p + 3, 16));
	return (0);
}

t_str	*create_str(char **map, int len)
{
	t_str	*str;
	int		i;
	int		j;

	i = -1;
	j = 0;
	if (!(str = (t_str*)malloc(sizeof(t_str) * (len + 1))))
		return (0);
	while (++i < len)
		str[i].line = ft_strsplit(map[i], ' ');
	str->y_len = len;
	i = 0;
	while (str[j].line[i])
		i++;
	str->x_len = i;
	return (str);
}

int		ft_read_map(char **argv, char **map)
{
	char	*line;
	int		len;
	int		fd;
	int		error;

	len = 0;
	line = NULL;
	fd = open(argv[1], O_RDONLY);
	while ((error = get_next_line(fd, &line) > 0) && error != -1)
	{
		map[len] = ft_strdup(line);
		len++;
	}
	if (error == -1)
	{
		ft_putstr("Put correct map!");
		exit(0);
	}
	map[len] = 0;
	return (len);
}

t_mod	*fill_mod(t_str *str)
{
	int		j;
	int		x;
	int		y;
	t_mod	*mod;

	y = -1;
	j = 0;
	mod = (t_mod*)malloc(sizeof(t_mod) * str->y_len * str->x_len);
	while (++y < str->y_len)
	{
		x = -1;
		while (++x < str->x_len)
		{
			fill_color(&mod[j], str, y, x);
			mod[j].x = (x - mod->x_len / 2) * (CX / mod->x_len);
			mod[j].y = (y - mod->y_len / 2) * (CY / mod->y_len);
			mod[j].rz = mod[j].z;
			mod[j].rx = mod[j].x;
			mod[j].ry = mod[j].y;
			j++;
		}
	}
	return (mod);
}
