/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmassy <anmassy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 11:18:02 by anmassy           #+#    #+#             */
/*   Updated: 2023/04/12 15:24:20 by anmassy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line/get_next_line.h"
#include "../include/so_long.h"

void	destroy_image(t_data *game)
{
	int	crash;

	crash = init_sprites(game);
	if (crash <= 0 && crash >= -8)
		mlx_destroy_image(game->img->mlx, game->img->wall);
	if (crash <= -1 && crash >= -8)
		mlx_destroy_image(game->img->mlx, game->img->door);
	if (crash <= -2 && crash >= -8)
		mlx_destroy_image(game->img->mlx, game->img->terrain);
	if (crash <= -3 && crash >= -8)
		mlx_destroy_image(game->img->mlx, game->img->fire);
	if (crash <= -4 && crash >= -8)
		mlx_destroy_image(game->img->mlx, game->img->bomb);
	if (crash <= -5 && crash >= -8)
		mlx_destroy_image(game->img->mlx, game->bonus->enemie);
	if (crash <= -6 && crash >= -8)
		mlx_destroy_image(game->img->mlx, game->bonus->life);
	if (crash <= -7 && crash >= -8)
		mlx_destroy_image(game->img->mlx, game->bonus->nolife);
	if (crash == -8)
		mlx_destroy_image(game->img->mlx, game->img->prewall);
	mlx_destroy_window(game->img->mlx, game->img->window);
	free(game->img->mlx);
	free_all(game);
}

void	destroy_numbers1(t_data *game)
{
	int	crash;

	crash = init_sprites_num(game);
	if (crash <= 0 && crash >= -9)
		mlx_destroy_image(game->img->mlx, game->bonus->zero);
	if (crash <= -1 && crash >= -9)
		mlx_destroy_image(game->img->mlx, game->bonus->one);
	if (crash <= -2 && crash >= -9)
		mlx_destroy_image(game->img->mlx, game->bonus->two);
	if (crash <= -3 && crash >= -9)
		mlx_destroy_image(game->img->mlx, game->bonus->three);
	if (crash <= -4 && crash >= -9)
		mlx_destroy_image(game->img->mlx, game->bonus->four);
	destroy_numbers2(game);
}

void	destroy_numbers2(t_data *game)
{
	int	crash;

	crash = init_sprites_num2(game);
	if (crash <= -5 && crash >= -8)
		mlx_destroy_image(game->img->mlx, game->bonus->five);
	if (crash <= -6 && crash >= -8)
		mlx_destroy_image(game->img->mlx, game->bonus->six);
	if (crash <= -7 && crash >= -9)
		mlx_destroy_image(game->img->mlx, game->bonus->seven);
	if (crash <= -8 && crash >= -9)
		mlx_destroy_image(game->img->mlx, game->bonus->eight);
	if (crash == -9)
		mlx_destroy_image(game->img->mlx, game->bonus->nine);
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
	mlx_destroy_image(game->img->mlx, game->img->prewall);
	mlx_destroy_image(game->img->mlx, game->bonus->enemie);
	mlx_destroy_image(game->img->mlx, game->bonus->nolife);
	mlx_destroy_image(game->img->mlx, game->bonus->life);
	mlx_destroy_image(game->img->mlx, game->bonus->zero);
	mlx_destroy_image(game->img->mlx, game->bonus->one);
	mlx_destroy_image(game->img->mlx, game->bonus->two);
	mlx_destroy_image(game->img->mlx, game->bonus->three);
	mlx_destroy_image(game->img->mlx, game->bonus->four);
	mlx_destroy_image(game->img->mlx, game->bonus->five);
	mlx_destroy_image(game->img->mlx, game->bonus->six);
	mlx_destroy_image(game->img->mlx, game->bonus->seven);
	mlx_destroy_image(game->img->mlx, game->bonus->eight);
	mlx_destroy_image(game->img->mlx, game->bonus->nine);
	mlx_destroy_window(game->img->mlx, game->img->window);
	mlx_destroy_display(game->img->mlx);
	free(game->img->mlx);
	free_all(game);
	return (0);
}
