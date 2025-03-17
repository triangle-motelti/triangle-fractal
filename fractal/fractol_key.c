/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_key.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motelti <motelti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 01:46:15 by motelti           #+#    #+#             */
/*   Updated: 2025/03/14 12:12:30 by motelti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	mouse(int button, int x, int y, t_fractol *f)
{
	(void)x;
	(void)y;
	if (button == 4)
		zoom(WIDTH / 2, HEIGHT / 2, f);
	else if (button == 5)
		unzoom(WIDTH / 2, HEIGHT / 2, f);
	print_fracal(f);
	return (0);
}

int	key_pressing(int key, t_fractol *f)
{
	if (key == KEY_ESC)
		clear(f);
	print_fracal(f);
	return (0);
}
