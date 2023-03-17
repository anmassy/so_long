/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmassy <anmassy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 11:31:55 by anmassy           #+#    #+#             */
/*   Updated: 2023/03/16 13:17:48 by anmassy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line/get_next_line.h"
#include "../include/so_long.h"

void	init_struct(t_data *game)
{
	game->val->map = NULL;
	game->val->width = 0;
	game->val->height = 0;
	game->val->x = 0;
	game->val->y = 0;
	game->val->count = 0;
	game->val->coll = 0;
	game->val->exit = 0;
	game->val->human = 0;
}

void	init_struct2(t_data	*game)
{
	game->img->mlx = NULL;
	game->img->window = NULL;
	game->img->a = 0;
	game->img->b = 0;
	game->img->wall = NULL;
	game->img->door = NULL;
	game->img->terrain = NULL;
	game->img->fire = NULL;
	game->img->bomb = NULL;
}

void	init_struct3(t_data *game)
{
	game->bonus->enemie = NULL;
	game->bonus->i = 0;
	game->bonus->j = 0;
}

t_data	*init_struct_to_struct(void)
{
	t_data	*game;

	game = malloc(sizeof(t_data));
	if (!game)
		return (NULL);
	game->val = malloc(sizeof(t_player));
	if (!game->val)
		return (NULL);
	game->img = malloc(sizeof(t_design));
	if (!game->img)
		return (NULL);
	game->bonus = malloc(sizeof(t_bonus));
	if (!game->bonus)
		return (NULL);
	init_struct(game);
	init_struct2(game);
	init_struct3(game);
	return (game);
}
