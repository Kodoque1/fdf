/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaddi <zaddi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 16:01:34 by zaddi             #+#    #+#             */
/*   Updated: 2026/02/12 12:38:00 by zaddi            ###   ########.fr       */
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
	if (!buf)
		return (close(f), -1);
	map->w = count_word(buf, ' ');
	while (buf)
	{
		if (count_word(buf, ' ') != map->w)
			return (free(buf), close(f), -1);
		map->h++;
		free(buf);
		buf = get_next_line(f);
	}
	if (close(f) == -1)
		return (-1);
	return (0);
}

int	process_entry(char *entry, t_map *map, int i, int j)
{
	int	e2i;

	if (!entry)
		return (-1);
	e2i = ft_atoi(entry);
	if (e2i < map->min_z)
		map->min_z = e2i;
	if (e2i > map->max_z)
		map->max_z = e2i;
	set_point(&(map->map[j][i]), i, j, e2i);
	return (0);
}

int	process_line(char *line, t_map *map, int j)
{
	char	**strs;
	int		i;

	if (!line)
		return (-1);
	strs = ft_split(line, ' ');
	free(line);
	if (!strs)
		return (-1);
	i = 0;
	while (strs[i])
	{
		if (process_entry(strs[i], map, i, j) == -1)
			return (free_array(strs), -1);
		i++;
	}
	free_array(strs);
	return (0);
}

int	parse_map(char *path, t_map *map)
{
	int		j;
	int		f;
	char	*line;

	map->max_z = -2147483648;
	map->min_z = 2147483647;
	if (rows_and_columns_size(path, map) == -1)
		return (-1);
	init_contiguous(map);
	if (!map->map)
		return (-1);
	f = open(path, O_RDONLY);
	if (f == -1)
		return (-1);
	j = 0;
	while (j < map->h)
	{
		line = get_next_line(f);
		if (process_line(line, map, j) == -1)
			return (close(f), -1);
		j++;
	}
	close(f);
	return (0);
}
