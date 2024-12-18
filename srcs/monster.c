/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monster.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpendilh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 10:20:28 by mpendilh          #+#    #+#             */
/*   Updated: 2024/12/17 13:37:06 by mpendilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

static int	monster_position(t_data *data, int new_x[2], int new_y[2])
{
	if (data->water[0].counter > 4 && data->water[0].counter < 7
		&& (data->obj_utils.new_x[0] + 1 == new_x[0]
			|| data->obj_utils.new_x[0] + 2 == new_x[0]
			|| data->obj_utils.new_x[0] + 3 == new_x[0]
			|| data->obj_utils.new_x[0] + 4 == new_x[0])
		&& (data->obj_utils.new_y[0] == new_y[0]
			|| data->obj_utils.new_y[0] == new_y[1]
			|| data->obj_utils.new_y[1] == new_y[0]
			|| data->obj_utils.new_y[1] == new_y[1]))
		return (1);
	if (data->water[0].counter > 4 && data->water[0].counter < 7
		&& (data->obj_utils.new_x[1] + 1 == new_x[0]
			|| data->obj_utils.new_x[1] + 2 == new_x[0]
			|| data->obj_utils.new_x[1] + 3 == new_x[0]
			|| data->obj_utils.new_x[1] + 4 == new_x[0])
		&& (data->obj_utils.new_y[0] == new_y[0]
			|| data->obj_utils.new_y[0] == new_y[1]
			|| data->obj_utils.new_y[1] == new_y[0]
			|| data->obj_utils.new_y[1] == new_y[1]))
		return (1);
	return (0);
}

void	monster_spell_collision(t_data *data)
{
	int	i;
	int	new_x[2];
	int	new_y[2];

	i = 0;
	while (i < data->monster_nbr)
	{
		new_x[0] = (int)(data->monster2[i].x / 64);
		new_x[1] = (int)ceilf(data->monster2[i].x / 64);
		new_y[0] = (int)(data->monster2[i].y / 64);
		new_y[1] = (int)ceilf(data->monster2[i].y / 64);
		if (monster_position(data, new_x, new_y))
			data->map[data->monster2[i].y_save][data->monster2[i].x_save] = '0';
		i++;
	}
}

static void	monster_direction(t_data *data, int i)
{
	float	dx;
	float	dy;
	float	e;

	dx = data->player.x - data->monster2[i].x;
	dy = data->player.y - data->monster2[i].y;
	e = sqrtf(dx * dx + dy * dy);
	dx = dx / e * data->monster2[i].speed_monster;
	dy = dy / e * data->monster2[i].speed_monster;
	data->monster2[i].speed_x = dx;
	data->monster2[i].speed_y = dy;
}

void	monster(t_data *data, int i)
{
	monster_direction(data, i);
	if (collision2(data, i))
	{
		mlx_put_image_to_window(data->window.mlx, data->window.win,
			data->monster[0].img, data->monster2[i].x - data->camera_x,
			data->monster2[i].y - data->camera_y);
		return ;
	}
	data->monster2[i].x += data->monster2[i].speed_x;
	data->monster2[i].y += data->monster2[i].speed_y;
	mlx_put_image_to_window(data->window.mlx, data->window.win,
		data->monster[0].img, data->monster2[i].x - data->camera_x,
		data->monster2[i].y - data->camera_y);
}

void	put_monster(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->monster_nbr)
	{
		if (data->map[data->monster2[i].y_save]
			[data->monster2[i].x_save] == 'M')
		{
			if (death(data, i))
				data->player.is_dead = true;
			monster(data, i);
		}
		if (data->map[data->monster2[i].y_save]
			[data->monster2[i].x_save] == '0')
			mlx_put_image_to_window(data->window.mlx, data->window.win,
				data->monster[1].img, data->monster2[i].x - data->camera_x,
				data->monster2[i].y - data->camera_y);
		i++;
	}
}
