/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motelti <motelti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 00:25:09 by motelti           #+#    #+#             */
/*   Updated: 2025/03/15 12:19:14 by motelti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static	void	flag(int ac, char **av, t_fractol *f)
{
	if (ac < 2)
		ft_putstr_fd("./fractol mandelbrot or julia [+/-00.00] [-/+00.00]\n", 1);
	else if (ac == 2 && !ft_strcmp(av[1], "julia"))
		ft_putstr_fd("./fractol mandelbrot or julia [+/-00.00] [-/+00.00]\n", 1);
	else if (ac != 2 && !ft_strcmp(av[1], "mandelbrot"))
		ft_putstr_fd("./fractol mandelbrot or julia [+/-00.00] [-/+00.00]\n", 1);
	else if (ac != 4 && !ft_strcmp(av[1], "julia"))
		ft_putstr_fd("./fractol mandelbrot or julia [+/-00.00] [-/+00.00]\n", 1);
	else
		ft_putstr_fd("./fractol mandelbrot or julia [+/-00.00] [-/+00.00]\n", 1);
	clear(f);
}

static	void	init(char **av, t_fractol *fractol)
{
	mlx_initialize(fractol);
	fractal_initialize(fractol, av);
	mlx_mouse_hook(fractol->win, mouse, fractol);
	mlx_hook(fractol->win, 17, 1L << 2, &clear, fractol);
	mlx_key_hook(fractol->win, key_pressing, fractol);
	mlx_loop(fractol->mlx);
}

int	main(int ac, char **av)
{
	t_fractol	*fractol;

	fractol = (t_fractol *)ft_calloc(1, sizeof(t_fractol));
	if (!fractol)
		return (-1);
	if (ac == 4)
	{
		julia_checker(av[2], fractol);
		julia_checker(av[3], fractol);
	}
	if (ac < 2 || (ft_strcmp(av[1], "mandelbrot") && ft_strcmp(av[1], "julia")
		) || (!ft_strcmp(av[1], "mandelbrot") && ac != 2) || (
			!ft_strcmp(av[1], "julia") && ac != 4))
	{
		flag(ac, av, fractol);
		return (0);
	}
	else if (ac == 2 || ac == 4)
	{
		init(av, fractol);
	}
	free(fractol);
	return (0);
}
