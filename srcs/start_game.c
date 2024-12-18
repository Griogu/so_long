/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpendilh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 18:23:21 by mpendilh          #+#    #+#             */
/*   Updated: 2024/12/17 13:39:32 by mpendilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

static void	get_player_position(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	data->player.y = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'P')
				return ;
			data->player.x += PIXEL;
			j++;
		}
		data->player.x = 0;
		data->player.y += PIXEL;
		i++;
	}
}

static void	monster_settings(t_data *data, int j, int i, int monster_index)
{
	data->monster2[monster_index].y = i * PIXEL;
	data->monster2[monster_index].y_save = i;
	data->monster2[monster_index].x = j * PIXEL;
	data->monster2[monster_index].x_save = j;
}

static void	get_monster_position(t_data *data)
{
	int	i;
	int	j;
	int	monster_index;

	i = 0;
	monster_index = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'M')
			{
				monster_settings(data, j, i, monster_index);
				data->monster2[monster_index].speed_monster
					= data->player.speed_player / 5;
				monster_index++;
			}
			j++;
		}
		i++;
	}
}

static void	initialize_data(t_data *data)
{
	data->death[0].counter = 1;
	data->exit[1].counter = 2;
	data->veldra[1].counter = 4;
	get_player_position(data);
	data->player.speed_player = 1920.0f * 1080.0f / 100000 * 0.03;
	get_monster_position(data);
	data->window.mlx = mlx_init();
	data->window.win = mlx_new_window(data->window.mlx, 1920, 1080, "so_long");
	initialize_textures(data);
	mlx_set_fps_goal(data->window.mlx, 600);
}

void	start_game(t_data *data)
{
	initialize_data(data);
	mlx_loop_hook(data->window.mlx, (void *)update, data);
	mlx_loop(data->window.mlx);
	destroy_all(data);
}
