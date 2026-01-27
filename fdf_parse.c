/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaddi <zaddi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 16:01:34 by zaddi             #+#    #+#             */
/*   Updated: 2026/01/25 16:56:34 by zaddi            ###   ########.fr       */
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
	if (entry) 
	{
		set_point(&(map->map[j][i]), i, j, ft_atoi(entry) * 2);
		return (0);
	}
	ft_printf("entry:%s\n", entry);
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

	if (rows_and_columns_size(path, map) == -1)
		return (-1);
	ft_printf("w:%d, h:%d\n", map->w, map->h);
	init_contiguous(map);
	if (!map)
		return (-1);
	f = open(path, O_RDONLY);
	if (f == -1)
		return (-1);
	j = 0;
	while (j < map->h)
	{
		ft_printf("i:%d\n", j);
		if (process_line(get_next_line(f), map, j) == -1)
		{
			ft_printf("break\n", j);
			return (-1);
		}

		j++;
	}
	close(f);
	return (0);
}
