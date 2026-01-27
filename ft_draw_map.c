/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaddi <zaddi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 13:31:01 by zaddi             #+#    #+#             */
/*   Updated: 2026/01/25 17:09:41 by zaddi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void	draw_rows(t_map *map, int i, t_data *data, int color)
{
	int	j;

	j = 0;
	while (j < (map->w - 1))
	//while (j < 1)
	{
		draw_line(map->map[i][j], map->map[i][j + 1], data, color);
		j++;
	}
}

void	draw_columns(t_map *map, int j, t_data *data, int color)
{
	int	i;

	i = 0;
	while (i < (map->h - 2))
	//while (i < 1)
	{
		draw_line(map->map[i][j], map->map[i + 1][j], data, color);
		i++;
	}
}

void	draw_map(t_map *map, t_data *data, int color)
{
	int	i;

	i = 0;	//while (i < 1)
	while (i < map->h)
	//while (i < 1)
	{
		draw_rows(map, i, data, color);
		i++;
	}
	i = 0;
	while (i < map->w)
	//while (i < 1)
	{
		draw_columns(map, i, data, color);
		i++;
	}
}
