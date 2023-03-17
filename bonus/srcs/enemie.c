/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemie.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmassy <anmassy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 09:25:01 by anmassy           #+#    #+#             */
/*   Updated: 2023/03/16 14:44:16 by anmassy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line/get_next_line.h"
#include "../include/so_long.h"

// mlx_loop_hook(game->img->mlx, enemie_move, game);

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
			game->img->door, game->bonus->j * 37, game->bonus->i * 37);
	else if (game->val->map[game->bonus->i][game->bonus->j] == 'C')
		mlx_put_image_to_window(game->img->mlx, game->img->window,
			game->img->bomb, game->bonus->j * 37, game->bonus->i * 37);
	else
		mlx_put_image_to_window(game->img->mlx, game->img->window,
			game->img->terrain, game->bonus->j * 37, game->bonus->i * 37);
	game->bonus->i++;
	mlx_put_image_to_window(game->img->mlx, game->img->window,
		game->bonus->enemie, game->bonus->j * 37, game->bonus->i * 37);
}
	
void	enemie_move_up(t_data *game)
{
	if (game->val->map[game->bonus->i - 1][game->bonus->j] == '1')
		return ;
	if (game->val->map[game->bonus->i][game->bonus->j] == 'E')
		mlx_put_image_to_window(game->img->mlx, game->img->window,
			game->img->door, game->bonus->j * 37, game->bonus->i * 37);
	else if (game->val->map[game->bonus->i][game->bonus->j] == 'C')
		mlx_put_image_to_window(game->img->mlx, game->img->window,
			game->img->bomb, game->bonus->j * 37, game->bonus->i * 37);
	else
		mlx_put_image_to_window(game->img->mlx, game->img->window,
			game->img->terrain, game->bonus->j * 37, game->bonus->i * 37);
	game->bonus->i--;
	mlx_put_image_to_window(game->img->mlx, game->img->window,
		game->bonus->enemie, game->bonus->j * 37, game->bonus->i * 37);
}

void	enemie_move_right(t_data *game)
{
	if (game->val->map[game->bonus->i][game->bonus->j + 1] == '1')
		return ;
	if (game->val->map[game->bonus->i][game->bonus->j] == 'E')
		mlx_put_image_to_window(game->img->mlx, game->img->window,
			game->img->door, game->bonus->j * 37, game->bonus->i * 37);
	else if (game->val->map[game->bonus->i][game->bonus->j] == 'C')
		mlx_put_image_to_window(game->img->mlx, game->img->window,
			game->img->bomb, game->bonus->j * 37, game->bonus->i * 37);
	else
		mlx_put_image_to_window(game->img->mlx, game->img->window,
			game->img->terrain, game->bonus->j * 37, game->bonus->i * 37);
	game->bonus->j++;
	mlx_put_image_to_window(game->img->mlx, game->img->window,
		game->bonus->enemie, game->bonus->j * 37, game->bonus->i * 37);
}

void	enemie_move_left(t_data *game)
{
	if (game->val->map[game->bonus->i][game->bonus->j - 1] == '1')
		return ;
	if (game->val->map[game->bonus->i][game->bonus->j] == 'E')
		mlx_put_image_to_window(game->img->mlx, game->img->window,
			game->img->door, game->bonus->j * 37, game->bonus->i * 37);
	else if (game->val->map[game->bonus->i][game->bonus->j] == 'C')
		mlx_put_image_to_window(game->img->mlx, game->img->window,
			game->img->bomb, game->bonus->j * 37, game->bonus->i * 37);
	else
		mlx_put_image_to_window(game->img->mlx, game->img->window,
			game->img->terrain, game->bonus->j * 37, game->bonus->i * 37);
	game->bonus->j--;
	mlx_put_image_to_window(game->img->mlx, game->img->window,
		game->bonus->enemie, game->bonus->j * 37, game->bonus->i * 37);
}

int	enemie_move(t_data *game)
{
	static int	speed = 0;

	if (speed > 1000)
	{
		speed = 0;
		if (game->bonus->i < game->val->x)
			enemie_move_down(game);
		else if (game->bonus->i > game->val->x)
			enemie_move_up(game);
		if (game->bonus->j < game->val->y)
			enemie_move_right(game);
		else if (game->bonus->j > game->val->y)
			enemie_move_left(game);
		return (1);
	}
	speed++;
	return (1);
}

void	human_life(t_data *game)
{
	printf("%d\n", game->val->human);
	if (game->val->map[game->val->x][game->val->y] == 'N')
	{
		game->val->human--;
		if (game->val->human == 0)
		{
			printf("GAME_OVER\n");
			destroy_map(game);
		}
	}
}