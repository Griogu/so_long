/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpendilh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 03:41:51 by mpendilh          #+#    #+#             */
/*   Updated: 2024/12/17 14:58:33 by mpendilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	wall3(t_data *data, int x, int y, int res[8])
{
	if (res[1] && !res[2] && res[4] && !res[7] && res[6] && res[0])
		mlx_put_image_to_window(data->window.mlx, data->window.win,
			data->wall[W_2].img, x * PIXEL - data->camera_x,
			y * PIXEL - data->camera_y);
	if (res[0] && res[5] && !res[1] & !res[6] && res[3])
		mlx_put_image_to_window(data->window.mlx, data->window.win,
			data->wall[W_3].img, x * PIXEL - data->camera_x,
			y * PIXEL - data->camera_y);
	if (!res[0] && !res[5] && res[3] && res[1] && res[6])
		mlx_put_image_to_window(data->window.mlx, data->window.win,
			data->wall[E_2].img, x * PIXEL - data->camera_x,
			y * PIXEL - data->camera_y);
	if (res[2] && res[7] && !res[1] && !res[6])
		mlx_put_image_to_window(data->window.mlx, data->window.win,
			data->wall[E_3].img, x * PIXEL - data->camera_x,
			y * PIXEL - data->camera_y);
	if (res[1] && !res[6] && res[0] && !res[4])
		mlx_put_image_to_window(data->window.mlx, data->window.win,
			data->wall[NW_2].img, x * PIXEL - data->camera_x,
			y * PIXEL - data->camera_y);
	if (res[1] && res[4] && res[2] && !res[3] && !res[6])
		mlx_put_image_to_window(data->window.mlx, data->window.win,
			data->wall[NE_2].img, x * PIXEL - data->camera_x,
			y * PIXEL - data->camera_y);
}

void	wall4(t_data *data, int x, int y, int res[8])
{
	if (res[3] && res[6] && res[5] && !res[1] && !res[4])
		mlx_put_image_to_window(data->window.mlx, data->window.win,
			data->wall[SW_2].img, x * PIXEL - data->camera_x,
			y * PIXEL - data->camera_y);
	if (res[4] && res[6] && !res[3] && res[7] && !res[1])
		mlx_put_image_to_window(data->window.mlx, data->window.win,
			data->wall[SE_2].img, x * PIXEL - data->camera_x,
			y * PIXEL - data->camera_y);
}
