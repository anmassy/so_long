/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmassy <anmassy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 13:06:00 by anmassy           #+#    #+#             */
/*   Updated: 2023/02/19 12:16:36 by anmassy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line/get_next_line.h"
#include "../include/so_long.h"

int	len_line(char *s)
{
	int	len;

	len = 0;
	while (s[len] && s[len] != '\n')
		len++;
	return (len);
}

int	map_is_rectangular(char	**map)
{
	int	first_line;
	int	next_line;
	int	line;

	first_line = len_line(map[0]);
	line = 1;
	while (map[line])
	{
		next_line = len_line(map[line]);
		if (next_line != first_line)
			return (0);
		line++;
	}
	return (1);
}

int	check_wall(char **map, char *av)
{
	int	line;
	int	i;

	line = 1;
	i = 0;
	while (map[0][i] && map[0][i] != '\n')
	{
		if (map[0][i] != '1')
			return (0);
		i++;
	}
	i = len_line(map[line]);
	while (map[line])
	{
		if (map[line][0] != '1' && map[line][i] != '1')
			return (0);
		line++;
	}
	line = len_doc(av);
	i = 0;
	while (map[line][i] && map[line][i] != '\n')
	{
		if (map[line][i] != '1')
			return (0);
		i++;
	}
	return (1);
}


void co_player(char **map, t_player *val)
{
	val->x = 0;
	while (map[val->x])
	{
		val->y = 0;
		while (map[val->x][val->y])
		{
			val->y++;
			if (map[val->x][val->y] == 'P')
				return ;
		}
		val->x++;
	}
}

void	fill(char **map, int x, int y, t_player *val)
{
	if (map[x][y] == '1' || map[x][y] != 'F')
		return ;
	if (map[x][y] != 'C')
		val->coll++;
	if (map[x][y] != 'E')
		val->exit++;
	map[x][y] = 'F';
	fill(map, x - 1, y, val);
	fill(map, x + 1, y, val);
	fill(map, x, y - 1, val);
	fill(map, x, y + 1, val);
}

void	flood_fill(char **map, t_player *val)
{
	val->coll = 0;
	val->exit = 0;
	co_player(map, val);
	fill(map, val->x, val->y, val);	
}
