/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motelti <motelti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 00:19:19 by motelti           #+#    #+#             */
/*   Updated: 2025/03/07 01:20:45 by motelti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "minilibx-linux/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <math.h>

# define WIDTH 900
# define HEIGHT 900

# define KEY_ESC	65307
# define KEY_LAR	65361
# define KEY_RAR	65363
# define KEY_UAR	65362
# define KEY_DAR	65364
# define KEY_PLUS	65451
# define KEY_MINU	65453
# define KEY_SPC	32
# define KEY_Z		122
# define KEY_X		120
# define KEY_ONE	65436
# define KEY_TWO	65433
# define KEY_TREE	65435
# define KEY_FOUR	65430
# define KEY_FIVE	65437
# define KEY_SIX	65432
# define KEY_SEVEN	65429
# define KEY_EIGHT	65431
# define KEY_NINE	65434
# define KEY_ZERO	65438
# define KEY_W		119
# define KEY_A		97
# define KEY_S		115
# define KEY_D		100

# define KEY_F1		65470
# define KEY_F2		65471
# define KEY_F3		65472
# define KEY_F4		65473

# define KEY_F5		65474
# define KEY_F6		65475
# define KEY_F7		65476
# define KEY_F8		65477

# define KEY_F9		65478
# define KEY_F10	65479
# define KEY_F11	65480
# define KEY_F12	65481

typedef struct s_fractol {
	void	*mlx;
	void	*win;
	void	*img;
	void	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		type;
	int		color;
	int		mask;
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
void	color(int key, t_fractol *f);
void	switch_key(int key, t_fractol *f);
void	julia_key(int key, t_fractol *f);
int		key_pressing(int key, t_fractol *f);

void	zoom(int x, int y, t_fractol *f);
void	unzoom(int x, int y, t_fractol *f);
void	pixel_draw(t_fractol *f, int color);

void	julia(t_fractol *f);
void	preset_julia(t_fractol *f, double rl, double imgn);
void	print_julia(t_fractol *f);

void	mandel(t_fractol *f);
void	print_mandel(t_fractol *f);

int 	ft_strcmp(const char *s1, const char *s2);
void	*ft_calloc(size_t count, size_t size);
int		ft_putstr_fd(char *s, int fd);
double	ft_atof(const char *str);

#endif