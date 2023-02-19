/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmassy <anmassy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:10:58 by anmassy           #+#    #+#             */
/*   Updated: 2023/02/19 12:03:08 by anmassy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
#include <stdio.h>

typedef struct	s_player
{
	int			x;
	int			y;
	int			coll;
	int			exit;
}				t_player;

int		len_line(char *s);
int		map_is_rectangular(char	**map);
int		check_wall(char **map, char *av);
void	co_player(char **map, t_player *val);
void	fill(char **map, int x, int y, t_player *val);
void	flood_fill(char **map, t_player *val);

int		len_doc(char *av);
char	**convert_map(char *av);
int		ft_strcmp(char *s1, char *s2);
int		check_file(char *av);

int		check_entry(char **map);
int		check_exit(char **map);
int		check_connecting(char **map);
int		check_value(char **map);
int		valid_map(char **map, t_player *val);

int		full_check(char	**map, char **av);
int		solved_map(char	**map, t_player *val);

#endif