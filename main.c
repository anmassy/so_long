/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmassy <anmassy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:09:48 by anmassy           #+#    #+#             */
/*   Updated: 2023/02/19 13:39:05 by anmassy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line/get_next_line.h"
#include "include/so_long.h"

t_player	*init_struct()
{
	t_player	*val;
	
	val = malloc(sizeof(t_player));
	val->x = 0;
	val->y = 0;
	val->coll = 0;
	val->exit = 0;
	val->count = 0;
	return (val);
}

int main(int ac, char **av)
{
	int			fd;
	char		c;
	t_player	*val;

	val = init_struct();
	if (ac != 2)
	{
		printf("Error\nnumber of arguments is invalide\n");
		return (0);
	}
	fd = open (av[1], O_RDONLY);
	if (fd < 0 || read (fd, &c, 1) == 0)
	{
		printf("Error\nmap dosen't exist\n");
		return (0);
	}
	close(fd);
	convert_map(val, av[1]);
	if (!full_check(av, val))
		return (0);
	solved_map(val);
	// map = convert_map(av[1]);
	return (0);
}