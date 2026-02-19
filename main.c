/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaddi <zaddi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 15:04:29 by zaddi             #+#    #+#             */
/*   Updated: 2026/02/19 18:30:22 by zaddi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

static void	cleanup_and_exit(t_vars *vars)
{
	if (vars->map)
		free_map(vars->map);
	if (vars->img && vars->img->img)
		mlx_destroy_image(vars->mlx, vars->img->img);
	mlx_destroy_window(vars->mlx, vars->win);
}

int	close_window(int keycode, t_vars *vars)
{
	if (keycode == 17 || keycode == 65307)
	{
		cleanup_and_exit(vars);
		exit(0);
	}
	return (0);
}

int	check_extension(char *str)
{
	int	size;

	size = ft_strlen(str);
	return ((size > 4) && ft_strncmp(str + size - 4, ".fdf", 4) == 0);
}

static int	init_graphics(t_vars *vars, t_data *img)
{
	vars->mlx = mlx_init();
	if (!vars->mlx)
		return (-1);
	vars->win = mlx_new_window(vars->mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "fdf");
	if (!vars->win)
		return (-1);
	vars->img = img;
	img->img = mlx_new_image(vars->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	if (!img->img)
		return (mlx_destroy_window(vars->mlx, vars->win), -1);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	return (0);
}



int	main(int argc, char **argv)
{
	t_map	map;
	t_vars	vars;
	t_data	img;

	if (argc != 2 || !check_extension(argv[1]))
		return (ft_printf("usage: ./fdf map.fdf\n"), 1);
	if (init_graphics(&vars, &img) == -1)
		return (1);
	if (parse_map(argv[1], &map) == -1)
		return (mlx_destroy_image(vars.mlx, img.img),
			mlx_destroy_window(vars.mlx, vars.win), 1);
	vars.map = &map;
	scale_and_center(&map);
	draw_map(&map, &img, WHITE);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_hook(vars.win, 17, 0, close_window, &vars);
	mlx_hook(vars.win, 2, 1L << 0, close_window, &vars);
	mlx_loop(vars.mlx);
	cleanup_and_exit(&vars);
	return (0);
}
