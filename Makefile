# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/22 16:08:15 by tsiguenz          #+#    #+#              #
#    Updated: 2021/12/30 14:56:47 by tsiguenz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
UNAME=$(shell uname)

# Paths

SRC_PATH = srcs/
OBJ_PATH = objs/

# Names

SRC_NAME = parse.c
OBJ_NAME = $(SRC_NAME:.c=.o)

# Files

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))

# Flags

CC = gcc
#CFLAGS = -Wall -Wextra -Werror
LIBFT = libft/libft.a
ifeq ($(UNAME), Linux)
	MLX = -Lmlx -lmlx -L/usr/lib -Imlx -lXext -lX11 -lm -lz
else
	MLX = -Lmlx -lmlx -framework OpenGL -framework AppKit -lm
endif

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(LIBFT) $(MLX) -o $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	mkdir -p objs
	$(CC) $(CFLAGS) -I/usr/include -Imlx -O3 -o $@ -c $<

all: obj mlx libft $(NAME)

obj:
	@mkdir -p $(OBJ_PATH)

libft:
	@make -C libft/

mlx:
	@make -C mlx/

clean:
	make clean -C libft/
	make clean -C mlx/
	rm -rf $(OBJ_PATH)

fclean:	clean
	make fclean -C libft/
	rm -f $(NAME)

re:	fclean all

debug: $(OBJ)
	$(CC) -ggdb $(OBJ) $(MLX) -o $(NAME)
	
.PHONY: all clean fclean re obj mlx libft
