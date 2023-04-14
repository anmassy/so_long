# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anmassy <anmassy@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/17 15:12:21 by anmassy           #+#    #+#              #
#    Updated: 2023/04/14 11:09:25 by anmassy          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =	get_next_line/get_next_line.c \
		get_next_line/get_next_line_utils.c \
		ft_printf/srcs/ft_print_hex.c \
		ft_printf/srcs/ft_print_nbr.c \
		ft_printf/srcs/ft_print_other.c \
		ft_printf/srcs/ft_print_ptr.c \
		ft_printf/srcs/ft_print_unsigned_nbr.c \
		ft_printf/srcs/ft_printf.c \
		srcs/check_map.c \
		srcs/convert_map.c \
		srcs/map_value.c \
		srcs/global_check.c \
		srcs/valid_map.c \
		srcs/set_mlx.c \
		srcs/init_struct.c \
		srcs/move_player.c \
		srcs/display.c \
		srcs/free_fonctions.c \
		main.c

SRC_BONUS =	get_next_line/get_next_line.c \
			get_next_line/get_next_line_utils.c \
			ft_printf/srcs/ft_print_hex.c \
			ft_printf/srcs/ft_print_nbr.c \
			ft_printf/srcs/ft_print_other.c \
			ft_printf/srcs/ft_print_ptr.c \
			ft_printf/srcs/ft_print_unsigned_nbr.c \
			ft_printf/srcs/ft_printf.c \
			bonus/check_map.c \
			bonus/convert_map.c \
			bonus/map_value.c \
			bonus/global_check.c \
			bonus/valid_map.c \
			bonus/set_mlx.c \
			bonus/init_struct.c \
			bonus/move_player.c \
			bonus/free_fonctions.c \
			bonus/enemie.c \
			bonus/compteur.c \
			bonus/life.c \
			bonus/destroy_image.c \
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

.PHONY : all bonus clean fclean re
