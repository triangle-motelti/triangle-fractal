/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_fractol.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motelti <motelti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 02:52:53 by motelti           #+#    #+#             */
/*   Updated: 2025/03/16 22:06:27 by motelti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	get_color(int iter, t_fractol *f)
{
	double	t;
	int		r;
	int		g;
	int		b;

	if (iter == f->max_iter)
		return (0);
	t = (double)iter / f->max_iter;
	r = (int)(sin(5 * t + 0) * 127 + 128);
	g = (int)(sin(5 * t + 2) * 127 + 128);
	b = (int)(sin(5 * t + 4) * 127 + 128);
	return ((r << 16) | (g << 8) | b);
}

void	zoom(int x, int y, t_fractol *f)
{
	f->x_set = (x / f->zoom + f->x_set) - (x / (f->zoom * 1.5));
	f->y_set = (y / f->zoom + f->y_set) - (y / (f->zoom * 1.5));
	f->zoom *= 1.5;
}

void	unzoom(int x, int y, t_fractol *f)
{
	f->x_set = (x / f->zoom + f->x_set) - (x / (f->zoom / 1.5));
	f->y_set = (y / f->zoom + f->y_set) - (y / (f->zoom / 1.5));
	f->zoom /= 1.5;
}

void	pixel_draw(t_fractol *f, int color)
{
	char	*dst;

	dst = f->addr + (f->y * f->line_len + f->x * (f->bpp / 8));
	*(unsigned int *)dst = color;
}
