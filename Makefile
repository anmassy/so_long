# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anmassy <anmassy@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/17 15:12:21 by anmassy           #+#    #+#              #
#    Updated: 2023/02/06 12:01:27 by anmassy          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY : all clean fclean re lib
CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = so_long
SRC = main.c
OBJ = $(SRC:.c=.o)


all : $(NAME) 

%.o: %.c
	$(CC) $(CFLAGS) -Imlx -Iinclude -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) -Imlx -Iinclude mlx/libmlx_linux.a mlx/libmlx.a -lXext -lX11 -lm -lz -o $(NAME)

$(OBJ) : so_long.h Makefile


COM_COLOR = \033[0;34m
OBJ_COLOR = \033[0;36m
OK_COLOR = \033[0;32m
ERROR_COLOR = \033[0;31m
WARN_COLOR = \033[0;33m
NO_COLOR = \033[m

BLUE_COLOR = \033[1;34m
CYAN_COLOR = \033[1;36m
GREEN_COLOR = \033[1;32m
PURPLE_COLOR = \033[1;35m
GRAY_COLOR = \033[0;37m
DGRAY_COLOR = \033[1;30m
WHITE_COLOR = \033[1;37m

	
compile_color:
	echo -en "$(GRAY_COLOR)"

lib:
	make -C mlx_linux
	make -C libft
	make -C ft_printf

test : all
	echo -e "$(CYAN_COLOR)"	
	./so_long


clean :
	rm -f *.o
	rm -f gnl/*.o

fclean : clean
	rm -f $(NAME)

re : fclean all
