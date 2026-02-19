/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_interpolate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaddi <zaddi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 17:14:39 by zaddi             #+#    #+#             */
/*   Updated: 2026/02/11 20:03:33 by zaddi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

int	interpolate(int c[2], float f)
{
	int		r;
	int		g;
	int		b;
	float	cf;

	cf = 1.0f - f;
	r = (int)(((c[0] >> 16) & 0xFF) * cf + ((c[1] >> 16) & 0xFF) * f);
	g = (int)(((c[0] >> 8) & 0xFF) * cf + ((c[1] >> 8) & 0xFF) * f);
	b = (int)((c[0] & 0xFF) * cf + (c[1] & 0xFF) * f);
	return ((r << 16) | (g << 8) | b);
}

int	p2c(t_map *map, t_point p)
{
	float	f;
	int		range;
	int		c[2];

	range = map->max_z - map->min_z;
	if (range == 0)
		return (WHITE);
	f = (float)(p.z - map->min_z) / (float)range;
	if (f < 0.5f)
	{
		c[0] = VIOLET;
		c[1] = WHITE;
		return (interpolate(c, f * 2.0f));
	}
	c[0] = WHITE;
	c[1] = 0x88CCFF;
	return (interpolate(c, (f - 0.5f) * 2.0f));
}
