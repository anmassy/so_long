/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmassy <anmassy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 12:57:28 by anmassy           #+#    #+#             */
/*   Updated: 2023/02/18 13:36:53 by anmassy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line/get_next_line.h"
#include "../include/so_long.h"

int	len_doc()
{
	int	len;
	char	c;
	int fd;

	len = 0;
	fd = open ("./map/map_test.ber", O_RDONLY);
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
	fd = open("./map/map_test.ber", O_RDONLY);
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

// int	check_file(char *av)
// {
// 	char *s;
// 	int i;
// 	int	j;

// 	i = ft_strlen(av) - 4;
// 	j = 0;
// 	while(av[i])
// 		s[j++] = av[i++];
// 	ft_strcmp(s, ".ber");
// }