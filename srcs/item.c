/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   item.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpendilh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 17:36:19 by mpendilh          #+#    #+#             */
/*   Updated: 2024/12/15 17:49:40 by mpendilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	put_button(t_data *data)
{
	if (data->player.speed_y)
		mlx_put_image_to_window(data->window.mlx, data->window.win,
			data->button[data->button[0].counter].img,
			data->player.x + 25 - data->camera_x,
			data->player.y - 25 - data->camera_y);
	else
		mlx_put_image_to_window(data->window.mlx, data->window.win,
			data->button[data->button[0].counter].img,
			data->player.x + 25 - data->camera_x,
			data->player.y - data->camera_y);
}

static void	get_item_nbr(t_data *data)
{
	int	i;
	int	j;

	data->item_nbr = 0;
	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'C')
				data->item_nbr++;
			j++;
		}
		i++;
	}
}

static void	collect_item(t_data *data)
{
	data->obj_utils.signal = 0;
	if (data->map[data->obj_utils.new_y[0]][data->obj_utils.new_x[0]] == 'C')
	{
		put_button(data);
		data->obj_utils.signal = 1;
		event(data);
	}
	if (data->map[data->obj_utils.new_y[1]][data->obj_utils.new_x[0]] == 'C')
	{
		put_button(data);
		data->obj_utils.signal = 2;
		event(data);
	}
	if (data->map[data->obj_utils.new_y[0]][data->obj_utils.new_x[1]] == 'C')
	{
		put_button(data);
		data->obj_utils.signal = 3;
		event(data);
	}
	if (data->map[data->obj_utils.new_y[1]][data->obj_utils.new_x[1]] == 'C')
	{
		put_button(data);
		data->obj_utils.signal = 4;
		event(data);
	}
}

void	get_item(t_data *data)
{
	data->obj_utils.new_x[0] = (int)ceilf(data->player.x / 64);
	data->obj_utils.new_y[0] = (int)ceilf(data->player.y / 64);
	data->obj_utils.new_x[1] = (int)data->player.x / 64;
	data->obj_utils.new_y[1] = (int)data->player.y / 64;
	get_item_nbr(data);
	collect_item(data);
}
