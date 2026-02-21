/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaddi <zaddi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 15:04:29 by zaddi             #+#    #+#             */
/*   Updated: 2026/02/21 23:15:58 by zaddi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

static int	init_graphics(t_vars *vars, t_data *img)
{
	vars->mlx = mlx_init();
	if (!vars->mlx)
		return (-1);
	vars->win = mlx_new_window(vars->mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "fdf");
	if (!vars->win)
	{
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
		return (-1);
	}
	vars->img = img;
	img->img = mlx_new_image(vars->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	if (!img->img)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
		return (-1);
	}
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	return (0);
}



static void	cleanup_on_parse_error(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->img->img);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
}

int	main(int argc, char **argv)
{
	t_map	map;
	t_vars	vars;
	t_data	img;

	ft_memset(&vars, 0, sizeof(t_vars));
	if (argc != 2 || !check_extension(argv[1]))
		return (ft_printf("usage: ./fdf map.fdf\n"), 1);
	if (init_graphics(&vars, &img) == -1)
		return (ft_printf("Error: failed to initialize graphics\n"), 1);
	if (parse_map(argv[1], &map) == -1)
	{
		cleanup_on_parse_error(&vars);
		return (ft_printf("Error: failed to parse map\n"), 1);
	}
	vars.map = &map;
	scale_and_center(&map);
	draw_map(&map, &img, WHITE);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_hook(vars.win, EVENT_DESTROY, 0, handle_close, &vars);
	mlx_hook(vars.win, EVENT_KEYPRESS, 1L << 0, handle_keypress, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
