/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motelti <motelti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:38:08 by motelti           #+#    #+#             */
/*   Updated: 2025/03/07 02:17:25 by motelti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	clear(t_fractol *f)
{
    mlx_clear_window(f->mlx, f->win);
    mlx_destroy_window(f->mlx, f->win);
    mlx_destroy_display(f->mlx);
    mlx_loop_end(f->mlx);
    free(f->mlx);
    free(f);
    exit(1);
    return (0);
}

void	mlx_initialize(t_fractol	*f)
{
	f->mlx = mlx_init();
	f->win = mlx_new_window(f->mlx, WIDTH, HEIGHT, "motelti");
	f->mask = 0x00F0F0F0;
	f->color = 0x000000FF;
}
void	fractal_initialize(t_fractol *f, char **av)
{
	if (ft_strcmp(av[1], "mandelbrot") == 0 && !av[2])
		mandel(f);
	else if (ft_strcmp(av[1], "julia") == 0)
	{
		if (av[2] && av[3])
			preset_julia(f, ft_atof(av[2]), ft_atof(av[3]));
		else
			julia(f);
	}
	else
	{
		write(1, "usage : ./fractol julia [option] [option] or mandelbrot\n", 57);
		clear(f);
	}
	print_fracal(f);
}


void	print_fracal(t_fractol *f)
{
	if (f->type == 0)
		print_mandel(f);
	else if (f->type == 1)
		print_julia(f);
	else
	{
		write(1, "Can't print fractal\n", 21);
		clear(f);
	}
}
