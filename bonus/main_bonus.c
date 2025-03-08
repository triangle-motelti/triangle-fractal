/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motelti <motelti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 00:25:09 by motelti           #+#    #+#             */
/*   Updated: 2025/03/07 14:57:49 by motelti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol_bonus.h"

int	main(int ac, char **av)
{
	t_fractol	*fractol;

	fractol = (t_fractol *)ft_calloc(1, sizeof(t_fractol));
	if (!fractol)
		return (-1);
	if (ac == 2 || ac == 4)
	{
		mlx_initialize(fractol);
		fractal_initialize(fractol, av);
		mlx_mouse_hook(fractol->win, mouse, fractol);
		mlx_hook(fractol->win, 17, 1L << 2, &clear, fractol);
		mlx_key_hook(fractol->win, key_pressing, fractol);
		mlx_loop(fractol->mlx);
	}
	else if (ac == 3 && ft_strcmp(av[1], "julia") == 0)
		write(1, "./fractol julia [option] [option]\n", 35);
	else
		write(1, "usage : ./fractol mandelbrot\n", 30);
	free(fractol);
	return (0);
}