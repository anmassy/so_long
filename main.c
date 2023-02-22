/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmassy <anmassy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:09:48 by anmassy           #+#    #+#             */
/*   Updated: 2023/02/22 12:19:35 by anmassy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line/get_next_line.h"
#include "include/so_long.h"

int	main(int ac, char **av)
{
	int			fd;
	char		c;
	t_data		*game;

	game = init_struct_to_struct();
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
	convert_map(game, av[1]);
	if (!full_check(av, game))
		return (0);
	solved_map(game);
	free_all(game);
	convert_map(game, av[1]);
	game->img->mlx = mlx_init();
	game->img->window = mlx_new_window(game->img->mlx, game->val->width * 32, (game->val->height +1) * 32, "so_long");
	init_sprites(game);
	item_place(game);
	mlx_loop(game->img->mlx);
	// free_all(game);
	// free(game);
	return (0);
}
