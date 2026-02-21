/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaddi <zaddi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 16:01:34 by zaddi             #+#    #+#             */
/*   Updated: 2026/02/21 23:15:58 by zaddi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

static int	validate_and_count_rows(int f, t_map *map)
{
	char	*buf;
	int		words;

	buf = get_next_line(f);
	while (buf)
	{
		strip_newline(buf);
		words = count_word(buf, ' ');
		if (words != map->w)
			return (free(buf), close(f), -1);
		map->h++;
		free(buf);
		buf = get_next_line(f);
	}
	return (0);
}

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
	strip_newline(buf);
	map->w = count_word(buf, ' ');
	if (map->w <= 0)
		return (free(buf), close(f), -1);
	map->h = 1;
	free(buf);
	if (validate_and_count_rows(f, map) == -1)
		return (-1);
	close(f);
	if (map->h == 0)
		return (-1);
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
	if (init_contiguous(map) == -1)
		return (-1);
	f = open(path, O_RDONLY);
	if (f == -1)
		return (free_map(map), -1);
	j = 0;
	while (j < map->h)
	{
		line = get_next_line(f);
		if (process_line(line, map, j) == -1)
			return (close(f), free_map(map), -1);
		j++;
	}
	close(f);
	return (0);
}
