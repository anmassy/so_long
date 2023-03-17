/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_mlx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmassy <anmassy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 09:45:00 by anmassy           #+#    #+#             */
/*   Updated: 2023/03/16 14:10:34 by anmassy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line/get_next_line.h"
#include "../include/so_long.h"

int	init_sprites(t_data *game)
{
	game->img->wall = mlx_xpm_file_to_image(game->img->mlx, WALL,
			&game->img->a, &game->img->b);
	if (!game->img->wall)
		return (0);
	game->img->door = mlx_xpm_file_to_image(game->img->mlx, DOOR,
			&game->img->a, &game->img->b);
	if (!game->img->door)
		return (-1);
	game->img->terrain = mlx_xpm_file_to_image(game->img->mlx, TERRAIN,
			&game->img->a, &game->img->b);
	if (!game->img->terrain)
		return (-2);
	game->img->fire = mlx_xpm_file_to_image(game->img->mlx, FIRE,
			&game->img->a, &game->img->b);
	if (!game->img->fire)
		return (-3);
	game->img->bomb = mlx_xpm_file_to_image(game->img->mlx, BOMB,
			&game->img->a, &game->img->b);
	if (!game->img->bomb)
		return (-4);
	game->bonus->enemie = mlx_xpm_file_to_image(game->img->mlx, ENEMIE,
			&game->img->a, &game->img->b);
	if (!game->bonus->enemie)
		return (-5);
	return (1);
}

void	chose_image(t_data *game, int i, int j)
{
	if (game->val->map[i][j] == '1')
		mlx_put_image_to_window(game->img->mlx, game->img->window,
			game->img->wall, j * 37, i * 37);
	else if (game->val->map[i][j] == 'P')
		mlx_put_image_to_window(game->img->mlx, game->img->window,
			game->img->fire, j * 37, i * 37);
	else if (game->val->map[i][j] == 'C')
		mlx_put_image_to_window(game->img->mlx, game->img->window,
			game->img->bomb, j * 37, i * 37);
	else if (game->val->map[i][j] == 'E')
		mlx_put_image_to_window(game->img->mlx, game->img->window,
			game->img->door, j * 37, i * 37);
	else if (game->val->map[i][j] == 'N')
		mlx_put_image_to_window(game->img->mlx, game->img->window,
			game->bonus->enemie, j * 37, i * 37);
	else
		mlx_put_image_to_window(game->img->mlx, game->img->window,
			game->img->terrain, j * 37, i * 37);
}

void	item_place(t_data *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->val->map[i])
	{
		j = 0;
		while (game->val->map[i][j] && j < game->val->width)
		{
			chose_image(game, i, j);
			j++;
		}
		i++;
	}
}

void	create_map(t_data *game, char *av)
{
	convert_map(game, av);
	game->img->mlx = mlx_init();
	if (!game->img->mlx)
		free_all(game);
	game->img->window = mlx_new_window(game->img->mlx, game->val->width * 37,
			(game->val->height + 1) * 37, "so_long");
	if (!game->img->window)
	{
		free(game->img->mlx);
		free_all(game);
	}
	if (init_sprites(game) != 1)
		destroy_image(game);
	game->val->human = 3;
	item_place(game);
	game->val->count = 0;
	co_enemie(game);
	mlx_hook(game->img->window, 33, 0L, destroy_map, game);
	mlx_key_hook(game->img->window, find_key, game);
	mlx_loop_hook(game->img->mlx, enemie_move, game);
	mlx_loop(game->img->mlx);
}
