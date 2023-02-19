/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_value.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmassy <anmassy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 12:59:57 by anmassy           #+#    #+#             */
/*   Updated: 2023/02/19 14:44:10 by anmassy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line/get_next_line.h"
#include "../include/so_long.h"

int	check_entry(t_player *val)
{
	int	i;
	int	j;
	int count;

	i = 0;
	count = 0;
	while (val->map[i])
	{
		j = 0;
		while (val->map[i][j])
		{
			if (val->map[i][j] == 'E')
				count++;
			j++;
		}
		i++;
	}
	if (count != 1)
		return (0);
	return (1);
}

int	check_exit(t_player *val)
{
	int	i;
	int	j;
	int count;

	i = 0;
	count = 0;
	while (val->map[i])
	{
		j = 0;
		while (val->map[i][j])
		{
			if (val->map[i][j] == 'P')
				count++;
			j++;
		}
		i++;
	}
	if (count != 1)
		return (0);
	return (1);
}

int	check_connecting(t_player *val)
{
	int	i;
	int	j;

	i = 0;
	while (val->map[i])
	{
		j = 0;
		while (val->map[i][j])
		{
			if (val->map[i][j] == 'C')
				val->count++;
			j++;
		}
		i++;
	}
	if (val->count == 0)
		return (0);
	return (1);
}

int	check_value(t_player *val)
{
	int	i;
	int	j;

	i = 0;
	while (val->map[i])
	{
		j = 0;
		while (val->map[i][j] && val->map[i][j] != '\n')
		{
			if (val->map[i][j] != '1' && val->map[i][j] != '0' && val->map[i][j] != 'E'
				&& val->map[i][j] != 'P' && val->map[i][j] != 'C')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	valid_map(t_player *val)
{
	if (val->coll != val->count || val->exit != 1)
		return (0);
	return (1);
}