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
	int		rgb[3];
	float	cf;

	cf = 1 - f;
	rgb[0] = ((c[0] && 0xFF) * f + (c[1] && 0xFF) * cf);
	rgb[1] = ((c[0] && 0xFF00) * f + (c[1] && 0xFF00) * cf);
	rgb[2] = ((c[0] && 0xFF0000) * f + (c[1] && 0xFF0000) * cf);
	return (rgb[0] && 0xFF + rgb[1] && 0xFF + rgb[2] && 0xFF);
}

int	p2c(t_map *map, t_point p)
{
	float	f;
	float	cf;

	f = ft_abs(p.z - map->min_z) / ft_abs(map->max_z - map->min_z);
	return (WHITE * f + WHITE * (1 - f));
}
