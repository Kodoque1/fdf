/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaddi <zaddi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 16:01:34 by zaddi             #+#    #+#             */
/*   Updated: 2026/02/11 19:40:27 by zaddi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

int	rows_and_columns_size(char *path, t_map *map)
{
	int		f;
	char	*buf;

	map->w = 0;
	map->h = 0;
	f = open(path, O_RDONLY);
	if (f == -1)
		return (-1);
	buf = get_next_line(f);
	if (buf)
	{
		map->w = count_word(buf, ' ');
		map->h = 1;
		while (buf)
		{
			if (count_word(buf, ' ') != map->w)
				return (-1);
			buf = get_next_line(f);
			(map->h)++;
		}
		if (close(f) == -1)
			return (-1);
	}
	return (0);
}

int	process_entry(char *entry, t_map *map, int i, int j)
{
	int	e2i;

	if (entry)
	{
		e2i = ft_atoi(entry);
		if (e2i < map->min_z)
			map->min_z = e2i;
		if (e2i > map->max_z)
			map->max_z = e2i;
		set_point(&(map->map[j][i]), i, j, ft_atoi(entry));
		return (0);
	}
	return (-1);
}

int	process_line(char *line, t_map *map, int j)
{
	char	**strs;
	int		i;

	if (line)
	{
		strs = ft_split(line, ' ');
		if (strs)
		{
			i = 0;
			while (strs[i])
			{
				if (process_entry(strs[i], map, i, j) == -1)
				{
					free_array(strs);
					return (-1);
				}
				i++;
			}
			free_array(strs);
			return (0);
		}
		else
			return (-1);
	}
	return (-1);
}

int	parse_map(char *path, t_map *map)
{
	int	j;
	int	f;

	map->max_z = -2147483648;
	map->min_z = 2147483647;
	if (rows_and_columns_size(path, map) == -1)
		return (-1);
	init_contiguous(map);
	if (!map)
		return (-1);
	f = open(path, O_RDONLY);
	if (f == -1)
		return (-1);
	j = 0;
	while (j < map->h)
	{
		if (process_line(get_next_line(f), map, j) == -1)
			return (-1);
		j++;
	}
	close(f);
	return (0);
}
