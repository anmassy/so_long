/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compteur.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmassy <anmassy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 09:52:53 by anmassy           #+#    #+#             */
/*   Updated: 2023/04/12 12:30:45 by anmassy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line/get_next_line.h"
#include "../include/so_long.h"

int	init_sprites_num(t_data *game)
{
	game->bonus->zero = mlx_xpm_file_to_image(game->img->mlx, ZERO,
			&game->img->a, &game->img->b);
	if (!game->bonus->zero)
		return (0);
	game->bonus->one = mlx_xpm_file_to_image(game->img->mlx, ONE,
			&game->img->a, &game->img->b);
	if (!game->bonus->one)
		return (-1);
	game->bonus->two = mlx_xpm_file_to_image(game->img->mlx, TWO,
			&game->img->a, &game->img->b);
	if (!game->bonus->two)
		return (-2);
	game->bonus->three = mlx_xpm_file_to_image(game->img->mlx, THREE,
			&game->img->a, &game->img->b);
	if (!game->bonus->three)
		return (-3);
	game->bonus->four = mlx_xpm_file_to_image(game->img->mlx, FOUR,
			&game->img->a, &game->img->b);
	if (!game->bonus->four)
		return (-4);
	return (1);
}

int	init_sprites_num2(t_data *game)
{
	game->bonus->five = mlx_xpm_file_to_image(game->img->mlx, FIVE,
			&game->img->a, &game->img->b);
	if (!game->bonus->five)
		return (-5);
	game->bonus->six = mlx_xpm_file_to_image(game->img->mlx, SIX,
			&game->img->a, &game->img->b);
	if (!game->bonus->six)
		return (-6);
	game->bonus->seven = mlx_xpm_file_to_image(game->img->mlx, SEVEN,
			&game->img->a, &game->img->b);
	if (!game->bonus->seven)
		return (-7);
	game->bonus->eight = mlx_xpm_file_to_image(game->img->mlx, EIGHT,
			&game->img->a, &game->img->b);
	if (!game->bonus->eight)
		return (-8);
	game->bonus->nine = mlx_xpm_file_to_image(game->img->mlx, NINE,
			&game->img->a, &game->img->b);
	if (!game->bonus->nine)
		return (-9);
	return (1);
}

void	image_num(t_data *game, int num, int width, int height)
{
	if (num == 0)
		mlx_put_image_to_window(game->img->mlx, game->img->window,
			game->bonus->zero, width, height);
	if (num == 1)
		mlx_put_image_to_window(game->img->mlx, game->img->window,
			game->bonus->one, width, height);
	if (num == 2)
		mlx_put_image_to_window(game->img->mlx, game->img->window,
			game->bonus->two, width, height);
	if (num == 3)
		mlx_put_image_to_window(game->img->mlx, game->img->window,
			game->bonus->three, width, height);
	if (num == 4)
		mlx_put_image_to_window(game->img->mlx, game->img->window,
			game->bonus->four, width, height);
	image_num2(game, num, width, height);
}

void	image_num2(t_data *game, int num, int width, int height)
{
	if (num == 5)
		mlx_put_image_to_window(game->img->mlx, game->img->window,
			game->bonus->five, width, height);
	if (num == 6)
		mlx_put_image_to_window(game->img->mlx, game->img->window,
			game->bonus->six, width, height);
	if (num == 7)
		mlx_put_image_to_window(game->img->mlx, game->img->window,
			game->bonus->seven, width, height);
	if (num == 8)
		mlx_put_image_to_window(game->img->mlx, game->img->window,
			game->bonus->eight, width, height);
	if (num == 9)
		mlx_put_image_to_window(game->img->mlx, game->img->window,
			game->bonus->nine, width, height);
}
