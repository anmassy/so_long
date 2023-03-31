/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmassy <anmassy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 17:37:32 by anmassy           #+#    #+#             */
/*   Updated: 2023/03/31 12:27:23 by anmassy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line/get_next_line.h"
#include "../include/so_long.h"

void	count_move(t_data *game, int key)
{
	static int	move = 1;

	if (key == W && game->val->map[game->val->x - 1][game->val->y] != '1')
		printf("%d\n", move++);
	if (key == A && game->val->map[game->val->x][game->val->y - 1] != '1')
		printf("%d\n", move++);
	if (key == S && game->val->map[game->val->x + 1][game->val->y] != '1')
		printf("%d\n", move++);
	if (key == D && game->val->map[game->val->x][game->val->y + 1] != '1')
		printf("%d\n", move++);
}

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
