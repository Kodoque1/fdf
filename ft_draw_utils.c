/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaddi <zaddi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 16:04:11 by zaddi             #+#    #+#             */
/*   Updated: 2026/02/13 17:41:02 by zaddi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"
#include "stdio.h"

void	my_mlx_pixel_put(t_data *data, t_point p, int color)
{
	char	*dst;

	if ((SCREEN_WIDTH >= p.x) && (p.x >= 0) && (SCREEN_HEIGHT >= p.y)
		&& (p.y >= 0))
	{
		dst = data->addr + (p.y * data->line_length + p.x
				* (data->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
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

void	draw_line(t_point p0, t_point p1, t_data *data, int c[2])
{
	t_point	d;
	t_point	s;
	float	td;
	float	f;

	init_delta_sign(&d, &s, p0, p1);
	td = d.x + d.y;
	f = 0.;
	while (!(p0.x == p1.x && p0.y == p1.y))
	{
		my_mlx_pixel_put(data, p0, inter_color(c, f / (float)td));
		s.z = d.z;
		if (s.z > -d.x)
		{
			d.z -= d.y;
			p0.x += s.x;
			f += 1.;
		}
		if (s.z < d.y)
		{
			d.z += d.x;
			p0.y += s.y;
			f += 1.;
		}
	}
}
