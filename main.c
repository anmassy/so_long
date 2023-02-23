/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmassy <anmassy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:09:48 by anmassy           #+#    #+#             */
/*   Updated: 2023/02/23 12:44:36 by anmassy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line/get_next_line.h"
#include "include/so_long.h"


int	free_all(t_data *game)
{
	free_map(game);
	free(game->val);
	free(game->img);
	free(game);
	exit(0);
}

int	main(int ac, char **av)
{
	int		fd;
	char	c;
	t_data	*game;

	if (ac != 2)
		check_error("Error\nnumber of arguments is invalide\n");
	fd = open (av[1], O_RDONLY);
	if (fd < 0 || read (fd, &c, 1) == 0)
		check_error("Error\nmap dosen't exist\n");
	close(fd);
	game = init_struct_to_struct();
	convert_map(game, av[1]);
	if (!full_check(av, game))
		free_all(game);
	solved_map(game);
	free_map(game);
	create_map(game, av[1]);
	free_all(game);
	return (0);
}
