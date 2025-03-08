/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_key_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motelti <motelti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 01:46:15 by motelti           #+#    #+#             */
/*   Updated: 2025/03/08 01:22:04 by motelti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol_bonus.h"

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

int	key_pressing(int key, t_fractol *f)
{
	if (key == KEY_ESC)
		clear(f);
	else if (key == KEY_LAR)
		f->x_set -= 10.0 / f->zoom;
	else if (key == KEY_RAR)
		f->x_set += 10.0 / f->zoom;
	else if (key == KEY_UAR)
		f->y_set -= 10.0 / f->zoom;
	else if (key == KEY_DAR)
		f->y_set += 10.0 / f->zoom;
	else if (key == KEY_S)
        f->color_shift += 0.1;
	print_fracal(f);
	return (0);
}

