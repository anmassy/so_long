/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmassy <anmassy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:10:58 by anmassy           #+#    #+#             */
/*   Updated: 2023/02/20 15:34:15 by anmassy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define WALL "./textures/wall.xpm"
# define BOMB "./textures/bomb.xpm"
# define FIRE "./textures/fire.xpm"
# define TERRAIN "./textures/terrain.xpm"
# define DOOR "./textures/door.xpm"

# include <stdio.h>
# include <stddef.h>
# include "../mlx/mlx.h"

typedef struct s_player
{
	char	**map;
	int		width;
	int		height;
	int		x;
	int		y;
	int		count;
	int		coll;
	int		exit;
}				t_player;

typedef struct s_design
{
	void	*mlx;
	void	*window;
	int		a;
	int		b;
	void	*wall;
	void	*terrain;
	void	*door;
	void	*fire;
	void	*bomb;
}				t_design;

int		count_line(char *av, t_player *val);
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
void	free_all(t_player *val);

void	display_map(t_player *val);

void	init_sprites(t_design *img);
void	chose_image(t_design *img, t_player *val, int i, int j);
void	item_place(t_design *img, t_player *val);

#endif