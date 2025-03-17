/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motelti <motelti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 00:19:19 by motelti           #+#    #+#             */
/*   Updated: 2025/03/16 13:28:40 by motelti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <mlx.h>

# define WIDTH 900
# define HEIGHT 900

# define KEY_ESC	65307

typedef struct s_fractol {
	void	*mlx;
	void	*win;
	void	*img;
	void	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		type;
	int		x;
	int		y;
	int		max_iter;
	double	zoom;
	double	c_r;
	double	c_i;
	double	z_r;
	double	z_i;
	double	x_set;
	double	y_set;
}				t_fractol;

int		clear(t_fractol *f);
void	print_fracal(t_fractol *f);
void	mlx_initialize(t_fractol	*f);
void	fractal_initialize(t_fractol *f, char **av);

int		mouse(int button, int x, int y, t_fractol *f);
int		key_pressing(int key, t_fractol *f);

void	zoom(int x, int y, t_fractol *f);
void	unzoom(int x, int y, t_fractol *f);
void	pixel_draw(t_fractol *f, int color);
int		get_color(int iter, t_fractol *f);

void	julia(t_fractol *f);
void	print_julia(t_fractol *f);
void	julia_checker(char *s, t_fractol *f);

void	mandel(t_fractol *f);
void	print_mandel(t_fractol *f);

int		ft_strcmp(const char *s1, const char *s2);
void	*ft_calloc(size_t count, size_t size);
int		ft_putstr_fd(char *s, int fd);
double	ft_atof(const char *str);

#endif
