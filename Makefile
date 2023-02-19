# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anmassy <anmassy@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/17 15:12:21 by anmassy           #+#    #+#              #
#    Updated: 2023/02/19 11:59:20 by anmassy          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =	srcs/check_map.c \
		srcs/convert_map.c \
		srcs/map_value.c \
		srcs/global_check.c \
		main.c \
		get_next_line/get_next_line.c \
		get_next_line/get_next_line_utils.c

OBJ = $(SRC:.c=.o)

NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

INCS = -I ./include -I ./mlx
LIBC = -L ./mlx
MLX_FLAG = -lXext -lX11 -lm -lz

all : $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@

$(NAME): $(OBJ)
	@$(MAKE) -C mlx >/dev/null 2>&1
	@$(CC) $(CFLAGS) $(INCS) $(MLX_FLAG) -o $(NAME) $(OBJ) $(LIBC) mlx/libmlx.a

clean :
	$(RM) $(OBJ)
	$(MAKE) -C mlx clean

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re
