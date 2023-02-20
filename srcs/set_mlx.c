/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_mlx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmassy <anmassy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 09:45:00 by anmassy           #+#    #+#             */
/*   Updated: 2023/02/20 15:36:46 by anmassy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line/get_next_line.h"
#include "../include/so_long.h"

void	init_sprites(t_design *img)
{
	img->wall = mlx_xpm_file_to_image(img->mlx, "textures/wall.xpm", &img->a, &img->b);
	img->door = mlx_xpm_file_to_image(img->mlx, DOOR, &img->a, &img->b);
	img->terrain = mlx_xpm_file_to_image(img->mlx, TERRAIN, &img->a, &img->b);
	img->fire = mlx_xpm_file_to_image(img->mlx, FIRE, &img->a, &img->b);
	img->bomb = mlx_xpm_file_to_image(img->mlx, BOMB, &img->a, &img->b);
}

void	chose_image(t_design *img, t_player *val, int i, int j)
{
	if (val->map[i][j] == '1')
		mlx_put_image_to_window(img->mlx, img->window, img->wall, j * 32, i * 32);
	else if (val->map[i][j] == 'P')
		mlx_put_image_to_window(img->mlx, img->window, img->fire, j * 32, i * 32);
	else if (val->map[i][j] == 'C')
		mlx_put_image_to_window(img->mlx, img->window, img->bomb, j * 32, i * 32);
	else if (val->map[i][j] == 'E')
		mlx_put_image_to_window(img->mlx, img->window, img->door, j * 32, i * 32);
	else
		mlx_put_image_to_window(img->mlx, img->window, img->terrain, j * 32, i * 32);
}

void	item_place(t_design *img, t_player *val)
{
	int	i;
	int	j;

	i = 0;
	while (val->map[i])
	{
		j = 0;
		while (val->map[i][j] && j < val->width)
		{
			chose_image(img, val, i ,j);
			j++;
		}
		i++;
	}
}
