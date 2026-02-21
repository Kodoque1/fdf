/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaddi <zaddi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 23:15:00 by zaddi             #+#    #+#             */
/*   Updated: 2026/02/21 23:15:58 by zaddi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void	cleanup_and_exit(t_vars *vars)
{
	if (vars->map)
		free_map(vars->map);
	if (vars->img->img)
		mlx_destroy_image(vars->mlx, vars->img->img);
	if (vars->win)
		mlx_destroy_window(vars->mlx, vars->win);
	if (vars->mlx)
	{
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
	}
}

int	handle_close(t_vars *vars)
{
	cleanup_and_exit(vars);
	exit(0);
	return (0);
}

int	handle_keypress(int keycode, t_vars *vars)
{
	if (keycode == KEY_ESC)
	{
		cleanup_and_exit(vars);
		exit(0);
	}
	return (0);
}
