/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_mlx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmassy <anmassy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 09:45:00 by anmassy           #+#    #+#             */
/*   Updated: 2023/02/23 12:45:59 by anmassy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line/get_next_line.h"
#include "../include/so_long.h"

void	init_sprites(t_data *game)
{
	game->img->wall = mlx_xpm_file_to_image(game->img->mlx, WALL,
			&game->img->a, &game->img->b);
	game->img->door = mlx_xpm_file_to_image(game->img->mlx, DOOR,
			&game->img->a, &game->img->b);
	game->img->terrain = mlx_xpm_file_to_image(game->img->mlx, TERRAIN,
			&game->img->a, &game->img->b);
	game->img->fire = mlx_xpm_file_to_image(game->img->mlx, FIRE,
			&game->img->a, &game->img->b);
	game->img->bomb = mlx_xpm_file_to_image(game->img->mlx, BOMB,
			&game->img->a, &game->img->b);
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

void	create_map(t_data *game, char *av)
{
	convert_map(game, av);
	game->img->mlx = mlx_init();
	game->img->window = mlx_new_window(game->img->mlx, game->val->width * 32,
			(game->val->height +1) * 32, "so_long");
	init_sprites(game);
	item_place(game);
	game->val->count = 0;
	mlx_hook(game->img->window, 33, 0L, free_all, game);
	mlx_key_hook(game->img->window, find_key, game);
	mlx_loop(game->img->mlx);
}
