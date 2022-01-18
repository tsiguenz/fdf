# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/22 16:08:15 by tsiguenz          #+#    #+#              #
#    Updated: 2022/01/18 18:58:58 by tsiguenz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

# Paths

SRC_PATH = srcs/
OBJ_PATH = objs/

# Names

SRC_NAME = init_map.c check_file.c errors.c render_map.c draw_line.c main.c
OBJ_NAME = $(SRC_NAME:.c=.o)

# Files

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))

# Flags

CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBFT = libft/libft.a

# Flags mlx for Linux and MacOS

UNAME=$(shell uname)
ifeq ($(UNAME), Linux)
	MLXFLAGS = -Lmlx -lmlx -L/usr/lib -Imlx -lXext -lX11 -lm -lz
else
	MLXFLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit -lm
endif

$(NAME): $(OBJ)
	@make -C libft/ --no-print-directory
	@make -C mlx/ --no-print-directory
	@echo "Build $(NAME)"
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLXFLAGS) -o $(NAME)
	./fdf | cat -e

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p objs
	@$(CC) $(CFLAGS) -I/usr/include -Imlx -O3 -o $@ -c $<

all: $(NAME)

clean:
	@make clean -C libft/ --no-print-directory
	@echo "Delete fdf/$(OBJ_PATH)"
	@rm -rf $(OBJ_PATH) db

fclean:	clean
	@make fclean -C libft/ --no-print-directory
	@echo "Delete fdf/$(NAME)"
	@rm -f $(NAME) db

db: $(SRC)
	$(CC) $(CFLAGS) -g $(SRC) $(LIBFT) $(MLX) -o $@
	gdb $@

re:	fclean all

.PHONY: all clean fclean re mlx libft db
