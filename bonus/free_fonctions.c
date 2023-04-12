/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_fonctions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmassy <anmassy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 17:07:41 by anmassy           #+#    #+#             */
/*   Updated: 2023/04/12 11:19:09 by anmassy          ###   ########.fr       */
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
