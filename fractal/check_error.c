/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motelti <motelti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 14:25:39 by motelti           #+#    #+#             */
/*   Updated: 2025/03/14 22:18:00 by motelti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static	int	checker(char *s)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (s[i])
	{
		if (s[i] == '.')
			c++;
		i++;
	}
	return (c);
}

static	int	check_number(char *s, int *i)
{
	int	d;
	int	n;

	n = 0;
	d = 0;
	while (s[*i] && s[*i] != ' ')
	{
		if (s[*i] == '.')
		{
			if (d)
				return (0);
			d = 1;
		}
		else if (s[*i] >= '0' && s[*i] <= '9')
			n++;
		else
			return (0);
		(*i)++;
	}
	if (n == 0)
		return (0);
	return (1);
}

static	int	is_number(char *s)
{
	int	i;

	i = 0;
	while (s[i] == ' ')
		i++;
	if (s[i] == '-' || s[i] == '+')
		i++;
	if (!check_number(s, &i))
		return (0);
	while (s[i] == ' ')
		i++;
	return (s[i] == '\0');
}

void	julia_checker(char *s, t_fractol *f)
{
	if ((is_number(s)) == 0)
	{
		ft_putstr_fd("./fractol mandelbrot ", 1);
		ft_putstr_fd("./fractol julia [+/-00.00] [-/+00.00]\n", 1);
		clear(f);
	}
	if ((checker(s) > 1))
	{
		ft_putstr_fd("./fractol mandelbrot ", 1);
		ft_putstr_fd("./fractol julia [+/-00.00] [-/+00.00]\n", 1);
		clear(f);
	}
}
