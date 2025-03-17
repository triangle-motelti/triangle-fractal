/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motelti <motelti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:38:08 by motelti           #+#    #+#             */
/*   Updated: 2025/03/17 01:41:01 by motelti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol_bonus.h"

int	clear(t_fractol *f)
{
	if (f->img)
		mlx_destroy_image(f->mlx, f->img);
	if (f->win)
	{
		mlx_clear_window(f->mlx, f->win);
		mlx_destroy_window(f->mlx, f->win);
	}
	if (f->mlx)
	{
		mlx_destroy_display(f->mlx);
		free(f->mlx);
	}
	free(f);
	exit(1);
	return (0);
}

void	mlx_initialize(t_fractol	*f)
{
	f->mlx = mlx_init();
	if (!f->mlx)
		clear(f);
	f->win = mlx_new_window(f->mlx, WIDTH, HEIGHT, "motelti");
	if (!f->win)
		clear(f);
	f->img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	if (!f->img)
		clear(f);
	f->addr = mlx_get_data_addr(f->img, &f->bpp, &f->line_len, &f->endian);
	if (!f->addr)
		clear(f);
}

void	fractal_initialize(t_fractol *f, char **av)
{
	if (ft_strcmp(av[1], "mandelbrot") == 0 && !av[2])
		mandel(f);
	else if (ft_strcmp(av[1], "burning_ship") == 0 && !av[2])
		burning_ship(f);
	else if (ft_strcmp(av[1], "julia") == 0)
	{
		if (!av[2])
		{
			ft_putstr_fd("./fractol_bonus mandelbrot || burning_ship ||", 2);
			ft_putstr_fd("./fractol_bonus julia [+/-00.00] [-/+00.00]\n", 2);
			clear(f);
		}
		julia(f);
		{
			f->c_r = ft_atof(av[2]);
			f->c_i = ft_atof(av[3]);
		}
	}
	else
	{
		ft_putstr_fd("./fractol_bonus mandelbrot || burning_ship || ", 2);
		ft_putstr_fd("./fractol_bonus julia [+/-00.00] [-/+00.00]\n", 2);
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
	else if (f->type == 2)
		print_burning_ship(f);
	else
	{
		write(1, "Can't print fractal\n", 21);
		clear(f);
	}
}
