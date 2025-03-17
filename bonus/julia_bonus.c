/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motelti <motelti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 15:24:06 by motelti           #+#    #+#             */
/*   Updated: 2025/03/17 01:34:44 by motelti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol_bonus.h"

void	julia(t_fractol *f)
{
	f->type = 1;
	f->max_iter = 100;
	f->zoom = 300;
	f->x_set = -1.5;
	f->y_set = -1.4;
}

static void	draw_julia(t_fractol *f)
{
	double	z_next;
	double	z_rtmp;
	int		i;

	f->z_r = (f->x / f->zoom + f->x_set);
	f->z_i = (f->y / f->zoom + f->y_set);
	z_next = f->z_r * f->z_r + f->z_i * f->z_i;
	i = 0;
	while (z_next < 4 && i < f->max_iter)
	{
		z_rtmp = f->z_r * f->z_r - f->z_i * f->z_i;
		f->z_i = 2 * f->z_r * f->z_i + f->c_i;
		f->z_r = z_rtmp + f->c_r;
		z_next = f->z_r * f->z_r + f->z_i * f->z_i;
		i++;
	}
	if (i == f->max_iter)
		pixel_draw(f, 0);
	else
		pixel_draw(f, get_color(i, f));
}

void	print_julia(t_fractol *f)
{
	f->x = 0;
	while (f->x < WIDTH)
	{
		f->y = 0;
		while (f->y < HEIGHT)
		{
			draw_julia(f);
			f->y++;
		}
		f->x++;
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
}
