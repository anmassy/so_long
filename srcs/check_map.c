/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmassy <anmassy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 13:06:00 by anmassy           #+#    #+#             */
/*   Updated: 2023/02/19 17:37:57 by anmassy          ###   ########.fr       */
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

int	map_is_rectangular(t_player *val)
{
	int	first_line;
	int	next_line;
	int	line;

	first_line = len_line(val->map[0]);
	line = 1;
	while (val->map[line])
	{
		next_line = len_line(val->map[line]);
		if (next_line != first_line)
			return (0);
		line++;
	}
	return (1);
}

int	count_line(char *av)
{
	int		len;
	char	c;
	int		fd;

	len = 0;
	fd = open (av, O_RDONLY);
	while (read (fd, &c, 1) > 0)
	{
		if (c == '\n')
			len++;
	}
	close(fd);
	return (len);
}

int	check_wall(t_player *val, char *av)
{
	int	line;
	int	i;

	line = 1;
	i = 0;
	while (val->map[0][i] && val->map[0][i] != '\n')
	{
		if (val->map[0][i] != '1')
			return (0);
		i++;
	}
	i = len_line(val->map[line]);
	while (val->map[line])
	{
		if (val->map[line][0] != '1' && val->map[line][i] != '1')
			return (0);
		line++;
	}
	line = count_line(av);
	i = 0;
	while (val->map[line] && val->map[line][i] && val->map[line][i] != '\n')
	{
		if (val->map[line][i] != '1')
			return (0);
		i++;
	}
	return (1);
}
