/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpendilh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 15:44:26 by mpendilh          #+#    #+#             */
/*   Updated: 2024/12/17 14:33:21 by mpendilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

static void	put_ground(t_data *data, int x, int y)
{
	mlx_put_image_to_window(data->window.mlx, data->window.win,
		data->ground.img, x * PIXEL - data->camera_x,
		y * PIXEL - data->camera_y);
}

static void	put_exit(t_data *data, int x, int y)
{
	if (!data->item_nbr)
		mlx_put_image_to_window(data->window.mlx, data->window.win,
			data->exit[data->exit[1].counter].img,
			x * PIXEL - data->camera_x, y * PIXEL - data->camera_y);
	else
		mlx_put_image_to_window(data->window.mlx, data->window.win,
			data->exit[data->exit[0].counter].img,
			x * PIXEL - data->camera_x, y * PIXEL - data->camera_y);
}

static void	put_collectible(t_data *data, int x, int y)
{
	if (!data->random)
		mlx_put_image_to_window(data->window.mlx, data->window.win,
			data->easter_egg[data->easter_egg[0].counter].img,
			x * PIXEL - data->camera_x, y * PIXEL - data->camera_y);
	if (x % 1 == 0 && data->random)
		mlx_put_image_to_window(data->window.mlx, data->window.win,
			data->item[RED][data->item[0][0].counter].img,
			x * PIXEL - data->camera_x, y * PIXEL - data->camera_y);
	if (x % 2 == 0 && data->random)
		mlx_put_image_to_window(data->window.mlx, data->window.win,
			data->item[PINK][data->item[0][0].counter].img,
			x * PIXEL - data->camera_x, y * PIXEL - data->camera_y);
	if (x % 3 == 0 && data->random)
		mlx_put_image_to_window(data->window.mlx, data->window.win,
			data->item[GREEN][data->item[0][0].counter].img,
			x * PIXEL - data->camera_x, y * PIXEL - data->camera_y);
	if (x % 4 == 0 && data->random)
		mlx_put_image_to_window(data->window.mlx, data->window.win,
			data->item[BLUE][data->item[0][0].counter].img,
			x * PIXEL - data->camera_x, y * PIXEL - data->camera_y);
	if (x % 5 == 0 && data->random)
		mlx_put_image_to_window(data->window.mlx, data->window.win,
			data->item[PURPLE][data->item[0][0].counter].img,
			x * PIXEL - data->camera_x, y * PIXEL - data->camera_y);
}

void	put_icon(t_data *data)
{
	if (!data->icon[0].is_attack && !data->icon[0].counter)
		mlx_put_image_to_window(data->window.mlx, data->window.win,
			data->icon[0].img, data->player.x - 32 - data->camera_x,
			0 - data->camera_y - 128);
	if (data->icon[0].counter)
	{
		count_frame_icon(data);
		mlx_put_image_to_window(data->window.mlx, data->window.win,
			data->icon[data->icon[0].counter].img,
			data->player.x - data->camera_x - 32,
			0 - data->camera_y - 128);
	}
	if (!data->water[0].is_attack)
		data->icon[0].is_attack = false;
}

void	put_image(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == '1')
				put_wall(data, j, i);
			if (data->map[i][j] == '0' || data->map[i][j] == 'P'
				|| data->map[i][j] == 'C' || data->map[i][j] == 'M')
				put_ground(data, j, i);
			if (data->map[i][j] == 'E')
				put_exit(data, j, i);
			if (data->map[i][j] == 'C')
				put_collectible(data, j, i);
			j++;
		}
		i++;
	}
}
