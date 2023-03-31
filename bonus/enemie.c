/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemie.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmassy <anmassy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 09:25:01 by anmassy           #+#    #+#             */
/*   Updated: 2023/03/31 13:22:20 by anmassy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line/get_next_line.h"
#include "../include/so_long.h"

void	co_enemie(t_data *game)
{
	game->bonus->i = 0;
	while (game->val->map[game->bonus->i])
	{
		game->bonus->j = 0;
		while (game->val->map[game->bonus->i][game->bonus->j])
		{
			game->bonus->j++;
			if (game->val->map[game->bonus->i][game->bonus->j] == 'N')
				return ;
		}
		game->bonus->i++;
	}
}

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

void	life(t_data *game, int human_life) //mettre les images
{
	if (human_life == 3)
	{
		mlx_put_image_to_window(game->img->mlx, game->img->window,
				game->bonus->life, 0 * 32, (game->val->height + 1) * 32);
		mlx_put_image_to_window(game->img->mlx, game->img->window,
				game->bonus->life, 1 * 32, (game->val->height + 1) * 32);
		mlx_put_image_to_window(game->img->mlx, game->img->window,
				game->bonus->life, 2 * 32, (game->val->height + 1) * 32);
	}
	if (human_life == 2)
	{
		mlx_put_image_to_window(game->img->mlx, game->img->window,
				game->bonus->life, 0 * 32, (game->val->height + 1) * 32);
		mlx_put_image_to_window(game->img->mlx, game->img->window,
				game->bonus->life, 1 * 32, (game->val->height + 1) * 32);
		mlx_put_image_to_window(game->img->mlx, game->img->window,
				game->bonus->nolife, 2 * 32, (game->val->height + 1) * 32);
	}
	if (human_life == 1)
	{
		mlx_put_image_to_window(game->img->mlx, game->img->window,
				game->bonus->life, 0 * 32, (game->val->height + 1) * 32);
		mlx_put_image_to_window(game->img->mlx, game->img->window,
				game->bonus->nolife, 1 * 32, (game->val->height + 1) * 32);
		mlx_put_image_to_window(game->img->mlx, game->img->window,
				game->bonus->nolife, 2 * 32, (game->val->height + 1) * 32);
	}
}

void	human_life(t_data *game)
{
	life(game, game->val->human);
	if (game->val->x == game->bonus->i && game->val->y == game->bonus->j)
	{
		game->val->human--;
		if (game->val->human == 0)
		{
			printf("GAME_OVER\n");
			destroy_map(game);
		}
	}
}

int	enemie_move(t_data *game)
{
	static int	speed = 0;

	if (speed > 20000)
	{
		speed = 0;
		if (game->bonus->i < game->val->x)
			enemie_move_down(game);
		else if (game->bonus->i > game->val->x)
			enemie_move_up(game);
		else if (game->bonus->j < game->val->y)
			enemie_move_right(game);
		else if (game->bonus->j > game->val->y)
			enemie_move_left(game);
		return (1);
	}
	speed++;
	return (1);
}

// void	move(t_data *game) derneire parti a faire 

// {
// 	int	distance;

// 	distance = 0;
// 	while (game->val->map[game->val->x][game-val->y] != game->val->map[game->bonus->i][game-bonus->j])
// 	{
// 		if (game->val->x + 1 == 0)
// 			game->val->x + 1 = distance + 1;
		
// 	}
// }