/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmassy <anmassy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:10:58 by anmassy           #+#    #+#             */
/*   Updated: 2023/02/23 12:45:14 by anmassy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define WALL "./textures/wall.xpm"
# define BOMB "./textures/bomb.xpm"
# define FIRE "./textures/fire.xpm"
# define TERRAIN "./textures/terrain.xpm"
# define DOOR "./textures/door.xpm"
# define W 119
# define A 97
# define S 115
# define D 100
# define ESC 65307

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

typedef struct s_data
{
	struct s_player	*val;
	struct s_design	*img;
}				t_data;

void	up_key(t_data *game);
void	down_key(t_data *game);
void	right_key(t_data *game);
void	left_key(t_data *game);
int		find_key(int key, t_data *game);

int		len_line(char *s);
int		map_is_rectangular(t_data *game);
int		count_line(char *av, t_data *game);
int		check_wall(t_data *game, char *av);

int		len_doc(char *av);
void	convert_map(t_data *game, char *av);
int		ft_strcmp(char *s1, char *s2);
int		check_file(char *av);

void	display_map(t_data *game);

int		full_check(char **av, t_data *game);
int		solved_map(t_data *game);
void	free_map(t_data *game);
int		free_all(t_data *game);
void	check_error(char *msg);

void	init_struct(t_data *game);
void	init_struct2(t_data	*game);
t_data	*init_struct_to_struct(void);

int		check_entry(t_data *game);
int		check_exit(t_data *game);
int		check_connecting(t_data *game);
int		check_value(t_data *game);
int		valid_map(t_data *game);

void	init_sprites(t_data *game);
void	chose_image(t_data *game, int i, int j);
void	item_place(t_data *game);
void	create_map(t_data *game, char *av);

void	co_player(t_data *game);
void	fill(int x, int y, t_data *game);
void	flood_fill(t_data *game);

#endif