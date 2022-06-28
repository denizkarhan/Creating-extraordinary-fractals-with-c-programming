/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkarhan <dkarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 11:53:58 by dkarhan           #+#    #+#             */
/*   Updated: 2022/06/28 14:32:15 by dkarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	check_args(char *ptr);
int	close_exit(t_frctl *vars);

int	main(int ac, char **av)
{
	t_frctl			frctl;
	t_setpixel		images;
	t_setfractals	*f;

	if (ac != 2 || !check_args(av[1]))
		close_exit(NULL);
	frctl.mlx = mlx_init();
	frctl.window = mlx_new_window(frctl.mlx, WIDTH, HEIGHT, "Fractol");
	frctl.yes = 1;
	images.img = mlx_new_image(frctl.mlx, WIDTH, HEIGHT);
	images.addr = mlx_get_data_addr(images.img, &images.bits_per_pixel, \
	&images.line_length, &images.endian);
	frctl.img = &images;
	f = fractol_element(av[1]);
	t_deneme(f);
	frctl.f = f;
	mlx_hook(frctl.window, 2, 1L << 0, keyhandler, &frctl);
	mlx_hook(frctl.window, 17, 0, close_exit, &frctl);
	mlx_mouse_hook(frctl.window, mouse_handler, &frctl);
	put_image_on_window(&frctl);
	mlx_loop_hook(frctl.mlx, put_image_on_window, &frctl);
	mlx_loop(frctl.mlx);
}

int	check_args(char *ptr)
{
	if (!ft_strncmp(ptr, "mandelbar", 9) || !ft_strncmp(ptr, "mandelbrot", 10)
		|| !ft_strncmp(ptr, "julia1", 6) || !ft_strncmp(ptr, "julia2", 6)
		|| !ft_strncmp(ptr, "julia3", 6) || !ft_strncmp(ptr, "burningship", 11))
		return (1);
	return (0);
}

int	close_exit(t_frctl *vars)
{
	if (vars)
	{
		mlx_destroy_window(vars->mlx, vars->window);
		free(vars->f);
	}
	else
	{
		printf("\nWrong Login! -> ./fractol fractol_name\n");
		printf("----------------Fractals----------------\n");
		printf("mandelbrot\n");
		printf("mandelbar\n");
		printf("burningship\n");
		printf("julia1\n");
		printf("julia2\n");
		printf("julia3\n");
	}
	exit(0);
	return (1);
}
