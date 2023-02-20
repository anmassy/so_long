/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_mlx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmassy <anmassy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 09:45:00 by anmassy           #+#    #+#             */
/*   Updated: 2023/02/20 14:35:55 by anmassy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line/get_next_line.h"
#include "../include/so_long.h"

void	init_sprites(t_player *val)
{
	val->wall = mlx_xpm_file_to_image(val->mlx, "textures/wall.xpm", &val->a, &val->b);
	val->door = mlx_xpm_file_to_image(val->mlx, DOOR, &val->a, &val->b);
	val->terrain = mlx_xpm_file_to_image(val->mlx, TERRAIN, &val->a, &val->b);
	val->fire = mlx_xpm_file_to_image(val->mlx, FIRE, &val->a, &val->b);
	val->bomb = mlx_xpm_file_to_image(val->mlx, BOMB, &val->a, &val->b);
}

void	chose_image(t_player *val, int i, int j)
{
	if (val->map[i][j] == '1')
		mlx_put_image_to_window(val->mlx, val->window, val->wall, i * 32, j * 32);
	else if (val->map[i][j] == 'P')
		mlx_put_image_to_window(val->mlx, val->window, val->fire, i * 32, j * 32);
	else if (val->map[i][j] == 'C')
		mlx_put_image_to_window(val->mlx, val->window, val->bomb, i * 32, j * 32);
	else if (val->map[i][j] == 'E')
		mlx_put_image_to_window(val->mlx, val->window, val->door, i * 32, j * 32);
	else
		mlx_put_image_to_window(val->mlx, val->window, val->terrain, i * 32, j * 32);
}

void	item_place(t_player *val)
{
	int	i;
	int	j;

	i = 1;
	while (val->map[i])
	{
		j = 0;
		while (val->map[i][j])
		{
			chose_image(val, i ,j);
			j++;
		}
		i++;
	}
}
