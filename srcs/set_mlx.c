/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_mlx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmassy <anmassy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 09:45:00 by anmassy           #+#    #+#             */
/*   Updated: 2023/02/22 13:42:35 by anmassy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line/get_next_line.h"
#include "../include/so_long.h"

void	init_sprites(t_data *game)
{
	game->img->wall = mlx_xpm_file_to_image(game->img->mlx, "textures/wall.xpm", &game->img->a, &game->img->b);
	game->img->door = mlx_xpm_file_to_image(game->img->mlx, DOOR, &game->img->a, &game->img->b);
	game->img->terrain = mlx_xpm_file_to_image(game->img->mlx, TERRAIN, &game->img->a, &game->img->b);
	game->img->fire = mlx_xpm_file_to_image(game->img->mlx, FIRE, &game->img->a, &game->img->b);
	game->img->bomb = mlx_xpm_file_to_image(game->img->mlx, BOMB, &game->img->a, &game->img->b);
}

void	chose_image(t_data *game, int i, int j)
{
	if (game->val->map[i][j] == '1')
		mlx_put_image_to_window(game->img->mlx, game->img->window, game->img->wall, j * 32, i * 32);
	else if (game->val->map[i][j] == 'P')
		mlx_put_image_to_window(game->img->mlx, game->img->window, game->img->fire, j * 32, i * 32);
	else if (game->val->map[i][j] == 'C')
		mlx_put_image_to_window(game->img->mlx, game->img->window, game->img->bomb, j * 32, i * 32);
	else if (game->val->map[i][j] == 'E')
		mlx_put_image_to_window(game->img->mlx, game->img->window, game->img->door, j * 32, i * 32);
	else
		mlx_put_image_to_window(game->img->mlx, game->img->window, game->img->terrain, j * 32, i * 32);
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
			chose_image(game, i ,j);
			j++;
		}
		i++;
	}
}
