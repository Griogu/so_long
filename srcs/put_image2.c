/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpendilh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 09:00:52 by mpendilh          #+#    #+#             */
/*   Updated: 2024/12/17 09:20:36 by mpendilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	put_icons2(t_data *data)
{
	if (!data->icon2[0].is_attack && !data->icon2[0].counter)
		mlx_put_image_to_window(data->window.mlx, data->window.win,
			data->icon2[0].img, data->player.x + 32 - data->camera_x,
			0 - 128 - data->camera_y);
	if (data->icon2[0].counter)
	{
		put_icon(data);
		count_frame_icon2(data);
		mlx_put_image_to_window(data->window.mlx, data->window.win,
			data->icon2[data->icon2[0].counter].img,
			data->player.x + 32 - data->camera_x,
			0 - 128 - data->camera_y);
	}
	if (!data->fire[0].is_attack)
		data->icon2[0].is_attack = false;
}
