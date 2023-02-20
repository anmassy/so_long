/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmassy <anmassy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:09:48 by anmassy           #+#    #+#             */
/*   Updated: 2023/02/20 15:41:34 by anmassy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line/get_next_line.h"
#include "include/so_long.h"

t_player	*init_struct(void)
{
	t_player	*val;

	val = malloc(sizeof(t_player));
	val->map = NULL;
	val->width = 0;
	val->height = 0;
	val->x = 0;
	val->y = 0;
	val->count = 0;
	val->coll = 0;
	val->exit = 0;
	return (val);
}

t_design	*init_struct2(void)
{

	t_design	*img;
	img = malloc(sizeof(t_design));
	img->mlx = NULL;
	img->window = NULL;
	img->a = 0;
	img->b = 0;
	img->wall = NULL;
	img->door = NULL;
	img->terrain = NULL;
	img->fire = NULL;
	img->bomb = NULL;
	return (img);
}
int	main(int ac, char **av)
{
	int			fd;
	char		c;
	t_player	*val;
	t_design	*img;

	val = init_struct();
	img = init_struct2();
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
	free_all(val);
	convert_map(val, av[1]);
	img->mlx = mlx_init();
	img->window = mlx_new_window(img->mlx, val->width * 32, (val->height +1) * 32, "so_long");
	init_sprites(img);
	item_place(img, val);
	mlx_loop(img->mlx);
	// free_all(val);
	// free(val);
	return (0);
}
