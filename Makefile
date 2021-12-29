# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/22 16:08:15 by tsiguenz          #+#    #+#              #
#    Updated: 2021/12/29 23:29:49 by tsiguenz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
UNAME=$(shell uname)

# Paths

SRC_PATH = srcs/
OBJ_PATH = objs/

# Names

SRC_NAME = get_next_line.c get_next_line_utils.c  parse.c
OBJ_NAME = $(SRC_NAME:.c=.o)

# Files

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))

# Flags

CC = gcc
#CFLAGS = -Wall -Wextra -Werror 
ifeq ($(UNAME), Linux)
	MLX = -Lmlx -lmlx -L/usr/lib -Imlx -lXext -lX11 -lm -lz
else
	MLX = -Lmlx -lmlx -framework OpenGL -framework AppKit -lm
endif

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(MLX) -o $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	$(CC) $(CFLAGS) -g -I/usr/include -Imlx -O3 -o $@ -c $<

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

debug: $(OBJ)
	$(CC) -ggdb $(OBJ) $(MLX) -o $(NAME)
	
.PHONY: all clean fclean re
