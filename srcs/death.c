/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpendilh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 16:43:52 by mpendilh          #+#    #+#             */
/*   Updated: 2024/12/17 13:35:25 by mpendilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int	death(t_data *data, int i)
{
	int	new_x[2];
	int	new_y[2];

	new_x[0] = (int)(data->monster2[i].x / 64);
	new_x[1] = (int)ceilf((data->monster2[i].x / 64));
	new_y[0] = (int)(data->monster2[i].y / 64);
	new_y[1] = (int)ceilf((data->monster2[i].y / 64));
	if (((int)data->player.x / 64 == new_x[0]
			|| (int)data->player.x / 64 == new_x[1])
		&& ((int)data->player.y / 64 == new_y[0]
			|| (int)data->player.y / 64 == new_y[1]))
		return (1);
	return (0);
}

void	death_animation(t_data *data)
{
	count_frame_death(data);
	mlx_put_image_to_window(data->window.mlx, data->window.win,
		data->death[0].img, 0, 0);
	mlx_put_image_to_window(data->window.mlx, data->window.win,
		data->death[data->death[0].counter].img,
		data->player.x - data->camera_x,
		data->player.y - data->camera_y);
}
