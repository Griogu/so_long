/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   veldra.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpendilh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 12:17:00 by mpendilh          #+#    #+#             */
/*   Updated: 2024/12/14 13:08:42 by mpendilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	put_veldra(t_data *data)
{
	if (data->player.speed_x < 0)
	{
		veldra_frame2(data);
		mlx_put_image_to_window(data->window.mlx, data->window.win,
			data->veldra[data->veldra[1].counter].img,
			data->player.x + 64 - data->camera_x,
			data->player.y - data->camera_y);
	}
	else
	{
		veldra_frame(data);
		mlx_put_image_to_window(data->window.mlx, data->window.win,
			data->veldra[data->veldra[0].counter].img,
			data->player.x - 32 - data->camera_x,
			data->player.y - data->camera_y);
	}
}
