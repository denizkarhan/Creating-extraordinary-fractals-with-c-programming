/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkarhan <dkarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 11:54:12 by dkarhan           #+#    #+#             */
/*   Updated: 2022/06/28 12:54:22 by dkarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	mandelbrot(t_frctl *ptr)
{
	int		n;
	double	x;
	double	y;
	double	x2;
	double	y2;

	n = 0;
	x = 0;
	y = 0;
	x2 = 0;
	y2 = 0;
	while (x2 + y2 <= 4 && n < MAXITER)
	{
		y = 2 * x * y + ptr->f->cy;
		x = x2 - y2 + ptr->f->cx;
		y2 = y * y;
		x2 = x * x;
		n++;
	}
	return (n);
}

int	burningship(t_frctl *ptr)
{
	int		n;
	double	x;
	double	y;
	double	x2;
	double	y2;

	n = 0;
	x = 0;
	y = 0;
	x2 = 0;
	y2 = 0;
	while (x2 + y2 <= 4 && n < MAXITER)
	{
		y = fabs(2 * x * y) + ptr->f->cy;
		x = x2 - y2 + ptr->f->cx;
		x2 = x * x;
		y2 = y * y;
		n++;
	}
	return (n);
}

int	mandelbar(t_frctl *ptr)
{
	int		n;
	double	x;
	double	y;
	double	x2;
	double	y2;

	n = 0;
	x = 0;
	y = 0;
	x2 = 0;
	y2 = 0;
	while (x2 + y2 <= 4 && n < MAXITER)
	{
		y = -2 * x * y + ptr->f->cy;
		x = x2 - y2 + ptr->f->cx;
		x2 = x * x;
		y2 = y * y;
		n++;
	}
	return (n);
}

int	julia(t_frctl *ptr)
{
	double	temp;
	double	cx;
	double	cy;
	int		n;

	cx = ptr->f->cx;
	cy = ptr->f->cy;
	n = 0;
	while (cx * cx + cy * cy <= 64 && n < MAXITER)
	{
		temp = cx * cx - cy * cy;
		cy = 2 * cx * cy + ptr->f->offsety;
		cx = temp + ptr->f->offsetx;
		n++;
	}
	return (n);
}
