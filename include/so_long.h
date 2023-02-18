/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmassy <anmassy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:10:58 by anmassy           #+#    #+#             */
/*   Updated: 2023/02/18 13:14:47 by anmassy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

int	len_line(char *s);
int	map_is_rectangular(char	**map);
int	check_wall(char **map);

int	len_doc();
char	**convert_map();
int	check_file(char *av);

int	check_entry(char **map);
int	check_exit(char **map);
int	check_connecting(char **map);
int	check_value(char **map);

#endif