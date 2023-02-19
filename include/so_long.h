/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmassy <anmassy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:10:58 by anmassy           #+#    #+#             */
/*   Updated: 2023/02/19 17:26:51 by anmassy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
#include <stdio.h>

typedef struct	s_player
{
	int	x;
	int	y;
	int	coll;
	int	exit;
	int	count;
	char	**map;
}				t_player;


int	count_line(char *av);
int		len_line(char *s);
int		map_is_rectangular(t_player *val);
int		check_wall(t_player *val, char *av);
void	co_player(t_player *val);
void	fill(int x, int y, t_player *val);
void	flood_fill(t_player *val);

int		len_doc(char *av);
void	convert_map(t_player *val, char *av);
int		ft_strcmp(char *s1, char *s2);
int		check_file(char *av);

int		check_entry(t_player *val);
int		check_exit(t_player *val);
int		check_connecting(t_player *val);
int		check_value(t_player *val);
int		valid_map(t_player *val);

int		full_check(char **av, t_player *val);
int		solved_map(t_player *val);

void	display_map(t_player *val);
void	free_all(t_player *val);

#endif