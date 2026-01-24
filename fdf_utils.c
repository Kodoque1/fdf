/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaddi <zaddi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 16:01:34 by zaddi             #+#    #+#             */
/*   Updated: 2026/01/24 18:19:01 by zaddi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

int	file_size(char *path)
{
	int	f;
	int	counter;

	counter = 0;
	f = open(path, O_RDONLY);
	if (f == -1)
		return (-1);
	while (get_next_line(f))
		counter++;
	if (close(f) == -1)
		return (-1);
	return (counter);
}

void	process_line(char *line, t_point **map, int i)
{
	char	**split;

	split = ft_split(line, ' ');
}

int	parse_map(char *path, int **map)
{
	int		size;
	int		f;
	char	**buf;
	int		counter;

	size = file_size(path);
	f = open(path, O_RDONLY);
	if (f == -1)
	{
		perror(NULL);
		exit(-1);
	}
	if (size)
	{
		buf = get_next_line(f);
		map = malloc(size * count_word(buf, ' ') * sizeof(t_point));
		counter = 1;
	}
}
