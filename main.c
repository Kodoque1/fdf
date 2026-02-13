/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaddi <zaddi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 15:04:29 by zaddi             #+#    #+#             */
/*   Updated: 2026/02/13 22:20:30 by zaddi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

int	close_window(int keycode, t_vars *vars)
{
	(void) keycode;
	mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}

int	check_extension(char *str)
{
	int	size;

	size = ft_strlen(str);
	return ((size > 4) && ft_strncmp(str + size - 4, ".fdf", 4) == 0);
}

int	main(int argc, char **argv)
{
	t_map	map;
	t_vars	vars;
	t_data	img;

	if ((argc != 2) || !check_extension(argv[1]))
	{
		ft_printf("usage: ./fdf map.fdf\n");
		exit(-1);
	}
	else
	{
		vars.mlx = mlx_init();
		vars.win = mlx_new_window(vars.mlx, SCREEN_WIDTH, SCREEN_HEIGHT,
				"fdf");
		img.img = mlx_new_image(vars.mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
		img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
				&img.line_length, &img.endian);
		parse_map(argv[1], &map);
		scale_and_center(&map);
		draw_map(&map, &img);
		mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
		mlx_hook(vars.win, 2, 1L << 0, close_window, &vars);
		mlx_loop(vars.mlx);
	}
}
