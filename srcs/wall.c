/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpendilh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 11:34:34 by mpendilh          #+#    #+#             */
/*   Updated: 2024/12/14 09:21:37 by mpendilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

static int	get_type(t_data *data, int x, int y)
{
	if (x < 0 || y < 0 || x > data->width - 1 || y > data->height - 1)
		return (1);
	return (data->map[y][x] == '1');
}

static int	get_adj_wall(t_data *data, int x, int y, int res[8])
{
	res[0] = get_type(data, x - 1, y - 1);
	res[1] = get_type(data, x, y - 1);
	res[2] = get_type(data, x + 1, y - 1);
	res[3] = get_type(data, x - 1, y);
	res[4] = get_type(data, x + 1, y);
	res[5] = get_type(data, x - 1, y + 1);
	res[6] = get_type(data, x, y + 1);
	res[7] = get_type(data, x + 1, y + 1);
	return (*res);
}

static void	wall(t_data *data, int x, int y, int res[8])
{
	if (res[4] && res[6] && !res[7] && res[2] && res[5])
		mlx_put_image_to_window(data->window.mlx, data->window.win,
			data->wall[NW].img, x * PIXEL - data->camera_x,
			y * PIXEL - data->camera_y);
	if (res[3] && res[6] && !res[5] && res[0] && res[7] && res[1])
		mlx_put_image_to_window(data->window.mlx, data->window.win,
			data->wall[NE].img, x * PIXEL - data->camera_x,
			y * PIXEL - data->camera_y);
	if (res[1] && res[4] && !res[2] && res[7] && res[0] && res[6])
		mlx_put_image_to_window(data->window.mlx, data->window.win,
			data->wall[SW].img, x * PIXEL - data->camera_x,
			y * PIXEL - data->camera_y);
	if (!res[0] && res[1] && res[3] && res[5] && res[2] && res[6])
		mlx_put_image_to_window(data->window.mlx, data->window.win,
			data->wall[SE].img, x * PIXEL - data->camera_x,
			y * PIXEL - data->camera_y);
}

static void	wall2(t_data *data, int x, int y, int res[8])
{
	if (!res[6] && res[1] && res[3] && res[4] && res[2] && res[0])
		mlx_put_image_to_window(data->window.mlx, data->window.win,
			data->wall[N].img, x * PIXEL - data->camera_x,
			y * PIXEL - data->camera_y);
	if (!res[4] && res[1] && res[6] && res[3] && res[0])
		mlx_put_image_to_window(data->window.mlx, data->window.win,
			data->wall[W].img, x * PIXEL - data->camera_x,
			y * PIXEL - data->camera_y);
	if (!res[3] && res[1] && res[6] && res[4] && res[7] && res[2])
		mlx_put_image_to_window(data->window.mlx, data->window.win,
			data->wall[E].img, x * PIXEL - data->camera_x,
			y * PIXEL - data->camera_y);
	if (!res[1] && res[3] && res[4] && res[6] && res[7] && res[5])
		mlx_put_image_to_window(data->window.mlx, data->window.win,
			data->wall[S].img, x * PIXEL - data->camera_x,
			y * PIXEL - data->camera_y);
	if (res[0] && res[1] && res[2] && res[3] && res[4]
		&& res[5] && res[6] && res[7])
		mlx_put_image_to_window(data->window.mlx, data->window.win,
			data->wall[CENTER].img, x * PIXEL - data->camera_x,
			y * PIXEL - data->camera_y);
}

void	put_wall(t_data *data, int x, int y)
{
	int	res[8];

	get_adj_wall(data, x, y, res);
	mlx_put_image_to_window(data->window.mlx, data->window.win,
		data->wall[STALAGMITE].img, x * PIXEL - data->camera_x,
		y * PIXEL - data->camera_y);
	wall(data, x, y, res);
	wall2(data, x, y, res);
	wall3(data, x, y, res);
	wall4(data, x, y, res);
}
