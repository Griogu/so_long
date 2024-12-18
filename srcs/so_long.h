/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpendilh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 16:08:13 by mpendilh          #+#    #+#             */
/*   Updated: 2024/12/17 14:12:57 by mpendilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef SO_LONG_H
# define SO_LONG_H

# include <math.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdbool.h>
# include "libft/libft.h"
# include "SDL2/SDL_scancode.h"
# include "../MacroLibX/includes/mlx.h"

# define PIXEL 64
# define WALL_TEXTURES 18
# define EXIT_TEXTURES 4
# define ITEM_NBR 5
# define ITEM_FRAME 4
# define BUTTON_TEXTURES 2
# define PLAYER_TEXTURES 9
# define PLAYER_FRAME 4
# define VELDRA_FRAME 8
# define MONSTER_TEXTURES 2
# define WATER_SPELL 6
# define WATER_ICON_NBR 5
# define FIRE_SPELL 28
# define FIRE_ICON_NBR 4
# define EASTER_EGG 4
# define DEATH 6

# define ABS(Value) (Value * ((Value > 0) - (Value < 0)))
# define ERROR_MESS "Error\n"
# define MONSTER_ERROR "Too much monster for one slime.\n"
# define NO_MAP "Please give a map.\n"
# define TEXTURES_ERROR "Please check the permission's texture.\n"
# define FILE_ERROR "File can't be open.\n"
# define MAP_NOT_VALID "The map is not valid.\n"
# define PLAYER_ERROR "The map must contain only 1 player.\n"
# define EXIT_ERROR "The map must contain only 1 exit.\n"
# define ITEM_ERROR "The map must contain at least 1 collectible.\n"

typedef struct s_player
{
	int		move_print;

	float	x;
	float	y;
	float	speed_x;
	float	speed_y;
	float	speed_player;
	float	move_counter;

	bool	is_dead;

	char	*move;
}	t_player;

typedef struct s_monster
{
	int		x_save;
	int		y_save;

	float	x;
	float	y;
	float	speed_monster;
	float	speed_x;
	float	speed_y;
}	t_monster;

typedef struct s_sprite
{
	int		frame;
	int		counter;
	int		fd;
	int		width;
	int		height;

	void	*img;
}	t_sprite;

typedef struct s_attack_sprite
{
	int		frame;
	int		counter;
	int		fd;
	int		width;
	int		height;

	bool	is_attack;

	void	*img;
}	t_a_sprite;

typedef enum e_direction
{
	NW = 0,
	NW_2,
	N,
	NE,
	NE_2,
	W,
	SW,
	SW_2,
	S,
	E,
	SE,
	SE_2,
	CENTER,
	STALAGMITE,
	W_2,
	W_3,
	E_2,
	E_3
}	t_direction;

typedef enum e_color
{
	PURPLE = 0,
	BLUE,
	GREEN,
	PINK,
	RED
}	t_color;

typedef struct s_object_utils
{
	int	new_x[2];
	int	new_y[2];
	int	signal;
}	t_object_u;

typedef struct s_object
{
	int		width;
	int		height;
	int		x;
	int		y;
	int		frame;
	int		counter;
	int		fd;

	void	*img;
}	t_object;

typedef struct s_object_2
{
	int		width;
	int		height;
	int		x;
	int		y;
	int		fd;

	void	*img;
}	t_object_2;

typedef struct s_window
{
	void	*mlx;
	void	*win;
}	t_window;

typedef struct s_data
{
	//parsing
	int				fd;
	float			camera_x;
	float			camera_y;
	int				fd_map;
	float			width;
	float			height;
	int				player_nbr;
	int				exit_nbr;
	int				item_nbr;
	int				monster_nbr;
	int				limit_map_counter_2;
	int				limit_map_counter;

	unsigned int	random;

	char			*map_name;
	char			*map_line;
	char			*map_to_split;
	char			*tmp;

	char			**cpy_map;
	char			**map;

	t_player		player;
	t_sprite		sprite_p[PLAYER_TEXTURES][PLAYER_FRAME];
	t_monster		monster2[5000];
	t_sprite		monster[MONSTER_TEXTURES];
	t_a_sprite		water[WATER_SPELL];
	t_a_sprite		icon[WATER_ICON_NBR];
	t_a_sprite		fire[FIRE_SPELL];
	t_a_sprite		icon2[FIRE_ICON_NBR];
	t_sprite		death[DEATH];
	t_object_u		obj_utils;
	t_object_2		wall[WALL_TEXTURES];
	t_object		veldra[VELDRA_FRAME];
	t_object		exit[EXIT_TEXTURES];
	t_object		item[ITEM_NBR][ITEM_FRAME];
	t_object		easter_egg[EASTER_EGG];
	t_object		button[BUTTON_TEXTURES];
	t_window		window;
	t_object_2		ground;
}	t_data;

// permission

void	open_textures(void);

// Parsing

int		check_map_limit(t_data *map);
int		check_character(int c);
int		check_file(char *map_name, t_data *map);
void	check_size_map(t_data *map);
void	check_character_nbr(t_data *map);
void	free_tab(char **tab);
void	parsing(t_data *map);
void	check_all_map(t_data *map);

// error

void	free_error(t_data *data);
void	free_error2(t_data *data);
void	error_management(char *message, t_data *data);
void	error_textures(t_data *data);

// gestion img

void	start_game(t_data *data);
void	initialize_textures(t_data *data);
void	initialize_player(t_data *data);
void	initialize_wall(t_data *data);
void	initialize_exit(t_data *data);
void	initialize_collectible(t_data *data);
void	initialize_button(t_data *data);
void	initialize_veldra(t_data *data);
void	initialize_monster(t_data *data);
void	initialize_spell(t_data *data);
void	initialize_spell_icon(t_data *data);
void	initialize_spell2(t_data *data);
void	initialize_spell_icon2(t_data *data);
void	initialize_easter_egg(t_data *data);
void	initialize_death(t_data *data);
void	destroy_all(t_data *data);

//item

void	get_item(t_data *data);
void	put_button(t_data *data);

//exit

void	exit_map(t_data *data);

// put img

void	put_image(t_data *data);
void	put_player_position(t_data *data);
void	put_wall(t_data *data, int x, int y);
void	put_veldra(t_data *data);
void	put_monster(t_data *data);
void	put_icon(t_data *data);
void	put_icons2(t_data *data);
void	wall3(t_data *data, int x, int y, int res[8]);
void	wall4(t_data *data, int x, int y, int res[8]);

// frame

void	count_frame_exit_close(t_data *data);
void	count_frame_exit_open(t_data *data);
void	count_frame_item(t_data *data);
void	count_frame_button(t_data *data);
void	count_frame_monster(t_data *data);
void	count_all_frame(t_data *data);
void	count_frame_icon(t_data *data);
void	count_frame_icon2(t_data *data);
void	veldra_frame(t_data *data);
void	veldra_frame2(t_data *data);
void	player_frame(t_data *data, int i);
void	water_spell_frame(t_data *data);
void	fire_spell_frame(t_data *data);
void	count_frame_death(t_data *data);
void	update(t_data *data);

//collision 

int		collision(t_data *data);

// event

void	event(t_data *data);
int		mouse_hook(int button, t_data *data);

// other

void	close_files(t_data *data);
void	death_animation(t_data *data);
void	choose_map(t_data *data);
void	water_attack(t_data *data);
void	fire_attack(t_data *data);

// monster

int		collision2(t_data *data, int i);
void	monster(t_data *data, int i);
int		death(t_data *data, int monster_i);
void	monster_spell_collision(t_data *data);
void	monster_spell_collision2(t_data *data);

#endif
