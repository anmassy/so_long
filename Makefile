# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anmassy <anmassy@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/17 15:12:21 by anmassy           #+#    #+#              #
#    Updated: 2023/02/23 17:09:52 by anmassy          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =	srcs/check_map.c \
		srcs/convert_map.c \
		srcs/map_value.c \
		srcs/global_check.c \
		srcs/display.c \
		srcs/valid_map.c \
		get_next_line/get_next_line.c \
		get_next_line/get_next_line_utils.c \
		srcs/set_mlx.c \
		srcs/init_struct.c \
		srcs/bind_key.c \
		srcs/free_all.c \
		main.c

OBJ = $(SRC:.c=.o)

NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -f

INCS = -I ./include -I ./mlx
LIBC = -L ./mlx
MLX_FLAG = -L./mlx -lXext -lX11 -lbsd -lm

all : $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) $(INCS) -c $< -o $@

$(NAME): $(OBJ)
	@$(MAKE) -C mlx >/dev/null 2>&1
	@$(CC) $(CFLAGS) $(INCS) $(MLX_FLAG) $(OBJ) $(LIBC) mlx/libmlx.a -o $(NAME) 

clean :
	@$(RM) $(OBJ) >/dev/null
	@$(MAKE) -C mlx clean >/dev/null

fclean : clean
	@$(RM) $(NAME) >/dev/null

re : fclean all

.PHONY : all clean fclean re
