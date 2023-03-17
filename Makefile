# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anmassy <anmassy@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/17 15:12:21 by anmassy           #+#    #+#              #
#    Updated: 2023/03/17 14:45:46 by anmassy          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =	get_next_line/get_next_line.c \
		get_next_line/get_next_line_utils.c \
		srcs/check_map.c \
		srcs/convert_map.c \
		srcs/map_value.c \
		srcs/global_check.c \
		srcs/valid_map.c \
		srcs/set_mlx.c \
		srcs/init_struct.c \
		srcs/bind_key.c \
		srcs/display.c \
		srcs/free_all.c \
		main.c

SRC_BONUS =	get_next_line/get_next_line.c \
			get_next_line/get_next_line_utils.c \
			bonus/srcs/check_map.c \
			bonus/srcs/convert_map.c \
			bonus/srcs/map_value.c \
			bonus/srcs/global_check.c \
			bonus/srcs/valid_map.c \
			bonus/srcs/set_mlx.c \
			bonus/srcs/init_struct.c \
			bonus/srcs/bind_key.c \
			bonus/srcs/free_all.c \
			bonus/srcs/enemie.c \
			main.c

OBJ = $(SRC:.c=.o)

OBJ_BONUS = $(SRC_BONUS:.c=.o)

NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -f

INCS = -I ./include -I ./mlx
LIBC = -L ./mlx
MLX_FLAG = -L./mlx -lXext -lX11 -lbsd -lm

all : $(NAME)

bonus: $(OBJ_BONUS)
	@$(MAKE) -C mlx >/dev/null 2>&1
	@$(CC) $(CFLAGS) $(INCS) $(MLX_FLAG) $(OBJ_BONUS) $(LIBC) mlx/libmlx.a -o $(NAME) 

%.o: %.c
	@$(CC) $(CFLAGS) $(INCS) -c $< -o $@

$(NAME): $(OBJ)
	@$(MAKE) -C mlx >/dev/null 2>&1
	@$(CC) $(CFLAGS) $(INCS) $(MLX_FLAG) $(OBJ) $(LIBC) mlx/libmlx.a -o $(NAME) 

clean :
	@$(RM) $(OBJ) $(OBJ_BONUS) >/dev/null
	@$(MAKE) -C mlx clean >/dev/null

fclean : clean
	@$(RM) $(NAME) >/dev/null

re : fclean all

.PHONY : all clean fclean re
