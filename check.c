/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmassy <anmassy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 13:06:00 by anmassy           #+#    #+#             */
/*   Updated: 2023/02/18 11:53:13 by anmassy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line/get_next_line.h"
//#include "so_long.h"
int	len_doc()
{
	int	len;
	char	c;
	int fd;

	len = 0;
	fd = open ("document.ber", O_RDONLY);
	if (read (fd, &c, 1) == 0)
		return (0);
	while (read (fd, &c, 1) > 0)
	{
		if (c == '\n')
			len++;
	}
	close(fd);
	return (len);
}

int len_line(char *s)
{
	int	len;

	len = 0;
	while (s[len] && s[len] != '\n')
		len++;
	return (len);
}

char	**convert_map()
{
	char	**map;
	int		fd;
	char	*line;
	int		len;
	int		i;
	
	i = 0;
	len = len_doc();
	map = (char **)malloc((len + 1) * sizeof(char*));
	if (!map)
		return (NULL);
	fd = open("document.ber", O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		map[i] = line;
		i++;
		line = get_next_line(fd);
	}
	map[i] = NULL;
	close(fd);
	return (map);
}

int	check_entry(char **map)
{
	int	i;
	int	j;
	int count;

	i = 0;
	count = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E')
				count++;
			j++;
		}
		i++;
	}
	if (count != 1)
		return (0);
	return (1);
}

int	check_exit(char **map)
{
	int	i;
	int	j;
	int count;

	i = 0;
	count = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				count++;
			j++;
		}
		i++;
	}
	if (count != 1)
		return (0);
	return (1);
}

int	check_connecting(char **map)
{
	int	i;
	int	j;
	int count;

	i = 0;
	count = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				count++;
			j++;
		}
		i++;
	}
	if (count == 0)
		return (0);
	return (1);
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

int	check_value(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] && map[i][j] != '\n')
		{
			if (map[i][j] != '1' && map[i][j] != '0' && map[i][j] != 'E'
				&& map[i][j] != 'P' && map[i][j] != 'C')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_wall(char **map)
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
	line = len_doc();
	i = 0;
	while (map[line][i] && map[line][i] != '\n')
	{
		if (map[line][i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	check_file(char *av)
{
	char *s;
	int i;
	int	j;

	i = ft_strlen(av) - 4;
	j = 0;
	while(av[i])
		s[j++] = av[i++];
	ft_strcmp(s, ".ber");
}

int main(void)
{
	char	**map;
	int	i;

	map = convert_map();
	if (!check_connecting(map) || !check_entry(map) || !check_exit(map)
		|| !map_is_rectangular(map) || !check_value(map) || !check_wall(map))
	{
		printf("error");
		return (0);
	}
	return (0);
}

