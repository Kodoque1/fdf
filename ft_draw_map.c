/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaddi <zaddi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 13:31:01 by zaddi             #+#    #+#             */
/*   Updated: 2026/02/11 20:00:54 by zaddi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void	draw_rows(t_map *map, int i, t_data *data, int color)
{
	int	j;

	j = 0;
	while (j < (map->w - 1))
	{
		draw_line(map->map[i][j], map->map[i][j + 1], data, color);
		j++;
	}
}

void	draw_columns(t_map *map, int j, t_data *data, int color)
{
	int		i;
	t_point	p1;
	t_point	p2;
	int		c[2];

	i = 0;
	while (i < (map->h - 2))
	{
		p1 = map->map[i][j];
		p2 = map->map[i + 1][j];
		c[0] = p2c(map, p1);
		c[1] = p2c(map, p2);
		draw_line(p1, p2, data, c);
		i++;
	}
}

void	draw_map(t_map *map, t_data *data, int color)
{
	int	i;

	i = 0;
	while (i < map->h)
	{
		draw_rows(map, i, data, color);
		i++;
	}
	i = 0;
	while (i < map->w)
	{
		draw_columns(map, i, data, color);
		i++;
	}
}
