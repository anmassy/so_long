/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmassy <anmassy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:10:58 by anmassy           #+#    #+#             */
/*   Updated: 2023/04/12 12:29:20 by anmassy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define WALL "./images/wall.xpm"
# define PREWALL "./images/prewall.xpm"
# define BOMB "./images/coll.xpm"
# define FIRE "./images/player.xpm"
# define TERRAIN "./images/floor.xpm"
# define DOOR "./images/exit.xpm"
# define ENEMIE "./images/enemy.xpm"
# define LIFE "./images/life.xpm"
# define NOLIFE "./images/nolife.xpm"
# define ZERO "./images/0.xpm"
# define ONE "./images/1.xpm"
# define TWO "./images/2.xpm"
# define THREE "./images/3.xpm"
# define FOUR "./images/4.xpm"
# define FIVE "./images/5.xpm"
# define SIX "./images/6.xpm"
# define SEVEN "./images/7.xpm"
# define EIGHT "./images/8.xpm"
# define NINE "./images/9.xpm"
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
	int		human;
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
	void	*prewall;
}				t_design;

typedef struct s_bonus
{
	void	*enemie;
	int		i;
	int		j;
	void	*life;
	void	*nolife;
	void	*zero;
	void	*one;
	void	*two;
	void	*three;
	void	*four;
	void	*five;
	void	*six;
	void	*seven;
	void	*eight;
	void	*nine;
}				t_bonus;

typedef struct s_data
{
	struct s_player	*val;
	struct s_design	*img;
	struct s_bonus	*bonus;
}				t_data;

int		len_line(char *s);
int		map_is_rectangular(t_data *game);
int		count_line(char *av, t_data *game);
int		check_mid_wall(t_data *game);
int		check_wall(t_data *game, char *av);

int		init_sprites_num(t_data *game);
int		init_sprites_num2(t_data *game);
void	image_num(t_data *game, int num, int width, int height);
void	image_num2(t_data *game, int num, int width, int height);
void	ft_update_score(t_data *game, int score);
void	count_move(t_data *game, int key);

int		len_doc(char *av);
void	convert_map(t_data *game, char *av);
int		ft_strcmp(char *s1, char *s2);
int		check_file(char *av);

void	destroy_image(t_data *game);
void	destroy_numbers1(t_data *game);
void	destroy_numbers2(t_data *game);
int		destroy_map(t_data *game);

void	enemie_move_down(t_data *game);
void	enemie_move_up(t_data *game);
void	enemie_move_right(t_data *game);
void	enemie_move_right(t_data *game);
int		enemie_move(t_data *game);

void	free_map(t_data *game);
int		free_all(t_data *game);

void	print_error(char *msg);
int		full_check(char **av, t_data *game);
int		solved_map(t_data *game);

void	init_struct(t_data *game);
void	init_struct2(t_data	*game);
void	init_struct3(t_data *game);
t_data	*init_struct_to_struct(void);

void	life(t_data *game, int human_life);
void	human_life(t_data *game);

int		check_entry(t_data *game);
int		check_exit(t_data *game);
int		check_connecting(t_data *game);
int		check_value(t_data *game);
int		valid_map(t_data *game);

void	up_key(t_data *game);
void	down_key(t_data *game);
void	right_key(t_data *game);
void	left_key(t_data *game);
int		find_key(int key, t_data *game);

int		init_sprites(t_data *game);
int		init_sprites2(t_data *game);
void	chose_image(t_data *game, int i, int j);
void	item_place(t_data *game);
void	create_map(t_data *game, char *av);

void	co_player(t_data *game);
void	co_enemie(t_data *game);
int		check_enemie(t_data *game);
void	fill(int x, int y, t_data *game);
void	flood_fill(t_data *game);

#endif