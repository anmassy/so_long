/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmassy <anmassy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 17:37:32 by anmassy           #+#    #+#             */
/*   Updated: 2023/04/12 10:37:55 by anmassy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line/get_next_line.h"
#include "../include/so_long.h"

void	co_player(t_data *game)
{
	game->val->x = 0;
	while (game->val->map[game->val->x])
	{
		game->val->y = 0;
		while (game->val->map[game->val->x][game->val->y])
		{
			game->val->y++;
			if (game->val->map[game->val->x][game->val->y] == 'P')
				return ;
		}
		game->val->x++;
	}
}

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

int	check_enemie(t_data *game)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (game->val->map[i])
	{
		j = 0;
		while (game->val->map[i][j] && game->val->map[i][j] != '\n')
		{
			if (game->val->map[i][j] == 'N')
				count++;
			j++;
		}
		i++;
	}
	if (count > 1)
		return (-1);
	return (count);
}

void	fill(int x, int y, t_data *game)
{
	if (game->val->map[x][y] == '1' || game->val->map[x][y] == 'F')
		return ;
	if (game->val->map[x][y] == 'C')
		game->val->coll++;
	if (game->val->map[x][y] == 'E')
		game->val->exit++;
	game->val->map[x][y] = 'F';
	fill(x - 1, y, game);
	fill(x + 1, y, game);
	fill(x, y - 1, game);
	fill(x, y + 1, game);
}

void	flood_fill(t_data *game)
{
	co_player(game);
	fill(game->val->x, game->val->y, game);
}
