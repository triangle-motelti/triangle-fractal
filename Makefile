# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: motelti <motelti@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/06 15:45:43 by motelti           #+#    #+#              #
#    Updated: 2025/03/07 01:43:43 by motelti          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# NAME = fractol
# CC = cc -Wall -Wextra -Werror

# MLX =   minilibx-linux/libmlx.a
# SRC = 	fractal/main.c \
# 	  	fractal/mandelbrot.c \
# 		fractal/julia.c \
# 		fractal/fractal.c \
# 		fractal/drawing_fractol.c \
# 		fractal/fractol_key.c \
# 		fractal/ft_putstr_fd.c \
# 		fractal/ft_calloc.c \
# 		fractal/ft_atof.c \
# 		fractal/ft_strcmp.c

# OBJ = $(SRC:.c=.o)
# INC = fractol.h

# all: $(NAME)

# $(NAME): $(OBJ) $(MLX)
# 	$(CC) $(OBJ) $(MLX) -lm -lXext -lX11 -o $(NAME)

# $(MLX):
# 	make -C MLX

# %.o: %.c $(INC)
# 	$(CC) -c $< -o $@

# bonus: all

# clean:
# 	make clean -C MLX
# 	rm -f $(OBJ)

# fclean: clean
# 	rm -f $(NAME)

# re: fclean all


NAME	= fractol
CC		= cc -Wall -Wextra -Werror
MLX_DIR	= minilibx-linux
MLX		= $(MLX_DIR)/libmlx.a

SRC		= fractal/main.c \
		  fractal/mandelbrot.c \
		  fractal/julia.c \
		  fractal/fractal.c \
		  fractal/drawing_fractol.c \
		  fractal/fractol_key.c \
		  fractal/ft_putstr_fd.c \
		  fractal/ft_calloc.c \
		  fractal/ft_atof.c \
		  fractal/ft_strcmp.c

OBJ		= $(SRC:.c=.o)
INC		= fractol.h

all: $(MLX) $(NAME)

$(NAME): $(OBJ)
	$(CC) $^ $(MLX) -lXext -lX11 -lm -o $@

$(MLX):
	@make -s -C $(MLX_DIR)

%.o: %.c $(INC)
	$(CC) -I$(MLX_DIR) -c $< -o $@

bonus: all

clean:
	@make -s -C $(MLX_DIR) clean
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus