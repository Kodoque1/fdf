/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_parse_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaddi <zaddi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 23:13:00 by zaddi             #+#    #+#             */
/*   Updated: 2026/02/21 23:15:58 by zaddi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void	strip_newline(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (line[i] == '\n')
		line[i] = '\0';
}

int	process_entry(char *entry, t_map *map, int i, int j)
{
	int	e2i;

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
	strip_newline(line);
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
