# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anmassy <anmassy@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/17 15:12:21 by anmassy           #+#    #+#              #
#    Updated: 2023/02/18 13:08:21 by anmassy          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =	srcs/check_map.c \
		srcs/convert_map.c \
		srcs/map_value.c \
		main.c

NAME = so_long

OBJ = $(SRC:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -Imlx -Iinclude -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) -Imlx -Iinclude mlx/libmlx_linux.a mlx/libmlx.a -lXext -lX11 -lm -lz -o $(NAME)

$(OBJ) : so_long.h

lib:
	make -C mlx_linux

clean :
	rm -f *.o
	rm -f get_next_line/*.o

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re lib
