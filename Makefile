# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/22 16:08:15 by tsiguenz          #+#    #+#              #
#    Updated: 2022/02/07 15:00:55 by tsiguenz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

# Paths

SRC_PATH = srcs/
OBJ_PATH = objs/

# Names

SRC_NAME = 	init_map.c \
			check_file.c \
			render_map.c \
			draw_line.c \
			errors.c \
			bresenham.c \
			init_camera.c \
			utils.c \
			main.c

OBJ_NAME = $(SRC_NAME:.c=.o)

# Files

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))

# Flags

CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBFT = libft/libft.a -Ilibft

MLXFLAGS = -Lmlx -lmlx -L/usr/lib -Imlx -lXext -lX11 -lm -lz

all: lib $(NAME)

$(NAME): $(OBJ)
	@echo "Build $(NAME)"
	@$(CC) -g $(CFLAGS) $(OBJ) $(LIBFT) $(MLXFLAGS) -o $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p objs
	@$(CC) -g $(CFLAGS) -I/usr/include -Ilibft -Imlx -o $@ -c $<

lib:
	@make -C libft/ --no-print-directory
	@make -C mlx/ --no-print-directory

clean:
	@make clean -C libft/ --no-print-directory
	@make clean -C mlx/ --no-print-directory
	@echo "Delete fdf/$(OBJ_PATH)"
	@rm -rf $(OBJ_PATH) db

fclean:	clean
	@make fclean -C libft/ --no-print-directory
	@echo "Delete fdf/$(NAME)"
	@rm -f $(NAME) db

re:	fclean all

.PHONY: all clean fclean re lib
