/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_mlx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmassy <anmassy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 09:45:00 by anmassy           #+#    #+#             */
/*   Updated: 2023/02/23 15:12:46 by anmassy          ###   ########.fr       */
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
	return (1);
}

void	chose_image(t_data *game, int i, int j)
{
	if (game->val->map[i][j] == '1')
		mlx_put_image_to_window(game->img->mlx, game->img->window,
			game->img->wall, j * 32, i * 32);
	else if (game->val->map[i][j] == 'P')
		mlx_put_image_to_window(game->img->mlx, game->img->window,
			game->img->fire, j * 32, i * 32);
	else if (game->val->map[i][j] == 'C')
		mlx_put_image_to_window(game->img->mlx, game->img->window,
			game->img->bomb, j * 32, i * 32);
	else if (game->val->map[i][j] == 'E')
		mlx_put_image_to_window(game->img->mlx, game->img->window,
			game->img->door, j * 32, i * 32);
	else
		mlx_put_image_to_window(game->img->mlx, game->img->window,
			game->img->terrain, j * 32, i * 32);
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

void	destroy_image(t_data *game)
{
	int	crash;

	crash = init_sprites(game);
	if (crash <= -1 && crash >= -4)
		mlx_destroy_image(game->img->mlx, game->img->wall);
	if (crash <= -2 && crash >= -4)
		mlx_destroy_image(game->img->mlx, game->img->door);
	if (crash <= -3 && crash >= -4)
		mlx_destroy_image(game->img->mlx, game->img->terrain);
	if (crash == -4)
		mlx_destroy_image(game->img->mlx, game->img->fire);
	mlx_destroy_window(game->img->mlx, game->img->window);
	free(game->img->mlx);
	free_all(game);
}

int destroy_map(t_data *game)
{
	mlx_destroy_image(game->img->mlx, game->img->wall);
	mlx_destroy_image(game->img->mlx, game->img->door);
	mlx_destroy_image(game->img->mlx, game->img->terrain);
	mlx_destroy_image(game->img->mlx, game->img->fire);
	mlx_destroy_image(game->img->mlx, game->img->bomb);
	mlx_destroy_window(game->img->mlx, game->img->window);
	mlx_destroy_display(game->img->mlx);
	free(game->img->mlx);
	free_all(game);
	return(0);
}

void	create_map(t_data *game, char *av)
{
	convert_map(game, av);
	game->img->mlx = mlx_init();
	if (!game->img->mlx)
		free_all(game);
	game->img->window = mlx_new_window(game->img->mlx, game->val->width * 32,
			(game->val->height +1) * 32, "so_long");
	if (!game->img->window)
	{
		free(game->img->mlx);
		free_all(game);
	}
	if (init_sprites(game) != 1)
		destroy_image(game);
	item_place(game);
	game->val->count = 0;
	mlx_hook(game->img->window, 33, 0L, destroy_map, game);
	mlx_key_hook(game->img->window, find_key, game);
	mlx_loop(game->img->mlx);
}
