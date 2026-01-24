/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaddi <zaddi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 15:04:15 by zaddi             #+#    #+#             */
/*   Updated: 2026/01/24 16:25:26 by zaddi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FDF_H
# define FT_FDF_H

# include "ft_printf.h"
# include "get_next_line.h"
# include "libft.h"
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

#endif
