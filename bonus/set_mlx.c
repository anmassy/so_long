/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_mlx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmassy <anmassy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 09:45:00 by anmassy           #+#    #+#             */
/*   Updated: 2023/03/31 18:54:18 by anmassy          ###   ########.fr       */
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
	game->bonus->life = mlx_xpm_file_to_image(game->img->mlx, LIFE,
			&game->img->a, &game->img->b);
	if (!game->bonus->life)
		return (-6);
	game->bonus->nolife = mlx_xpm_file_to_image(game->img->mlx, NOLIFE,
			&game->img->a, &game->img->b);
	if (!game->bonus->nolife)
		return (-7);
	game->img->prewall = mlx_xpm_file_to_image(game->img->mlx, PREWALL,
			&game->img->a, &game->img->b);
	if (!game->img->prewall)
		return (-8);
	return (1);
}

void	chose_image(t_data *game, int i, int j)
{
	if (!game->val->map[i + 1] || (game->val->map[i + 1] && game->val->map[i][j] == '1' && game->val->map[i + 1][j] != '1'))
		mlx_put_image_to_window(game->img->mlx, game->img->window,
			game->img->wall, j * 32, i * 32);
	else if (game->val->map[i + 1] && game->val->map[i][j] == '1' && game->val->map[i + 1][j] == '1')
		mlx_put_image_to_window(game->img->mlx, game->img->window,
			game->img->prewall, j * 32, i * 32);
	else if (game->val->map[i][j] == 'P')
		mlx_put_image_to_window(game->img->mlx, game->img->window,
			game->img->fire, j * 32, i * 32);
	else if (game->val->map[i][j] == 'C')
		mlx_put_image_to_window(game->img->mlx, game->img->window,
			game->img->bomb, j * 32, i * 32);
	else if (game->val->map[i][j] == 'E')
		mlx_put_image_to_window(game->img->mlx, game->img->window,
			game->img->door, j * 32, i * 32);
	else if (game->val->map[i][j] == 'N')
		mlx_put_image_to_window(game->img->mlx, game->img->window,
			game->bonus->enemie, j * 32, i * 32);
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

int	init_sprites_num(t_data *game)
{
	game->bonus->zero = mlx_xpm_file_to_image(game->img->mlx, ZERO,
			&game->img->a, &game->img->b);
	if (!game->bonus->zero)
		return (0);
	game->bonus->one = mlx_xpm_file_to_image(game->img->mlx, ONE, 
			&game->img->a, &game->img->b);
	if (!game->bonus->one)
		return (-1);
	game->bonus->two = mlx_xpm_file_to_image(game->img->mlx, TWO,
			&game->img->a, &game->img->b);
	if (!game->bonus->two)
		return (-2);
	game->bonus->three = mlx_xpm_file_to_image(game->img->mlx, THREE,
			&game->img->a, &game->img->b);
	if (!game->bonus->three)
		return (-3);
	game->bonus->four = mlx_xpm_file_to_image(game->img->mlx, FOUR,
			&game->img->a, &game->img->b);
	if (!game->bonus->four)
		return (-4);
	game->bonus->five = mlx_xpm_file_to_image(game->img->mlx, FIVE,
			&game->img->a, &game->img->b);
	if (!game->bonus->five)
		return (-5);
	game->bonus->six = mlx_xpm_file_to_image(game->img->mlx, SIX,
			&game->img->a, &game->img->b);
	if (!game->bonus->six)
		return (-6);
	game->bonus->seven = mlx_xpm_file_to_image(game->img->mlx, SEVEN,
			&game->img->a, &game->img->b);
	if (!game->bonus->seven)
		return (-7);
	game->bonus->eight = mlx_xpm_file_to_image(game->img->mlx, EIGHT,
			&game->img->a, &game->img->b);
	if (!game->bonus->eight)
		return (-8);
	game->bonus->nine = mlx_xpm_file_to_image(game->img->mlx, NINE,
			&game->img->a, &game->img->b);
	if (!game->bonus->nine)
		return (-9);
	return (1);
}

void	image_num(t_data *game, int i, int num)
{
	if (num == 0)
		mlx_put_image_to_window(game->img->mlx, game->img->window,
			game->bonus->zero, (game->val->width - 1 - i) * 32, (game->val->height + 1) * 32);
	if (num == 1)
		mlx_put_image_to_window(game->img->mlx, game->img->window,
			game->bonus->one, (game->val->width - 1- i) * 32, (game->val->height + 1) * 32);
	if (num == 2)
		mlx_put_image_to_window(game->img->mlx, game->img->window,
			game->bonus->two, (game->val->width - 1- i) * 32, (game->val->height + 1) * 32);
	if (num == 3)
		mlx_put_image_to_window(game->img->mlx, game->img->window,
			game->bonus->three, (game->val->width - 1- i) * 32, (game->val->height + 1) * 32);
	if (num == 4)
		mlx_put_image_to_window(game->img->mlx, game->img->window,
			game->bonus->four, (game->val->width - 1- i) * 32, (game->val->height + 1) * 32);
	if (num == 5)
		mlx_put_image_to_window(game->img->mlx, game->img->window,
			game->bonus->five, (game->val->width - 1- i) * 32, (game->val->height + 1) * 32);
	if (num == 6)
		mlx_put_image_to_window(game->img->mlx, game->img->window,
			game->bonus->six, (game->val->width - 1- i) * 32, (game->val->height + 1) * 32);
	if (num == 7)
		mlx_put_image_to_window(game->img->mlx, game->img->window,
			game->bonus->seven, (game->val->width - 1- i) * 32, (game->val->height + 1) * 32);
	if (num == 8)
		mlx_put_image_to_window(game->img->mlx, game->img->window,
			game->bonus->eight, (game->val->width - 1- i) * 32, (game->val->height + 1) * 32);
	if (num == 9)
		mlx_put_image_to_window(game->img->mlx, game->img->window,
			game->bonus->nine, (game->val->width - 1- i) * 32, (game->val->height + 1) * 32);
}

void	ft_update_score(t_data *game, int score)
{
	int	i;
	int	num;

	i = 0;
	while (i < 4)
	{
		num = score % 10;
		score /= 10;
		mlx_put_image_to_window(game->img->mlx, game->img->window,
			game->bonus->zero, (game->val->width - 1 - i) * 32, (game->val->height + 1)* 32);
		image_num(game, i, num);
		i++;
	}
}



void	create_map(t_data *game, char *av)
{
	convert_map(game, av);
	game->img->mlx = mlx_init();
	if (!game->img->mlx)
		free_all(game);
	game->img->window = mlx_new_window(game->img->mlx, game->val->width * 32,
			(game->val->height + 2) * 32, "so_long");
	if (!game->img->window)
	{
		free(game->img->mlx);
		free_all(game);
	}
	if (init_sprites(game) != 1)
		destroy_image(game);
	init_sprites_num(game);
	game->val->human = 3; //bonus
	item_place(game);
	ft_update_score(game, 0);
	game->val->count = 0;
	co_enemie(game); //bonus
	mlx_hook(game->img->window, 33, 0L, destroy_map, game);
	mlx_key_hook(game->img->window, find_key, game);
	if (check_enemie(game) >= 1) //bonus
		mlx_loop_hook(game->img->mlx, enemie_move, game); //bonus
	mlx_loop(game->img->mlx);
}
