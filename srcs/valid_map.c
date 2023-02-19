/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmassy <anmassy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 17:37:32 by anmassy           #+#    #+#             */
/*   Updated: 2023/02/19 17:38:05 by anmassy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line/get_next_line.h"
#include "../include/so_long.h"

void	co_player(t_player *val)
{
	val->x = 0;
	while (val->map[val->x])
	{
		val->y = 0;
		while (val->map[val->x][val->y])
		{
			val->y++;
			if (val->map[val->x][val->y] == 'P')
				return ;
		}
		val->x++;
	}
}

void	fill(int x, int y, t_player *val)
{
	if (val->map[x][y] == '1' || val->map[x][y] == 'F')
		return ;
	if (val->map[x][y] == 'C')
		val->coll++;
	if (val->map[x][y] == 'E')
		val->exit++;
	val->map[x][y] = 'F';
	fill(x - 1, y, val);
	fill(x + 1, y, val);
	fill(x, y - 1, val);
	fill(x, y + 1, val);
}

void	flood_fill(t_player *val)
{
	co_player(val);
	fill(val->x, val->y, val);
}
