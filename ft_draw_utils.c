/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaddi <zaddi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 16:04:11 by zaddi             #+#    #+#             */
/*   Updated: 2026/01/25 17:11:13 by zaddi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	//ft_printf("x:%d, y:%d\n", x, y);
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	init_delta_sign(t_point *d, t_point *s, t_point p0, t_point p1)
{
	d->x = ft_abs(p1.x - p0.x);
	d->y = ft_abs(p1.y - p0.y);
	if (d->x > d->y)
		d->z = d->x / 2;
	else
		d->z = -d->y / 2;
	if (p0.x < p1.x)
		s->x = 1;
	else
		s->x = -1;
	if (p0.y < p1.y)
		s->y = 1;
	else
		s->y = -1;
}

void	draw_line(t_point p0, t_point p1, t_data *data, int color)
{
	t_point	d;
	t_point	s;

	init_delta_sign(&d, &s, p0, p1);
	while (!(p0.x == p1.x && p0.y == p1.y))
	{
		my_mlx_pixel_put(data, p0.x, p0.y, color);
		s.z = d.z;
		if (s.z > -d.x)
		{
			d.z -= d.y;
			p0.x += s.x;
		}
		if (s.z < d.y)
		{
			d.z += d.x;
			p0.y += s.y;
		}
	}
}

