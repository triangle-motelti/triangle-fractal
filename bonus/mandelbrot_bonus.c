/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motelti <motelti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 15:43:41 by motelti           #+#    #+#             */
/*   Updated: 2025/03/17 01:34:27 by motelti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol_bonus.h"

void	mandel(t_fractol *f)
{
	f->type = 0;
	f->max_iter = 100;
	f->zoom = 300;
	f->x_set = -2.1;
	f->y_set = -1.3;
}

static void	draw_mandel(t_fractol *f)
{
	double	z_next;
	double	z_tmp;
	int		i;

	f->c_r = f->x / f->zoom + f->x_set;
	f->c_i = -(f->y / f->zoom + f->y_set);
	f->z_r = 0.0;
	f->z_i = 0.0;
	i = 0;
	z_next = 0.0;
	while (z_next < 4 && i < f->max_iter)
	{
		z_tmp = f->z_r;
		f->z_r = f->z_r * f->z_r - f->z_i * f->z_i + f->c_r;
		f->z_i = 2 * f->z_i * z_tmp - f->c_i;
		z_next = f->z_r * f->z_r + f->z_i * f->z_i;
		i++;
	}
	if (i == f->max_iter)
		pixel_draw(f, 0);
	else
		pixel_draw(f, get_color(i, f));
}

void	print_mandel(t_fractol *f)
{
	f->x = 0;
	while (f->x < WIDTH)
	{
		f->y = 0;
		while (f->y < HEIGHT)
		{
			draw_mandel(f);
			f->y++;
		}
		f->x++;
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
}
