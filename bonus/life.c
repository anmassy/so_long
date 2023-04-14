/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmassy <anmassy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 09:59:00 by anmassy           #+#    #+#             */
/*   Updated: 2023/04/14 11:38:01 by anmassy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line/get_next_line.h"
#include "../include/so_long.h"

void	ft_update_score(t_data *game, int score)
{
	int	i;
	int	num;
	int	width;
	int	height;

	i = 0;
	while (i < 4)
	{
		width = (game->val->width - 1 - i) * 32;
		height = (game->val->height + 1) * 32;
		num = score % 10;
		score /= 10;
		mlx_put_image_to_window(game->img->mlx, game->img->window,
			game->bonus->zero, width, height);
		image_num(game, num, width, height);
		i++;
	}
}

void	count_move(t_data *game, int key)
{
	static int	move = 1;

	if (key == W && game->val->map[game->val->x - 1][game->val->y] != '1')
		ft_update_score(game, move++);
	if (key == A && game->val->map[game->val->x][game->val->y - 1] != '1')
		ft_update_score(game, move++);
	if (key == S && game->val->map[game->val->x + 1][game->val->y] != '1')
		ft_update_score(game, move++);
	if (key == D && game->val->map[game->val->x][game->val->y + 1] != '1')
		ft_update_score(game, move++);
}

void	life(t_data *game, int human_life)
{
	if (human_life >= 1)
	{
		mlx_put_image_to_window(game->img->mlx, game->img->window,
			game->bonus->life, 0 * 32, (game->val->height + 1) * 32);
		if (human_life >= 2)
			mlx_put_image_to_window(game->img->mlx, game->img->window,
				game->bonus->life, 1 * 32, (game->val->height + 1) * 32);
		if (human_life == 3)
			mlx_put_image_to_window(game->img->mlx, game->img->window,
				game->bonus->life, 2 * 32, (game->val->height + 1) * 32);
	}
	if (human_life <= 2)
		mlx_put_image_to_window(game->img->mlx, game->img->window,
			game->bonus->nolife, 2 * 32, (game->val->height + 1) * 32);
	if (human_life == 1)
		mlx_put_image_to_window(game->img->mlx, game->img->window,
			game->bonus->nolife, 1 * 32, (game->val->height + 1) * 32);
}

void	human_life(t_data *game)
{
	if (game->val->x == game->bonus->i && game->val->y == game->bonus->j)
	{
		game->val->human--;
		if (game->val->human == 0)
		{
			ft_printf("GAME_OVER\n");
			destroy_map(game);
		}
	}
	life(game, game->val->human);
}
