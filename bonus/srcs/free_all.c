/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmassy <anmassy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 17:07:41 by anmassy           #+#    #+#             */
/*   Updated: 2023/03/16 13:20:23 by anmassy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line/get_next_line.h"
#include "../include/so_long.h"

void	free_map(t_data *game)
{
	int	i;

	i = 0;
	while (game->val->map[i])
		free(game->val->map[i++]);
	free(game->val->map);
}

int	free_all(t_data *game)
{
	free_map(game);
	free(game->val);
	free(game->img);
	free(game);
	exit(0);
}

void	destroy_image(t_data *game)
{
	int	crash;

	crash = init_sprites(game);
	if (crash <= -1 && crash >= -5)
		mlx_destroy_image(game->img->mlx, game->img->wall);
	if (crash <= -2 && crash >= -5)
		mlx_destroy_image(game->img->mlx, game->img->door);
	if (crash <= -3 && crash >= -5)
		mlx_destroy_image(game->img->mlx, game->img->terrain);
	if (crash <= -4 && crash >= -5)
		mlx_destroy_image(game->img->mlx, game->img->fire);
	if (crash == -5)
		mlx_destroy_image(game->img->mlx, game->bonus->enemie);
	mlx_destroy_window(game->img->mlx, game->img->window);
	free(game->img->mlx);
	free_all(game);
}

int	destroy_map(t_data *game)
{
	mlx_destroy_image(game->img->mlx, game->img->wall);
	mlx_destroy_image(game->img->mlx, game->img->door);
	mlx_destroy_image(game->img->mlx, game->img->terrain);
	mlx_destroy_image(game->img->mlx, game->img->fire);
	mlx_destroy_image(game->img->mlx, game->img->bomb);
	mlx_destroy_image(game->img->mlx, game->bonus->enemie);
	mlx_destroy_window(game->img->mlx, game->img->window);
	mlx_destroy_display(game->img->mlx);
	free(game->img->mlx);
	free_all(game);
	return (0);
}
