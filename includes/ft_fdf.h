/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaddi <zaddi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 15:04:15 by zaddi             #+#    #+#             */
/*   Updated: 2026/02/21 23:15:58 by zaddi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FDF_H
# define FT_FDF_H

# define SQR3_SQR6 0.707106781
# define SQR2_SQR6 0.577350269
# define N1_SQR6 0.40824829
# define SCREEN_WIDTH 800
# define SCREEN_HEIGHT 600
# define SCREEN_FACTOR 0.7
# define WHITE 0xFFFFFF
# define VIOLET 0x7F00FF
# define CYAN 0x00FFFF
# define KEY_ESC 65307
# define EVENT_DESTROY 17
# define EVENT_KEYPRESS 2

# include "ft_printf.h"
# include "get_next_line.h"
# include "libft.h"
# include <fcntl.h>
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
	int		min_z;
	int		max_z;
	t_point	**map;
}			t_map;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	t_map	*map;
	t_data	*img;
}			t_vars;

t_point		*create_point(int x, int y, int z);
void		set_point(t_point *point, int x, int y, int z);
int			parse_map(char *path, t_map *map);
int			rows_and_columns_size(char *path, t_map *map);
void		strip_newline(char *line);
int			process_entry(char *entry, t_map *map, int i, int j);
int			process_line(char *line, t_map *map, int j);
void		draw_line(t_point p0, t_point p1, t_data *data, int c[2]);
void		map_iso_proj(t_map *map);
void		draw_map(t_map *map, t_data *data, int color);
void		ft_translate(t_point *point, int x, int y, int z);
void		scale_and_center(t_map *map);
int			init_contiguous(t_map *map);
void		free_map(t_map *map);
int			interpolate(int c[2], float f);
int			p2c(t_map *map, t_point p);
int			check_extension(char *str);
void		cleanup_and_exit(t_vars *vars);
int			handle_close(t_vars *vars);
int			handle_keypress(int keycode, t_vars *vars);

#endif
