/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base_to_10.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmalkevy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 13:18:27 by rmalkevy          #+#    #+#             */
/*   Updated: 2017/03/04 13:18:29 by rmalkevy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static long	ft_convert(char *str, int base, long n)
{
	int r;

	r = 0;
	while (*str != '\0')
	{
		if ((*str < 48 || *str > ((base / 10) ? 57 : 47 + base))
			&& (*str < 65 || *str > ((base / 10) ? 54 + base : 64))
			&& (*str < 87 || *str > ((base / 10) ? 86 + base : 96)))
			return (r * n);
		if (*str > 47 && *str < 58)
			r = r * base + *str - '0';
		else if (*str > 64 && *str < 71)
			r = r * base + (*str - 65) + 10;
		else
			r = r * base + (*str - 97) + 10;
		str++;
	}
	return (r * n);
}

long		ft_atoi_base(char *str, unsigned int base)
{
	int		n;

	n = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' && base == 10)
	{
		n = -1;
		str++;
	}
	else if (*str == '+' && base == 10)
		str++;
	while (*str == '0')
		str++;
	return (ft_convert(str, base, n));
}
