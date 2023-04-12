/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemie.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmassy <anmassy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 09:25:01 by anmassy           #+#    #+#             */
/*   Updated: 2023/04/12 15:12:58 by anmassy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line/get_next_line.h"
#include "../include/so_long.h"

void	enemie_move_down(t_data *game)
{
	if (game->val->map[game->bonus->i + 1][game->bonus->j] == '1')
		return ;
	if (game->val->map[game->bonus->i][game->bonus->j] == 'E')
		mlx_put_image_to_window(game->img->mlx, game->img->window,
			game->img->door, game->bonus->j * 32, game->bonus->i * 32);
	else if (game->val->map[game->bonus->i][game->bonus->j] == 'C')
		mlx_put_image_to_window(game->img->mlx, game->img->window,
			game->img->bomb, game->bonus->j * 32, game->bonus->i * 32);
	else
		mlx_put_image_to_window(game->img->mlx, game->img->window,
			game->img->terrain, game->bonus->j * 32, game->bonus->i * 32);
	game->bonus->i++;
	mlx_put_image_to_window(game->img->mlx, game->img->window,
		game->bonus->enemie, game->bonus->j * 32, game->bonus->i * 32);
}

void	enemie_move_up(t_data *game)
{
	if (game->val->map[game->bonus->i - 1][game->bonus->j] == '1')
		return ;
	if (game->val->map[game->bonus->i][game->bonus->j] == 'E')
		mlx_put_image_to_window(game->img->mlx, game->img->window,
			game->img->door, game->bonus->j * 32, game->bonus->i * 32);
	else if (game->val->map[game->bonus->i][game->bonus->j] == 'C')
		mlx_put_image_to_window(game->img->mlx, game->img->window,
			game->img->bomb, game->bonus->j * 32, game->bonus->i * 32);
	else
		mlx_put_image_to_window(game->img->mlx, game->img->window,
			game->img->terrain, game->bonus->j * 32, game->bonus->i * 32);
	game->bonus->i--;
	mlx_put_image_to_window(game->img->mlx, game->img->window,
		game->bonus->enemie, game->bonus->j * 32, game->bonus->i * 32);
}

void	enemie_move_right(t_data *game)
{
	if (game->val->map[game->bonus->i][game->bonus->j + 1] == '1')
		return ;
	if (game->val->map[game->bonus->i][game->bonus->j] == 'E')
		mlx_put_image_to_window(game->img->mlx, game->img->window,
			game->img->door, game->bonus->j * 32, game->bonus->i * 32);
	else if (game->val->map[game->bonus->i][game->bonus->j] == 'C')
		mlx_put_image_to_window(game->img->mlx, game->img->window,
			game->img->bomb, game->bonus->j * 32, game->bonus->i * 32);
	else
		mlx_put_image_to_window(game->img->mlx, game->img->window,
			game->img->terrain, game->bonus->j * 32, game->bonus->i * 32);
	game->bonus->j++;
	mlx_put_image_to_window(game->img->mlx, game->img->window,
		game->bonus->enemie, game->bonus->j * 32, game->bonus->i * 32);
}

void	enemie_move_left(t_data *game)
{
	if (game->val->map[game->bonus->i][game->bonus->j - 1] == '1')
		return ;
	if (game->val->map[game->bonus->i][game->bonus->j] == 'E')
		mlx_put_image_to_window(game->img->mlx, game->img->window,
			game->img->door, game->bonus->j * 32, game->bonus->i * 32);
	else if (game->val->map[game->bonus->i][game->bonus->j] == 'C')
		mlx_put_image_to_window(game->img->mlx, game->img->window,
			game->img->bomb, game->bonus->j * 32, game->bonus->i * 32);
	else
		mlx_put_image_to_window(game->img->mlx, game->img->window,
			game->img->terrain, game->bonus->j * 32, game->bonus->i * 32);
	game->bonus->j--;
	mlx_put_image_to_window(game->img->mlx, game->img->window,
		game->bonus->enemie, game->bonus->j * 32, game->bonus->i * 32);
}

int	enemie_move(t_data *game)
{
	static int	speed = 0;

	if (speed == 30000)
	{
		if (game->bonus->i > game->val->x)
			enemie_move_up(game);
		if (game->bonus->i < game->val->x)
			enemie_move_down(game);
		if (game->bonus->j > game->val->y)
			enemie_move_left(game);
		if (game->bonus->j < game->val->y)
			enemie_move_right(game);
		speed = 0;
	}
	speed++;
	return (1);
}
