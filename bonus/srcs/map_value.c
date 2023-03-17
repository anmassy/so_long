/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_value.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmassy <anmassy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 12:59:57 by anmassy           #+#    #+#             */
/*   Updated: 2023/03/14 14:46:16 by anmassy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line/get_next_line.h"
#include "../include/so_long.h"

int	check_entry(t_data *game)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (game->val->map[i])
	{
		j = 0;
		while (game->val->map[i][j])
		{
			if (game->val->map[i][j] == 'E')
				count++;
			j++;
		}
		i++;
	}
	if (count != 1)
		return (0);
	return (1);
}

int	check_exit(t_data *game)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (game->val->map[i])
	{
		j = 0;
		while (game->val->map[i][j])
		{
			if (game->val->map[i][j] == 'P')
				count++;
			j++;
		}
		i++;
	}
	if (count != 1)
		return (0);
	return (1);
}

int	check_connecting(t_data *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->val->map[i])
	{
		j = 0;
		while (game->val->map[i][j])
		{
			if (game->val->map[i][j] == 'C')
				game->val->count++;
			j++;
		}
		i++;
	}
	if (game->val->count == 0)
		return (0);
	return (1);
}

int	check_value(t_data *game) //bunus
{
	int	i;
	int	j;

	i = 0;
	while (game->val->map[i])
	{
		j = 0;
		while (game->val->map[i][j] && game->val->map[i][j] != '\n')
		{
			if (game->val->map[i][j] != '1' && game->val->map[i][j] != '0'
				&& game->val->map[i][j] != 'E' && game->val->map[i][j] != 'P'
				&& game->val->map[i][j] != 'C' && game->val->map[i][j] != 'N')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	valid_map(t_data *game)
{
	if (game->val->coll != game->val->count || game->val->exit != 1)
		return (0);
	return (1);
}
