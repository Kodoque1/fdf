/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaddi <zaddi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 15:04:15 by zaddi             #+#    #+#             */
/*   Updated: 2026/01/25 17:03:03 by zaddi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FDF_H
# define FT_FDF_H

# define SQR3_SQR6 0.707106781
# define SQR2_SQR6 0.577350269
# define N1_SQR6 0.40824829
# define SCREEN_WIDTH 800
# define SCREEN_HEIGHT 600
# define SCREEN_FACTOR 0.4

# include "ft_printf.h"
# include "get_next_line.h"
# include "libft.h"
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}			t_vars;

typedef struct s_point
{
	int		x;
	int		y;
	int		z;
}			t_point;

typedef struct s_map
{
	int		w;
	int		h;
	t_point	**map;
}			t_map;

t_point		*create_point(int x, int y, int z);
void		set_point(t_point *point, int x, int y, int z);
int			parse_map(char *path, t_map *map);
void		draw_line(t_point p0, t_point p1, t_data *data, int color);
void		map_iso_proj(t_map *map);
void		draw_map(t_map *map, t_data *data, int color);
void		ft_translate(t_point *point, int x, int y, int z);
void		scale_and_center(t_map *map);
void		init_contiguous(t_map *map);

#endif
