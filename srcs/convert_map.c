/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmassy <anmassy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 12:57:28 by anmassy           #+#    #+#             */
/*   Updated: 2023/02/19 12:08:45 by anmassy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line/get_next_line.h"
#include "../include/so_long.h"

int	len_doc(char *av)
{
	int	len;
	char	c;
	int fd;

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

char	**convert_map(char *av)
{
	char	**map;
	int		fd;
	char	*line;
	int		len;
	int		i;
	
	i = 0;
	len = len_doc(av);
	map = (char **)malloc((len + 1) * sizeof(char*));
	if (!map)
		return (NULL);
	fd = open(av, O_RDONLY);
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

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}

int	check_file(char *av)
{
	char	s[4];
	int		i;
	int		j;

	i = ft_strlen(av) - 4;
	j = 0;
	while(av[i])
		s[j++] = av[i++];
	if (ft_strcmp(s, ".ber") == 0)
		return (0);
	return (1);
}