/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bind_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmassy <anmassy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 18:06:26 by anmassy           #+#    #+#             */
/*   Updated: 2023/02/23 14:42:49 by anmassy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line/get_next_line.h"
#include "../include/so_long.h"

void	up_key(t_data *game)
{
	if (game->val->map[game->val->x - 1][game->val->y] == '1')
		return ;
	if (game->val->map[game->val->x][game->val->y] == 'E')
		mlx_put_image_to_window(game->img->mlx, game->img->window,
			game->img->door, game->val->y * 32, game->val->x * 32);
	else
		mlx_put_image_to_window(game->img->mlx, game->img->window,
			game->img->terrain, game->val->y * 32, game->val->x * 32);
	game->val->x--;
	if (game->val->map[game->val->x][game->val->y] == 'C')
	{
		game->val->map[game->val->x][game->val->y] = '0';
		game->val->count++;
	}
	mlx_put_image_to_window(game->img->mlx, game->img->window,
		game->img->fire, game->val->y * 32, game->val->x * 32);
	if (game->val->count == game->val->coll
		&& game->val->map[game->val->x][game->val->y] == 'E')
		destroy_map(game);
}

void	down_key(t_data *game)
{
	if (game->val->map[game->val->x + 1][game->val->y] == '1')
		return ;
	if (game->val->map[game->val->x][game->val->y] == 'E')
		mlx_put_image_to_window(game->img->mlx, game->img->window,
			game->img->door, game->val->y * 32, game->val->x * 32);
	else
		mlx_put_image_to_window(game->img->mlx, game->img->window,
			game->img->terrain, game->val->y * 32, game->val->x * 32);
	game->val->x++;
	if (game->val->map[game->val->x][game->val->y] == 'C')
	{
		game->val->map[game->val->x][game->val->y] = '0';
		game->val->count++;
	}
	mlx_put_image_to_window(game->img->mlx, game->img->window,
		game->img->fire, game->val->y * 32, game->val->x * 32);
	if (game->val->count == game->val->coll
		&& game->val->map[game->val->x][game->val->y] == 'E')
		destroy_map(game);
}

void	right_key(t_data *game)
{
	if (game->val->map[game->val->x][game->val->y +1] == '1')
		return ;
	if (game->val->map[game->val->x][game->val->y] == 'E')
		mlx_put_image_to_window(game->img->mlx, game->img->window,
			game->img->door, game->val->y * 32, game->val->x * 32);
	else
		mlx_put_image_to_window(game->img->mlx, game->img->window,
			game->img->terrain, game->val->y * 32, game->val->x * 32);
	game->val->y++;
	if (game->val->map[game->val->x][game->val->y] == 'C')
	{
		game->val->map[game->val->x][game->val->y] = '0';
		game->val->count++;
	}
	mlx_put_image_to_window(game->img->mlx, game->img->window,
		game->img->fire, game->val->y * 32, game->val->x * 32);
	if (game->val->count == game->val->coll
		&& game->val->map[game->val->x][game->val->y] == 'E')
		destroy_map(game);
}

void	left_key(t_data *game)
{
	if (game->val->map[game->val->x][game->val->y - 1] == '1')
		return ;
	if (game->val->map[game->val->x][game->val->y] == 'E')
		mlx_put_image_to_window(game->img->mlx, game->img->window,
			game->img->door, game->val->y * 32, game->val->x * 32);
	else
		mlx_put_image_to_window(game->img->mlx, game->img->window,
			game->img->terrain, game->val->y * 32, game->val->x * 32);
	game->val->y--;
	if (game->val->map[game->val->x][game->val->y] == 'C')
	{
		game->val->map[game->val->x][game->val->y] = '0';
		game->val->count++;
	}
	mlx_put_image_to_window(game->img->mlx, game->img->window,
		game->img->fire, game->val->y * 32, game->val->x * 32);
	if (game->val->count == game->val->coll
		&& game->val->map[game->val->x][game->val->y] == 'E')
		destroy_map(game);
}

int	find_key(int key, t_data *game)
{
	if (key == W)
		up_key(game);
	if (key == A)
		left_key(game);
	if (key == S)
		down_key(game);
	if (key == D)
		right_key(game);
	if (key == ESC)
		exit(0);
	return (1);
}
