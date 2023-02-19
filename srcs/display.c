/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmassy <anmassy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 13:22:31 by anmassy           #+#    #+#             */
/*   Updated: 2023/02/19 15:57:53 by anmassy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line/get_next_line.h"
#include "../include/so_long.h"

void	display_map(t_player *val)
{
	int j;
	int i;
	
	i = 0;
	while (val->map[i])
	{
		j = 0;
		while (val->map[i][j])
		{
			printf("%c ", val->map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}