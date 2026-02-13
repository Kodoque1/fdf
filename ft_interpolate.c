/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_interpolate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaddi <zaddi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 17:14:39 by zaddi             #+#    #+#             */
/*   Updated: 2026/02/13 17:41:20 by zaddi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"
#include "stdio.h"

int	bytes(int n, int i)
{
	return ((n >> (8 * i)) & 0xFF);
}

int	interpolate(int v1, int v2, float f)
{
	float	cf;

	if (f > 1.)
		f = 1.;
	else if (f < 0.)
		f = 0.;
	cf = 1. - f;
	return (v1 * cf + v2 * f);
}

int	inter_color(int c[2], float f)
{
	int	i;
	int	final_color;

	final_color = 0;
	i = 0;
	while (i < 3)
	{
		final_color += (interpolate(bytes(c[0], i), bytes(c[1], i),
					f) & 0xFF) << (8 * i);
		i++;
	}
	return (final_color);
}

int	p2c(t_map *map, t_point p)
{
	float	f;
	int		c[2];

	if (map->max_z == map->min_z)
		return (WHITE);
	c[0] = WHITE;
	c[1] = VIOLET;
	f = (float)(p.z - map->min_z) / (float)(map->max_z - map->min_z);
	return (inter_color(c, f));
}
