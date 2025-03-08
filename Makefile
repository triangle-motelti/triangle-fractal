# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: motelti <motelti@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/06 15:45:43 by motelti           #+#    #+#              #
#    Updated: 2025/03/08 00:39:52 by motelti          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = fractol
BONUS = fractol_bonus
CC = cc
CFLAGS	= -Wall -Werror -Wextra

HEADER = fractol.h
HEADER_BONUS = fractol_bonus.h

MLX = minilibx-linux/libmlx.a
SRC = fractal/main.c \
	fractal/mandelbrot.c \
	fractal/julia.c \
	fractal/fractal.c \
	fractal/drawing_fractol.c \
	fractal/fractol_key.c \
	fractal/ft_putstr_fd.c \
	fractal/ft_calloc.c \
	fractal/ft_atof.c \
	fractal/ft_strcmp.c
	  
BONUS_SRC = bonus/main_bonus.c \
	bonus/mandelbrot_bonus.c \
	bonus/julia_bonus.c \
	bonus/fractal_bonus.c \
	bonus/drawing_fractol_bonus.c \
	bonus/fractol_key_bonus.c \
	bonus/ft_putstr_fd_bonus.c \
	bonus/ft_calloc_bonus.c \
	bonus/ft_atof_bonus.c \
	bonus/ft_strcmp_bonus.c

OBJ = $(SRC:.c=.o)
BONUS_OBJ = $(BONUS_SRC:.c=.o)

all: $(NAME) clean
bonus: $(BONUS) clean

$(NAME): $(OBJ) $(MLX) 
	$(CC) $(CFLAGS) $(OBJ) $(MLX) -Imlx_linux -lm -lXext -lX11 -lz -o $(NAME)

$(BONUS): $(BONUS_OBJ) $(MLX)
	$(CC) $(CFLAGS) $(BONUS_OBJ) $(MLX) -Imlx_linux -lm -lXext -lX11 -lz -o $(BONUS)

$(MLX):
	make -C minilibx-linux

%.o: %.c $(HEADER) $(HEADER_BONUS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make clean -C minilibx-linux
	rm -f $(OBJ) $(BONUS_OBJ)

fclean: clean
	rm -f $(NAME) $(BONUS)

re: fclean all


