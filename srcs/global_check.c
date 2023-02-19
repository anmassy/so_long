/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmassy <anmassy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 10:36:11 by anmassy           #+#    #+#             */
/*   Updated: 2023/02/19 17:37:02 by anmassy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line/get_next_line.h"
#include "../include/so_long.h"

int	full_check(char **av, t_player *val)
{
	if (!check_file(av[1]))
		printf("Error\nfichier invalide\n");
	else if (!map_is_rectangular(val))
		printf("Error\nmap not rectangular\n");
	else if (!check_value(val))
		printf("Error\nvalues are not correct\n");
	else if (!check_wall(val, av[1]))
		printf("Error\nis not surrounded by wall\n");
	else if (!check_connecting(val) || !check_entry(val) || !check_exit(val))
		printf("Error\nany values are not present in the map\n");
	else
		return (1);
	return (0);
}

int	solved_map(t_player *val)
{
	flood_fill(val);
	if (!valid_map(val))
		printf("Error\nthe map can't be solved\n");
	else
		return (0);
	return (1);
}

void	free_all(t_player *val)
{
	int	i;

	i = 0;
	while (val->map[i])
		free(val->map[i++]);
	free(val->map);
}
