/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkarhan <dkarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 11:54:05 by dkarhan           #+#    #+#             */
/*   Updated: 2022/06/28 14:26:22 by dkarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int color1(int n)
{
	int color;

	if (n <= 75)
	{
		color = map(n, 75 / n, 0, 255);
		return (get_trgb(0, 0, 0, 3 * color / 2));
	}
	else if (n <= 150)
	{
		color = map(n - 75, 75, 0, 255);
		return (get_trgb(0, 255, 3 * color, 12 * color / 5));
	}
	else
	{
		color = map(n - 150, 75, 0, 255);
		return (get_trgb(0, 0, 0, color / 3));
	}
}

int color2(int n)
{
	int color;

	if (n <= 33)
	{
		color = map(n, 33, 0, 255);
		return (get_trgb(0, color, 0, 0));
	}
	else if (n <= 66)
	{
		color = map(n - 33, 33, 0, 255);
		return (get_trgb(0, 255, color, 0));
	}
	else
	{
		color = map(n - 66, 33, 0, 255);
		return (get_trgb(0, 255, 255, color));
	}
}

int color3(int n)
{
	int color;

	if (n <= 42)
	{
		color = map(n, 33, 0, 255);
		return (get_trgb(0, 0, color, color / 10));
	}
	else if (n <= 84)
	{
		color = map(n - 42, 33, 0, 255);
		return (get_trgb(0, 0, color, color / 2));
	}
	else
	{
		color = map(n - 84, 33, 0, 255);
		return (get_trgb(0, 4 * color / 3, 1234, 0.8 * color));
	}
}

uint32_t get_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int t_deneme(t_setfractals *new)
{
	static int i;

	i++;
	if (i % 3 == 1)
		new->coloring_func = color1;
	else if (i % 3 == 2)
		new->coloring_func = color2;
	else
		new->coloring_func = color3;
	return (0);
}
