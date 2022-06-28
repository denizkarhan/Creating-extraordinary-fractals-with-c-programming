/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_element.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkarhan <dkarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 11:54:16 by dkarhan           #+#    #+#             */
/*   Updated: 2022/06/28 12:54:21 by dkarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	fractol_element2(t_setfractals *ptr, char *str)
{
	ptr->fractal_func = julia;
	if (!ft_strncmp("julia2", str, 6))
	{
		ptr->offsetx = -0.4;
		ptr->offsety = 0.6;
	}
	else if (!ft_strncmp("julia3", str, 6))
	{
		ptr->offsetx = 0.285;
		ptr->offsety = 0.01;
	}
	else if (!ft_strncmp("mandelbar", str, 9))
		ptr->fractal_func = mandelbar;
}

t_setfractals	*fractol_element(char *ptr)
{
	t_setfractals	*new;

	new = malloc(sizeof(t_setfractals));
	new->px_max = 2;
	new->py_max = 2;
	new->px_min = -2;
	new->py_min = -2;
	if (!ft_strncmp("mandelbrot", ptr, 10))
		new->fractal_func = mandelbrot;
	else if (!ft_strncmp("julia1", ptr, 6))
	{
		new->fractal_func = julia;
		new->offsetx = -0.835;
		new->offsety = -0.232;
	}
	else if (!ft_strncmp("burningship", ptr, 11))
		new->fractal_func = burningship;
	else
		fractol_element2(new, ptr);
	return (new);
}
