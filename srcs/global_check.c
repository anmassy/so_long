/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmassy <anmassy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 10:36:11 by anmassy           #+#    #+#             */
/*   Updated: 2023/02/23 12:47:52 by anmassy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line/get_next_line.h"
#include "../include/so_long.h"

int	full_check(char **av, t_data *game)
{
	if (!check_file(av[1]))
		printf("Error\nfichier invalide\n");
	else if (!map_is_rectangular(game))
		printf("Error\nmap not rectangular\n");
	else if (!check_value(game))
		printf("Error\nvalues are not correct\n");
	else if (!check_wall(game, av[1]))
		printf("Error\nis not surrounded by wall\n");
	else if (!check_connecting(game) || !check_entry(game) || !check_exit(game))
		printf("Error\nany values are not present in the map\n");
	else
		return (1);
	return (0);
}

int	solved_map(t_data *game)
{
	flood_fill(game);
	if (!valid_map(game))
	{
		printf("Error\nthe map can't be solved\n");
		free_all(game);
	}
	else
		return (0);
	return (1);
}

void	free_map(t_data *game)
{
	int	i;

	i = 0;
	while (game->val->map[i])
		free(game->val->map[i++]);
	free(game->val->map);
}

void	check_error(char *msg)
{
	printf("%s", msg);
	exit(0);
}
