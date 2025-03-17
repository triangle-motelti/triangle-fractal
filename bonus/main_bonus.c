/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motelti <motelti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 00:25:09 by motelti           #+#    #+#             */
/*   Updated: 2025/03/16 13:34:49 by motelti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol_bonus.h"

static	void	check_arg(int i, t_fractol *f)
{
	if (i == 0 || i == 3)
	{
		ft_putstr_fd("gg./fractol_bonus mandelbrot || burning_ship ||", 2);
		ft_putstr_fd("./fractol_bonus julia [+/-00.00] [-/+00.00]\n", 2);
	}
	else if (i == 1 || i == 2)
	{
		ft_putstr_fd("./fractol_bonus mandelbrot || burning_ship ||", 2);
		ft_putstr_fd("./fractol_bonus julia [+/-00.00] [-/+00.00]\n", 2);
	}
	if (f)
		clear(f);
}

static	void	args(int ac, char **av, t_fractol *fractol)
{
	if (ac < 2)
		check_arg(1, fractol);
	if ((ft_strcmp(av[1], "mandelbrot") == 0))
	{
		if (ac != 2)
			check_arg(2, fractol);
	}
	else if ((ft_strcmp(av[1], "burning_ship") == 0))
	{
		if (ac != 2)
			check_arg(2, fractol);
	}
	else if (ft_strcmp(av[1], "julia") == 0)
	{
		if (ac != 4)
			check_arg(3, fractol);
	}
	else
		check_arg(0, fractol);
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
	args(ac, av, fractol);
	if (ac == 4)
	{
		julia_checker(av[2], fractol);
		julia_checker(av[3], fractol);
	}
	if (ac == 2 || ac == 4)
		init(av, fractol);
	free(fractol);
	return (0);
}
