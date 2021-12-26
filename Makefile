# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/22 16:08:15 by tsiguenz          #+#    #+#              #
#    Updated: 2021/12/23 18:14:52 by tsiguenz         ###   ########.fr        #
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
		$(CC) $(CFLAGS) -I/usr/include -Imlx -O3 -c $(SRC)
    else
		$(CC) $(CFLAGS) -I/usr/include -Imlx -O3 -c $(SRC)
    endif
$(NAME): $(OBJ)
    ifeq ($(UNAME), Linux)
		$(CC) $(OBJ) -Lmlx -lmlx -L/usr/lib -Imlx -lXext -lX11 -lm -lz -o $(NAME)
    else
		$(CC) $(CFLAGS) -I /usr/include $(SRC) -Lmlx -lmlx -framework OpenGl -framework AppKit
    endif
	
all: $(NAME)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
