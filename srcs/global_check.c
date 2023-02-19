/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmassy <anmassy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 10:36:11 by anmassy           #+#    #+#             */
/*   Updated: 2023/02/19 12:15:56 by anmassy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line/get_next_line.h"
#include "../include/so_long.h"

int	full_check(char	**map, char **av)
{
	if (!check_file(av[1]))
		printf("Error\nfichier invalide\n");
	else if (!map_is_rectangular(map))
		printf("Error\nmap not rectangular\n");
	else if (!check_value(map))
		printf("Error\nvalues are not correct\n");
	else if (!check_wall(map, av[1]))
		printf("Error\nis not surrounded by wall\n");
	else if (!check_connecting(map) || !check_entry(map) || !check_exit(map))
		printf("Error\nany values are not present in the map\n");
	else
		return (1);
	return (0);
}

int	solved_map(char	**map, t_player *val)
{
	flood_fill(map, val);
	printf("hello");
	if (!valid_map(map, val))
		printf("Error\nthe map can't be solved\n");
	else
		return (0);
	return (1);
}
