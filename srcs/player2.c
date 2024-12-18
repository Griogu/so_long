/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpendilh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 18:27:49 by mpendilh          #+#    #+#             */
/*   Updated: 2024/12/17 09:26:36 by mpendilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	water_attack(t_data *data)
{
	water_spell_frame(data);
	mlx_put_image_to_window(data->window.mlx, data->window.win,
		data->water[data->water[0].counter].img,
		data->player.x + 64 - data->camera_x,
		data->player.y - data->camera_y);
	data->player.speed_x = 0;
	data->player.speed_y = 0;
	data->icon[0].counter = 1;
}

void	fire_attack(t_data *data)
{
	fire_spell_frame(data);
	mlx_put_image_to_window(data->window.mlx, data->window.win,
		data->fire[data->fire[0].counter].img,
		data->player.x - 16 - data->camera_x, data->player.y - data->camera_y);
	data->player.speed_x = 0;
	data->player.speed_y = 0;
	data->icon2[0].counter = 1;
}
