/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkarhan <dkarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 11:54:09 by dkarhan           #+#    #+#             */
/*   Updated: 2022/06/28 12:54:23 by dkarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

double	map(double value, double from_high, double min, double max)
{
	return (min + ((max - min) * (value / from_high)));
}

void	set_fractal_x(t_frctl *ptr, double x_min, double x_max)
{
	ptr->f->px_min = x_min;
	ptr->f->px_max = x_max;
}

void	set_fractal_y(t_frctl *ptr, double y_min, double y_max)
{
	ptr->f->py_min = y_min;
	ptr->f->py_max = y_max;
}

int	keyhandler(int keycode, t_frctl *frctl)
{
	if (keycode == 8)
		t_deneme(frctl->f);
	else if (keycode == 53)
		close_exit(frctl);
	else if (keycode == 123)
		set_fractal_x(frctl, frctl->f->px_min - 0.05, frctl->f->px_max - 0.05);
	else if (keycode == 124)
		set_fractal_x(frctl, frctl->f->px_min + 0.05, frctl->f->px_max + 0.05);
	else if (keycode == 125)
		set_fractal_y(frctl, frctl->f->py_min + 0.05, frctl->f->py_max + 0.05);
	else if (keycode == 126)
		set_fractal_y(frctl, frctl->f->py_min - 0.05, frctl->f->py_max - 0.05);
	frctl->yes = 1;
	return (0);
}

int	mouse_handler(int keycode, int x, int y, t_frctl *frctl)
{
	double	map_x;
	double	map_y;

	if (keycode == 5)
	{
		map_x = map(x, WIDTH, frctl->f->px_min, frctl->f->px_max);
		map_y = map(y, HEIGHT, frctl->f->py_min, frctl->f->py_max);
		frctl->f->px_min = map_x + ((frctl->f->px_min - map_x) / 1.3);
		frctl->f->px_max = map_x + ((frctl->f->px_max - map_x) / 1.3);
		frctl->f->py_min = map_y + ((frctl->f->py_min - map_y) / 1.3);
		frctl->f->py_max = map_y + ((frctl->f->py_max - map_y) / 1.3);
		frctl->yes = 1;
	}
	else if (keycode == 4)
	{
		map_x = map(x, WIDTH, frctl->f->px_min, frctl->f->px_max);
		map_y = map(y, HEIGHT, frctl->f->py_min, frctl->f->py_max);
		frctl->f->px_min = map_x + ((frctl->f->px_min - map_x) / 0.7);
		frctl->f->px_max = map_x + ((frctl->f->px_max - map_x) / 0.7);
		frctl->f->py_min = map_y + ((frctl->f->py_min - map_y) / 0.7);
		frctl->f->py_max = map_y + ((frctl->f->py_max - map_y) / 0.7);
		frctl->yes = 1;
	}
	return (0);
}
