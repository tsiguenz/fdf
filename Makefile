# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/22 16:08:15 by tsiguenz          #+#    #+#              #
#    Updated: 2021/12/27 20:30:49 by tsiguenz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
SRC = *.c
OBJ = $(SRC:.c=.o)
CC = gcc
#CFLAGS = -Wall -Wextra -Werror
UNAME=$(shell uname)
%.o:
    ifeq ($(UNAME), Linux)
		$(CC) $(CFLAGS) -Imlx -O3 -c $(SRC)
    else
		$(CC) $(CFLAGS) -Imlx -O3 -c $(SRC)
    endif
$(NAME): $(OBJ)
    ifeq ($(UNAME), Linux)
		$(CC) $(OBJ) -Lmlx -lmlx -L/usr/lib -Imlx -lXext -lX11 -lm -lz -o $(NAME)
    else
		$(CC) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)	
    endif
	
all: $(NAME)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
