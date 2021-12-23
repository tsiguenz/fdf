# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/22 16:08:15 by tsiguenz          #+#    #+#              #
#    Updated: 2021/12/23 13:28:28 by tsiguenz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
SRC = *.c
OBJ = $(SRC:.c=.o)
CC = gcc
#CFLAGS = -Wall -Wextra -Werror

%.o:
	$(CC) $(CFLAGS) -I/usr/include -Imlx -O3 -c $(SRC)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -Lmlx -lmlx -L/usr/lib -Imlx -lXext -lX11 -lm -lz -o $(NAME)
	
all: $(NAME)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
