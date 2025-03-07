/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_key.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motelti <motelti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 01:46:15 by motelti           #+#    #+#             */
/*   Updated: 2025/03/07 01:48:23 by motelti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	mouse(int button, int x, int y, t_fractol *f)
{
	if (button == 4)
		zoom(x, y, f);
	else if (button == 5)
		unzoom(x, y, f);
	else if (button == 1)
	{
		f->c_r = (x - (double)WIDTH / 2) / (f->zoom);
		f->c_i = (y - (double)HEIGHT / 2) / (f->zoom);
	}
	print_fracal(f);
	return (0);
}

void	color(int key, t_fractol *f)
{
	if (key == KEY_ONE)
		f->color = 0x00FF0000;
	else if (key == KEY_TWO)
		f->color = 0x0000FF00;
	else if (key == KEY_TREE)
		f->color = 0x000000F;
	else if (key == KEY_FOUR)
		f->color = 0x00FFFFFF;
	else if (key == KEY_FIVE)
		f->color = 0x00FFFF00;
	else if (key == KEY_SIX)
		f->color = 0x0000FFFF;
	else if (key == KEY_SEVEN)
		f->color = 0x00FF00FF;
	else if (key == KEY_EIGHT)
		f->color = 0x0000FFF0;
	else if (key == KEY_NINE)
		f->color = 0x00FF7F7f;
}

void	switch_key(int key, t_fractol *f)
{
	if (key == KEY_ZERO)
	{
		if (f->mask == 0x00000000)
			f->mask = 0x000F0F0F;
		else if (f->mask == 0x000F0F0F)
			f->mask = 0x00F0F0F0;
		else
			f->mask = 0x00000000;
	}
	else if (key == KEY_SPC)
	{
		if (f->type == 0)
			julia(f);
		else
			mandel(f);
	}
}

void	julia_key(int key, t_fractol *f)
{
	if (key == KEY_F1)
		preset_julia(f, 0.285, 0.01);
	else if (key == KEY_F2)
		preset_julia(f, -0.4, 0.6);
	else if (key == KEY_F3)
		preset_julia(f, -0.70176, -0.3842);
	else if (key == KEY_F4)
		preset_julia(f, -0.835, -0.2321);
	else if (key == KEY_F5)
		preset_julia(f, -0.8, 0.156);
	else if (key == KEY_F6)
		preset_julia(f, -0.7269, 0.1889);
	else if (key == KEY_F7)
		preset_julia(f, 0.0, -0.8);
	else if (key == KEY_F8)
		preset_julia(f, -0.63, 0.67);
	else if (key == KEY_F9)
		preset_julia(f, 0.35, 0.05);
	else if (key == KEY_F10)
		preset_julia(f, -0.76, 0.12);
	else if (key == KEY_F11)
		preset_julia(f, -0.1222, 0.7444);
	else if (key == KEY_F12)
		preset_julia(f, -1.0, 0.0);
}

int	key_pressing(int key, t_fractol *f)
{
	if (key == KEY_ESC)
		clear(f);
	else if (key == KEY_LAR || key == KEY_A)
		f->x_set -= 10.0 / f->zoom;
	else if (key == KEY_RAR || key == KEY_D)
		f->x_set += 10.0 / f->zoom;
	else if (key == KEY_UAR || key == KEY_W)
		f->y_set -= 10.0 / f->zoom;
	else if (key == KEY_DAR || key == KEY_S)
		f->y_set += 10.0 / f->zoom;
	else if (key == KEY_Z)
		zoom((WIDTH / 2), (HEIGHT / 2), f);
	else if (key == KEY_X)
		unzoom((WIDTH / 2), (HEIGHT / 2), f);
	else if (key == KEY_PLUS)
		f->max_iter += 10;
	else if (key == KEY_MINU)
		f->max_iter -= 10;
	switch_key(key, f);
	julia_key(key, f);
	color(key, f);
	print_fracal(f);
	return (0);
}

