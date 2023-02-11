/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmassy <anmassy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 13:57:05 by anmassy           #+#    #+#             */
/*   Updated: 2022/11/29 17:31:04 by anmassy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	size_line(char *strings, int i)
{
	if (!strings)
		return (-1);
	while (1)
	{
		if (strings[i] == '\n' || strings[i] == 0)
			return (i);
		i++;
	}
	return (-1);
}

char	*get_next_line(int fd)
{
	static char		*strings[1024];
	char			*buffer;
	char			*line;
	int				ret;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	ret = read(fd, buffer, BUFFER_SIZE);
	while (ret > 0)
	{
		buffer[ret] = '\0';
		strings[fd] = ft_strjoin(strings[fd], buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
		ret = read(fd, buffer, BUFFER_SIZE);
	}
	line = ft_substr(strings[fd], 0, (size_line(strings[fd], 0) + 1));
	ret = size_line(strings[fd], 0) + 1;
	strings[fd] = ft_substr(strings[fd], ret, (ft_strlen(strings[fd]) - ret));
	return (free(buffer), line);
}

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("document.txt", O_RDONLY);
	while (line = get_next_line(fd))
	{
		printf("%s\n", line);
		free(line);
	}
	return (0);
}
