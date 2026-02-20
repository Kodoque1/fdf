/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaddi <zaddi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 10:01:40 by zaddi             #+#    #+#             */
/*   Updated: 2026/02/20 13:37:46 by zaddi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

t_point	*create_point(int x, int y, int z)
{
	t_point	*point;

	point = malloc(sizeof(t_point));
	point->x = x;
	point->y = y;
	point->z = z;
	return (point);
}

void	set_point(t_point *point, int x, int y, int z)
{
	point->x = x;
	point->y = y;
	point->z = z;
}

int	init_contiguous(t_map *map)
{
	t_point	*all_points;
	int		i;

	map->map = malloc(map->h * sizeof(t_point *));
	if (!map->map)
		return (-1);
	all_points = (t_point *) malloc(map->w * map->h * sizeof(t_point));
	if (!all_points)
	{
		free(map->map);
		map->map = NULL;
		return (-1);
	}
	ft_memset(all_points, 0, map->w * map->h * sizeof(t_point));
	i = 0;
	while (i < map->h)
	{
		map->map[i] = &all_points[i * map->w];
		i++;
	}
	return (0);
}

void	free_map(t_map *map)
{
	if (!map)
		return ;
	if (map->map)
	{
		if (map->map[0])
			free(map->map[0]);
		free(map->map);
	}
}

int	check_extension(char *str)
{
	int	size;

	size = ft_strlen(str);
	return ((size > 4) && ft_strncmp(str + size - 4, ".fdf", 4) == 0);
}
