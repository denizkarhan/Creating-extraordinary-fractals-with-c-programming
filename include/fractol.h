/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkarhan <dkarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 11:54:19 by dkarhan           #+#    #+#             */
/*   Updated: 2022/06/28 14:33:01 by dkarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "../mlx/mlx.h"
# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# define MAXITER 10000
# define HEIGHT 1000
# define WIDTH 1000

typedef struct s_frctl	t_frctl;

typedef struct s_setpixel
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_setpixel;

typedef struct s_setfractals
{
	double		px_min;
	double		px_max;
	double		py_min;
	double		py_max;
	double		cx;
	double		cy;
	double		offsetx;
	double		offsety;
	int			(*fractal_func)(struct s_frctl *);
	int			(*coloring_func)(int);
}	t_setfractals;

typedef struct s_frctl
{
	void			*mlx;
	void			*window;
	int				yes;
	t_setpixel		*img;
	t_setfractals	*f;
}	t_frctl;

t_setfractals	*fractol_element(char *ptr);
void			fractol_element2(t_setfractals *ptr, char *str);
double			map(double value, double from_high, double min, double max);
void			my_mlx_pixel_put(t_setpixel *data, int x, int y, int color);
void			set_fractal_x(t_frctl *ptr, double x_min, double x_max);
void			set_fractal_y(t_frctl *ptr, double y_min, double y_max);
int				t_deneme(t_setfractals *new);
int				put_image_on_window(t_frctl *frctl);
int				close_exit(t_frctl *frctl);
int				check_args(char *ptr);
int				keyhandler(int keycode, t_frctl *frctl);
int				mouse_handler(int keycode, int x, int y, t_frctl *frctl);
int				ft_strncmp(const char *s1, const char *s2, unsigned int n);
int				ft_strlen(char *ptr);
int				color1(int n);
int				color2(int n);
int				color3(int n);
uint32_t		get_trgb(int t, int r, int g, int b);
int				mandelbrot(t_frctl *ptr);
int				mandelbar(t_frctl *ptr);
int				burningship(t_frctl *ptr);
int				julia(t_frctl *ptr);

#endif
