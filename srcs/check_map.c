/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmassy <anmassy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 13:06:00 by anmassy           #+#    #+#             */
/*   Updated: 2023/03/09 12:02:40 by anmassy          ###   ########.fr       */
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

int	map_is_rectangular(t_data *game)
{
	int	first_line;
	int	next_line;
	int	line;

	first_line = len_line(game->val->map[0]);
	line = 1;
	while (game->val->map[line])
	{
		next_line = len_line(game->val->map[line]);
		if (next_line != first_line)
			return (0);
		line++;
	}
	return (1);
}

int	count_line(char *av, t_data *game)
{
	char	c;
	int		fd;

	fd = open (av, O_RDONLY);
	while (read (fd, &c, 1) > 0)
	{
		if (c == '\n')
			game->val->height++;
	}
	close(fd);
	return (game->val->height);
}

int	check_mid_wall(t_data *game)
{
	int	line;
	int	temp;

	line = 1;
	game->val->width = len_line(game->val->map[line]);
	temp = game->val->width - 1;
	while (game->val->map[line])
	{
		if (game->val->map[line][0] != '1'
			|| game->val->map[line][temp] != '1')
			return (0);
		line++;
	}
	return (1);
}

int	check_wall(t_data *game, char *av)
{
	int	line;
	int	i;

	i = 0;
	while (game->val->map[0][i] && game->val->map[0][i] != '\n')
	{
		if (game->val->map[0][i] != '1')
			return (0);
		i++;
	}
	if (!check_mid_wall(game))
		return (0);
	line = count_line(av, game);
	i = 0;
	while (game->val->map[line]
		&& game->val->map[line][i] && game->val->map[line][i] != '\n')
	{
		if (game->val->map[line][i] != '1')
			return (0);
		i++;
	}
	return (1);
}
