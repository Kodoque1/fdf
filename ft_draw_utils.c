/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaddi <zaddi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 16:04:11 by zaddi             #+#    #+#             */
/*   Updated: 2026/02/12 12:31:00 by zaddi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void	my_mlx_pixel_put(t_data *data, t_point p, int color)
{
	char	*dst;

	if ((p.x >= 0) && (p.x < SCREEN_WIDTH) && (p.y >= 0)
		&& (p.y < SCREEN_HEIGHT))
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
	int		steps;
	int		i;
	float	f;

	init_delta_sign(&d, &s, p0, p1);
	steps = ft_abs(p1.x - p0.x);
	if (ft_abs(p1.y - p0.y) > steps)
		steps = ft_abs(p1.y - p0.y);
	i = 0;
	while (!(p0.x == p1.x && p0.y == p1.y))
	{
		if (steps == 0)
			f = 1.0f;
		else
			f = (float)i / (float)steps;
		my_mlx_pixel_put(data, p0, interpolate(c, f));
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
		i++;
	}
	my_mlx_pixel_put(data, p1, c[1]);
}
