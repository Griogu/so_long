/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpendilh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 20:49:43 by mpendilh          #+#    #+#             */
/*   Updated: 2024/12/16 16:56:11 by mpendilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

static int	check_collision(t_data *data, int new_y[2], int new_x[2])
{
	if (data->player.speed_y < 0 && (data->map[new_y[0]][new_x[0]] == '1'
		|| data->map[new_y[1]][new_x[1]] == '1'
		|| data->map[new_y[0]][new_x[1]] == '1'
		|| data->map[new_y[1]][new_x[0]] == '1'))
		return (1);
	if (data->player.speed_x < 0 && (data->map[new_y[0]][new_x[0]] == '1'
		|| data->map[new_y[1]][new_x[1]] == '1'
		|| data->map[new_y[1]][new_x[0]] == '1'
		|| data->map[new_y[0]][new_x[1]] == '1'))
		return (1);
	if (data->player.speed_y > 0 && (data->map[new_y[0]][new_x[0]] == '1'
		|| data->map[new_y[1]][new_x[1]] == '1'
		|| data->map[new_y[0]][new_x[1]] == '1'
		|| data->map[new_y[1]][new_x[0]] == '1'))
		return (1);
	if (data->player.speed_x > 0 && (data->map[new_y[0]][new_x[0]] == '1'
		|| data->map[new_y[1]][new_x[1]] == '1'
		|| data->map[new_y[1]][new_x[0]] == '1'
		|| data->map[new_y[0]][new_x[1]] == '1'))
		return (1);
	return (0);
}

int	collision(t_data *data)
{
	int	new_x[2];
	int	new_y[2];

	new_x[0] = (int)((data->player.x + data->player.speed_x) / 64);
	new_x[1] = (int)ceilf((data->player.x + data->player.speed_x) / 64);
	new_y[0] = (int)((data->player.y + data->player.speed_y) / 64);
	new_y[1] = (int)ceilf((data->player.y + data->player.speed_y) / 64);
	if (check_collision(data, new_y, new_x))
	{
		if (data->player.speed_x < 0 || data->player.speed_y < 0)
		{
			data->player.x = (int)data->player.x;
			data->player.y = (int)data->player.y;
		}
		else if (data->player.speed_x > 0 || data->player.speed_y > 0)
		{
			data->player.x = (int)ceilf(data->player.x);
			data->player.y = (int)ceilf(data->player.y);
		}
		return (1);
	}
	return (0);
}

static int	check_collision2(t_data *data, int new_y[2], int new_x[2])
{
	if (data->map[new_y[0]][new_x[0]] == '1'
		|| data->map[new_y[1]][new_x[1]] == '1'
		|| data->map[new_y[0]][new_x[1]] == '1'
		|| data->map[new_y[1]][new_x[0]] == '1')
		return (1);
	return (0);
}

int	collision2(t_data *data, int i)
{
	int	new_x[2];
	int	new_y[2];

	new_x[0] = (int)((data->monster2[i].x
				+ data->monster2[i].speed_x) / 64);
	new_x[1] = (int)ceilf((data->monster2[i].x
				+ data->monster2[i].speed_x) / 64);
	new_y[0] = (int)((data->monster2[i].y
				+ data->monster2[i].speed_y) / 64);
	new_y[1] = (int)ceilf((data->monster2[i].y
				+ data->monster2[i].speed_y) / 64);
	if (check_collision2(data, new_y, new_x))
		return (1);
	return (0);
}
