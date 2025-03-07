/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_fractol.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motelti <motelti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 02:52:53 by motelti           #+#    #+#             */
/*   Updated: 2025/03/06 02:54:40 by motelti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

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