/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkarhan <dkarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 11:54:14 by dkarhan           #+#    #+#             */
/*   Updated: 2022/06/28 14:32:18 by dkarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	my_mlx_pixel_put(t_setpixel *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	put_image_on_window(t_frctl *frctl)
{
	int	x;
	int	y;
	int	n;

	x = 0;
	if (frctl->yes)
	{
		frctl->yes = 0;
		while (x < WIDTH)
		{
			y = 0;
			while (y < HEIGHT)
			{
				frctl->f->cx = map(x, 1000, frctl->f->px_min, frctl->f->px_max);
				frctl->f->cy = map(y, 1000, frctl->f->py_min, frctl->f->py_max);
				n = frctl->f->fractal_func(frctl);
				my_mlx_pixel_put(frctl->img, x, y, frctl->f->coloring_func(n));
				y++;
			}
			x++;
		}
		mlx_put_image_to_window(frctl->mlx, frctl->window, \
		frctl->img->img, 0, 0);
	}
	return (0);
}
