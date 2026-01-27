/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaddi <zaddi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 11:30:57 by zaddi             #+#    #+#             */
/*   Updated: 2026/01/25 16:40:34 by zaddi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void	ft_translate(t_point *point, int x, int y, int z)
{
	point->x += x;
	point->y += y;
	point->z += z;
}

void	ft_scale(t_point *point, float sx, float sy, float sz)
{
	point->x *= sx;
	point->y *= sy;
	point->z *= sz;
}

void	point_iso_proj(t_point *point)
{
	point->x = SQR3_SQR6 * (point->x - point->y);
	point->y = N1_SQR6 * ((point->x + point->y)) - point->z;
	point->z = SQR2_SQR6 * (point->x + point->y + point->z);
}

void	map_iso_proj(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->h)
	{
		j = 0;
		while (j < map->w)
		{
			point_iso_proj(&(map->map[i][j]));
			j++;
		}
		i++;
	}
}

void	scale_and_center(t_map *map)
{
	int	i;
	int	j;
	int	sx;
	int	sy;

	i = 0;
	sx = SCREEN_WIDTH / map->w * SCREEN_FACTOR;
	sy = SCREEN_HEIGHT / map->h * SCREEN_FACTOR;
	while (i < map->h)
	{
		j = 0;
		while (j < map->w)
		{
			ft_translate(&(map->map[i][j]), -map->w / 2, -map->h / 2, 0);
			ft_scale(&(map->map[i][j]), sx, sy, 1);
			point_iso_proj(&(map->map[i][j]));
			ft_translate(&(map->map[i][j]), SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2,
				0);
			j++;
		}
		i++;
	}
}
