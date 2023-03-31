/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmassy <anmassy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 13:22:31 by anmassy           #+#    #+#             */
/*   Updated: 2023/03/31 12:28:25 by anmassy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line/get_next_line.h"
#include "../include/so_long.h"

void	display_map(t_data *game)
{
	int	j;
	int	i;

	i = 0;
	while (game->val->map[i])
	{
		j = 0;
		while (game->val->map[i][j])
		{
			printf("%c ", game->val->map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}
